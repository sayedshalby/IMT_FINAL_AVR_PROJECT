 /******************************************************************************
 *
 * File Name: std_types.h
 *
 * Description: header file for data_types
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long  int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long  int s32;

typedef float  f32;
typedef double f64;
typedef unsigned long long u64;

#define NULL (void *)0

typedef enum
{
	R_NOK        ,
	R_OK         ,
	TIMER0_OK    ,
	TIMER0_NOK   ,
	TIMER2_OK    ,
	TIMER2_NOK   ,
	NULL_POINTER ,
	BUSY_FUNC	 ,
	DCMOTOR_OK	,
	DCMOTOR_NOK	,
	TIMER1_OK,
	TIMER1_NOK
}error_state_t;




#endif /* STD_TYPES_H_ */
