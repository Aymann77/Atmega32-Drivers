/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     USART	              ***************************/
/*************                VERSION : 1.00		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/****************************************** SYNCHRONOUS ******************************************/

/*---------------------------------------------------------------------------------
 *
 *     NAME     : USART_voidInit
 *     FUNCTION : INTIALIZATION USART WITH PRE-BUILD CONFIGURATION IN CONFIG.h FILE
 *     ARGUMENT : VOID
 *     RETURN   : VOID
 *
 *---------------------------------------------------------------------------------*/
void USART_voidInit( void ) ;


/* NOTE :
 *       DATA MUST BE FROM 5 TO 9 BITS ONLY
 */
/*---------------------------------------------------------------------------------
 *
 *     NAME     : USART_voidSendCharSynch
 *     FUNCTION : SEND DATA VIA USART
 *     ARGUMENT : DATA TO BE SENT U16
 *     RETURN   : U8 ERROR STATUS
 *
 *---------------------------------------------------------------------------------*/
u8 USART_voidSendCharSynch( u16 Copy_u16Data ) ;



/*---------------------------------------------------------------------------------
 *
 *     NAME     : USART_u8RecieveCharSynch
 *     FUNCTION : RECIEVE DATA VIA USART
 *     ARGUMENT : VOID
 *     RETURN   : U16 RECEIVED DATA
 *
 *---------------------------------------------------------------------------------*/
u16 USART_u8RecieveCharSynch( void ) ;



/*---------------------------------------------------------------------------------
 *
 *     NAME     : USART_voidSendStringSynch
 *     FUNCTION : SEND STRING VIA UART
 *     ARGUMENT : STRING OF WORDS WITH THE LAST CHARACTER ( '\0 ) NULL CHARACTER
 *     RETURN   : VOID
 *
 *---------------------------------------------------------------------------------*/
void USART_voidSendStringSynch( char * Copy_charString ) ;



/*---------------------------------------------------------------------------------------------------------------
 *
 *     NAME     : USART_voidRecieveBufferSynch
 *     FUNCTION : RECIEVE BUFFER VIA USART , BUFFER IS A STRING WITH NO NULL CHARACTER AT LAST
 *     ARGUMENT : POINTER WHICH RECEIVED DATA WILL BE WRITTEN TO , BUFFER SIZE( NUMBER OF CHARACTERS IN STRING )
 *     RETURN   : VOID
 *
 *---------------------------------------------------------------------------------------------------------------*/
void USART_voidRecieveBufferSynch( char * Copy_p8Buffer , u8 Copy_u8BufferSize ) ;



/****************************************** ASYNCHRONOUS ******************************************/

/*---------------------------------------------------------------------------------------------------------------
 *
 *     NAME     : USART_voidRecieveBufferASynch
 *     FUNCTION : RECIEVE BUFFER VIA USART , BUFFER IS A STRING WITH NO NULL CHARACTER AT LAST
 *     ARGUMENT : POINTER WHICH RECEIVED DATA WILL BE WRITTEN TO , BUFFER SIZE( NUMBER OF CHARACTERS IN STRING ),
 *                          NOTIFICATION TO FUNCTION
 *     RETURN   : ERROR STATUS
 *
 *---------------------------------------------------------------------------------------------------------------*/
u8 USART_voidRecieveBufferASynch( char * Copy_p8Buffer , u8 Copy_u8BufferSize , void( *Copy_pvNotificationFunc )(void) ) ;


#endif /* 1_MCAL_USART_USART_INTERFACE_H_ */
