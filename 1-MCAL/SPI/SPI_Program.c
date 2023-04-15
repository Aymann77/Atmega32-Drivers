/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL 		          ***************************/
/*************                SWC :     SPI	                  ***************************/
/*************                VERSION : 1.10		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#include "../../4-LIB/STD_TYPES.h"
#include "../../4-LIB/BIT_MATH.h"


#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"
#include "SPI_Register.h"

void SPI_voidInitMaster( void )
{

	/* SPI Peripheral Interrupt Enable */
#if   SPI_INTERRUPT ==   ENABLED
	SET_BIT( SPCR , SPCR_SPIE ) ;
#elif SPI_INTERRUPT ==   DISABLED
	CLEAR_BIT( SPCR , SPCR_SPIE ) ;
#endif

	/* Data Order Configuration */
#if   DATA_ORDER   ==   LSB_FIRST
	SET_BIT( SPCR , SPCR_DORD ) ;
#elif DATA_ORDER   ==   MSB_FIRST
	CLEAR_BIT( SPCR , SPCR_DORD ) ;
#endif

	/* Master Initialization */
	SET_BIT( SPCR , SPCR_MSTR ) ;

	/* Clock Polarity */
#if   CLOCK_POLARITY_MODE  ==  IDLE_HIGH
	SET_BIT( SPCR , SPCR_CPOL ) ;
#elif CLOCK_POLARITY_MODE  ==  IDLE_LOW
	CLEAR_BIT( SPCR , SPCR_CPOL ) ;
#endif

	/* Clock Phase */
#if   CLOCK_PHASE_MODE  ==  SETUP_FIRST
	SET_BIT( SPCR , SPCR_CPHA ) ;
#elif CLOCK_PHASE_MODE  ==  SAMPLE_FIRST
	CLEAR_BIT( SPCR , SPCR_CPHA ) ;
#endif

	/* Clock Rate Select */
#if ( CLOCK_RATE_SELECT >= FREQ_DIVIDE_BY_4 )  &&  ( CLOCK_RATE_SELECT <= FREQ_DIVIDE_BY_128 )

	/* Clear Double Speed Bit */
	CLEAR_BIT( SPSR , SPSR_SPI2X ) ;
	/* Bit Masking Clock Select */
	SPCR &= ( CLOCK_MASK ) ;
	SPCR |= ( CLOCK_RATE_SELECT ) ;

#elif ( CLOCK_RATE_SELECT > FREQ_DIVIDE_BY_128 )

	/* Set Double Speed Bit */
	SET_BIT( SPSR , SPSR_SPI2X ) ;
	/* Bit Masking Clock Select */
	SPCR &= ( CLOCK_MASK ) ;
	SPCR |= ( CLOCK_RATE_SELECT - 4 ) ;
#endif

	/* Enable SPI */
	SET_BIT( SPCR , SPCR_SPE ) ;

}


void SPI_voidInitSlave( void )
{

	/* SPI Peripheral Interrupt Enable */
#if   SPI_INTERRUPT ==   ENABLED
	SET_BIT( SPCR , SPCR_SPIE ) ;
#elif SPI_INTERRUPT ==   DISABLED
	CLEAR_BIT( SPCR , SPCR_SPIE ) ;
#endif

	/* Data Order Configuration */
#if   DATA_ORDER   ==   LSB_FIRST
	SET_BIT( SPCR , SPCR_DORD ) ;
#elif DATA_ORDER   ==   MSB_FIRST
	CLEAR_BIT( SPCR , SPCR_DORD ) ;
#endif

	/* Slave Initialization */
	CLEAR_BIT( SPCR , SPCR_MSTR ) ;

	/* Clock Polarity */
#if   CLOCK_POLARITY_MODE  ==  IDLE_HIGH
	SET_BIT( SPCR , SPCR_CPOL ) ;
#elif CLOCK_POLARITY_MODE  ==  IDLE_LOW
	CLEAR_BIT( SPCR , SPCR_CPOL ) ;
#endif

	/* Clock Phase */
#if   CLOCK_PHASE_MODE  ==  SETUP_FIRST
	SET_BIT( SPCR , SPCR_CPHA ) ;
#elif CLOCK_PHASE_MODE  ==  SAMPLE_FIRST
	CLEAR_BIT( SPCR , SPCR_CPHA ) ;
#endif

	/* Enable SPI */
	SET_BIT( SPCR , SPCR_SPE ) ;

}


u8 SPI_u8Transceive( u8 Copy_u8Data )
{
	/* Start Data Transfer */
	SPDR = Copy_u8Data ;

	/* Wait ( Busy Waiting ) Until Data Transfer is Complete */
	while( GET_BIT( SPSR , SPSR_SPIF ) == 0 ) ;

	/* Get The Exchanged Data  */
	return SPDR ;

}
