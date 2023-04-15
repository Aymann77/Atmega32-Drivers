/****************************************************************************************/
/****************************************************************************************/
/*************                AUTHOR :  MOHAMMED AYMAN        ***************************/
/*************                LAYER :   MCAL			      ***************************/
/*************                SWC :     ADC 		          ***************************/
/*************                VERSION : 1.00		          ***************************/
/*************                DATE : 12-10-2022		          ***************************/
/****************************************************************************************/
/****************************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef struct
{
	u8 * Channel ;
	u16 * Result ;
	u8 ChainSize ;
	void (*NotificationFunc)(void) ;
}Chain_t;

/*ADC ANALOG CHANNEL AND GAIN OPTIONS*/
#define ADC_SINGLE_ENDED_ADC0   					0
#define ADC_SINGLE_ENDED_ADC1   					1
#define ADC_SINGLE_ENDED_ADC2   					2
#define ADC_SINGLE_ENDED_ADC3						3
#define ADC_SINGLE_ENDED_ADC4						4
#define ADC_SINGLE_ENDED_ADC5	 					5
#define ADC_SINGLE_ENDED_ADC6						6
#define ADC_SINGLE_ENDED_ADC7	  					7
#define ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC0_10X    8
#define ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC0_10X    9
#define ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC0_200X   10
#define ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC0_200X   11
#define ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC2_10X    12
#define ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC2_10X    13
#define ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC2_200X   14
#define ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC2_200X   15
#define ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC1_1X     16
#define ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC1_1X     17
#define ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC1_1X     18
#define ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC1_1X     19
#define ADC_DIFF_POSTIVE_ADC4__NEGATIVE_ADC1_1X     20
#define ADC_DIFF_POSTIVE_ADC5__NEGATIVE_ADC1_1X     21
#define ADC_DIFF_POSTIVE_ADC6__NEGATIVE_ADC1_1X     22
#define ADC_DIFF_POSTIVE_ADC7__NEGATIVE_ADC1_1X     23
#define ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC2_1X     24
#define ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC2_1X     25
#define ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC2_1X     26
#define ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC2_1X     27
#define ADC_DIFF_POSTIVE_ADC4__NEGATIVE_ADC2_1X     28
#define ADC_DIFF_POSTIVE_ADC5__NEGATIVE_ADC2_1X     29
#define ADC_SINGLE_ENDED_1_22V                      30
#define ADC_SINGLE_ENDED_0V                         31


/*---------------------------------------------------------------------------------
 *
 *     NAME     : ADC_voidInit
 *     FUNCTION : INTIALIZATION ADC USING PRE-BUILD CONFIGURATIONS IN CONFIG FILE
 *     ARGUMENT : VOID
 *     RETURN   : VOID
 *
 *---------------------------------------------------------------------------------*/
void ADC_voidInit(void) ;


/*
 * USE IT IN SINGLE CONVERSION MODE ONLY
 */
/*---------------------------------------------------------------------------------
 *
 *     NAME     : ADC_u8StartConversionSynch
 *     FUNCTION : START CONVERSION USING SYNCHROUNUS FUNCTION ( WAITING UNTIL CONVERSION COMPLETE )
 *     ARGUMENT : Copy_u8Channel : 1-  ADC_SINGLE_ENDED_ADC0  2- ADC_SINGLE_ENDED_ADC1    ,   Copy_pu16Reading -> Pointer to u 16 to Store ADC Reading
 *                                 3-  ADC_SINGLE_ENDED_ADC2  4- ADC_SINGLE_ENDED_ADC3
 *                                 5-  ADC_SINGLE_ENDED_ADC4  6- ADC_SINGLE_ENDED_ADC5
 *                                 7-  ADC_SINGLE_ENDED_ADC6  8- ADC_SINGLE_ENDED_ADC7
 *
 *                                 9-  ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC0_10X
 *                                 10- ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC0_10X
 *                                 11- ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC0_200X
 *                                 12- ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC0_200X
 *                                 13- ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC2_10X
 *                                 14- ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC2_10X
 *                                 15- ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC2_200X
 *                                 16- ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC2_200X
 *                                 17- ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC1_1X
 *                                 18- ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC1_1X
 *                                 19- ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC1_1X
 *                                 20- ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC1_1X
 *                                 21- ADC_DIFF_POSTIVE_ADC4__NEGATIVE_ADC1_1X
 *                                 22- ADC_DIFF_POSTIVE_ADC5__NEGATIVE_ADC1_1X
 *                                 23- ADC_DIFF_POSTIVE_ADC6__NEGATIVE_ADC1_1X
 *                                 24- ADC_DIFF_POSTIVE_ADC7__NEGATIVE_ADC1_1X
 *                                 25- ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC2_1X
 *                                 26- ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC2_1X
 *                                 27- ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC2_1X
 *                                 28- ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC2_1X
 *                                 29- ADC_DIFF_POSTIVE_ADC4__NEGATIVE_ADC2_1X
 *                                 30- ADC_DIFF_POSTIVE_ADC5__NEGATIVE_ADC2_1X
 *            					   31- ADC_SINGLE_ENDED_1_22V
 *                                 32- ADC_SINGLE_ENDED_0V
 *
 *      RETURN   : u8 ErrorState if Function Worked Correctly returns <OK>
 *                  else it Returns <NULL_POINTER>
 *---------------------------------------------------------------------------------*/
u8 ADC_u8StartConversionSynch( u8 Copy_u8Channel , u16* Copy_pu16Reading ) ;




/*
 * USE IT WITH SINGLE CONVERSION MODE
 * USE IT WITH FREE RUNING MODE OR ANY TRIGGER SOURCE <---CALL IT ONLY ONCE--->
 */
/*---------------------------------------------------------------------------------
 *
 *     NAME     : ADC_u8StartConversionAsynch
 *     FUNCTION : START CONVERSION USING SYNCHROUNUS FUNCTION ( WAITING UNTIL CONVERSION COMPLETE )
 *     ARGUMENT : Copy_u8Channel : 1-  ADC_SINGLE_ENDED_ADC0  2- ADC_SINGLE_ENDED_ADC1    ,   Copy_pu16Reading -> Pointer to u 16 to Store ADC Reading
 *                                 3-  ADC_SINGLE_ENDED_ADC2  4- ADC_SINGLE_ENDED_ADC3    ,   Copy_pvNotificationFunc -> Notification Function to be executed
 *                                 5-  ADC_SINGLE_ENDED_ADC4  6- ADC_SINGLE_ENDED_ADC5                    when Conversion Completes
 *                                 7-  ADC_SINGLE_ENDED_ADC6  8- ADC_SINGLE_ENDED_ADC7
 *
 *                                 9-  ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC0_10X
 *                                 10- ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC0_10X
 *                                 11- ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC0_200X
 *                                 12- ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC0_200X
 *                                 13- ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC2_10X
 *                                 14- ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC2_10X
 *                                 15- ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC2_200X
 *                                 16- ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC2_200X
 *                                 17- ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC1_1X
 *                                 18- ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC1_1X
 *                                 19- ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC1_1X
 *                                 20- ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC1_1X
 *                                 21- ADC_DIFF_POSTIVE_ADC4__NEGATIVE_ADC1_1X
 *                                 22- ADC_DIFF_POSTIVE_ADC5__NEGATIVE_ADC1_1X
 *                                 23- ADC_DIFF_POSTIVE_ADC6__NEGATIVE_ADC1_1X
 *                                 24- ADC_DIFF_POSTIVE_ADC7__NEGATIVE_ADC1_1X
 *                                 25- ADC_DIFF_POSTIVE_ADC0__NEGATIVE_ADC2_1X
 *                                 26- ADC_DIFF_POSTIVE_ADC1__NEGATIVE_ADC2_1X
 *                                 27- ADC_DIFF_POSTIVE_ADC2__NEGATIVE_ADC2_1X
 *                                 28- ADC_DIFF_POSTIVE_ADC3__NEGATIVE_ADC2_1X
 *                                 29- ADC_DIFF_POSTIVE_ADC4__NEGATIVE_ADC2_1X
 *                                 30- ADC_DIFF_POSTIVE_ADC5__NEGATIVE_ADC2_1X
 *            					   31- ADC_SINGLE_ENDED_1_22V
 *                                 32- ADC_SINGLE_ENDED_0V
 *
 *      RETURN   : u8 ErrorState if Function Worked Correctly returns <OK>
 *                  else if pointer to store reading is NULL it Returns <NULL_POINTER>
 *                  else Conversion is not completed Function Returns <BUSY_FUNC>
 *---------------------------------------------------------------------------------*/
u8 ADC_u8StartConversionAsynch( u8 Copy_u8Channel , u16*Copy_pu16Reading ,  void(*Copy_pvNotificationFunc)(void) ) ;

/*
 * NOTE: Function Will Not Work Correctly if GIE is disabled
 *        make sure to enable it before Calling Function*/
/*---------------------------------------------------------------------------------
 *
 *     NAME     : ADC_u8StartChainAsynch
 *     FUNCTION : START CHAIN OF CONVERSIONS ON ADC WITH ASYNCHRONOUS WAY
 *     ARGUMENT : Pointer to Struct ( Chain_t )
 *                   Struct Elements :
 *                   {
 *                     u8 * Channel;
                       u16* Result ;
                       u8   ChainSize ;
                       void (*NotificationFunc)(void);
 *                   }
 *     RETURN   : u8 Error state if Function Worked Correctly Returns ->  OK
 *                 else if pointer to struct is NULL returns -> NULL_POINTER
 *                 else ADC is Busy Doing Conversion returen -> BUSY_FUNC
 *---------------------------------------------------------------------------------*/
u8 ADC_u8StartChainAsynch( Chain_t * Copy_Chain ) ;


#endif /* 1_MCAL_ADC_ADC_INTERFACE_H_ */
