/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : STD_TYPES Driver                                                                     */


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char           u8 ;
typedef unsigned short int     u16 ;
typedef unsigned long int      u32 ;
typedef unsigned long long int u64 ;
typedef signed char             s8 ;
typedef signed short int       s16 ;
typedef signed int             s32 ;
typedef signed long long       s64 ;
typedef float                  f32 ;
typedef double                 f64 ;
typedef long double            f96 ;


typedef enum{
	NOK=0,
	OK
}Error_State;

#define NULL 0
#define NULL_POINTER 1


#endif /* STD_TYPES_H_ */
