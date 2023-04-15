/*
 * SSD_Private.h
 *
 *  Created on: Sep 6, 2022
 *      Author: moham
 */

#ifndef _SSD_PRIVATE_H_
#define _SSD_PRIVATE_H_

/*---------------------------------------------------------------------------------------*/

/*------------------------*/
/*   SSD NUMBER IN HEXA   */
/*------------------------*/


#if SSD_u8COM_TYPE == COM_CATHODE

#define ZERO  0x3F
#define ONE   0x06
#define TWO   0x5B
#define THREE 0x4F
#define FOUR  0x66
#define FIVE  0x6D
#define SIX   0x7D
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE  0x6F

#elif SSD_u8COM_TYPE == COM_ANODE

#define ZERO  ~(0x3F)
#define ONE   ~(0x06)
#define TWO   ~(0x5B)
#define THREE ~(0x4F)
#define FOUR  ~(0x66)
#define FIVE  ~(0x6D)
#define SIX   ~(0x7D)
#define SEVEN ~(0x07)
#define EIGHT ~(0x7F)
#define NINE  ~(0x6F)

#endif


/*---------------------------------------------------------------------------------------*/

#endif /* 2_HAL_SSD_SSD_PRIVATE_H_ */
