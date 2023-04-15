/*********************************************************************************************
****************************   Author : Mohammed Ayman       *********************************
****************************   Title :     STD_TYPES         *********************************
****************************   Date   : 24/4/2022            *********************************
****************************   Version->1   (24/4/2022)      *********************************
**********************************************************************************************/




/********************* Standard Types To USE *********************/

/****
***** u:unsigned
***** s:signed
***** f:floating numbers
                 *****/
				 
				 
#ifndef _STDTYPES_H_
#define _STDTYPES_H_


/********* 8Bits -> 1Byte *******/
/********* Numbers  OR Char*******/

typedef unsigned char u8;
typedef signed char s8;


/********* 16Bits -> 2Bytes*******/
/*********  Numbers S OR U *******/

typedef unsigned short int u16;
typedef signed short int s16;


/********* 32Bits -> 4Bytes *******/
/*********   Numbers S OR U *******/

typedef unsigned long int u32;
typedef signed long int s32;


/********* 64Bits -> 8Bytes *******/
/********* Numbers S OR U   *******/

typedef signed long long int s64;
typedef unsigned long long int u64;



/********* Floating Numbers *******/
typedef float f32;
typedef double f64;
typedef long double f128;



/*SOME VALUES*/
#define NULL            		0
#define NULL_CHARACTER 		   '\0'
#define OK              		0
#define NOK             		1
#define NULL_POINTER   		    2
#define BUSY_FUNC       		3
#define CONVERSION_NO_COMPLETE  4

#endif



