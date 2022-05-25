/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : BITMATH Driver                                                                     */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define GET_BIT(VAR,BIT_NUM)            ((VAR>>BIT_NUM)&1)
#define CLR_BIT(VAR,BIT_NUM)            VAR &= ~(1<<BIT_NUM)
#define SET_BIT(VAR,BIT_NUM)            VAR |= (1<<BIT_NUM)
#define TOGGLE_BIT(VAR,BIT_NUM)         VAR ^= (1<<BIT_NUM)
#define ASSIGN_BIT(VAR,BIT,VAL)         (VAL==1)?(SET_BIT(VAR,BIT)):(CLR_BIT(VAR,BIT))

/**
 #define  SET_HIGH_NIBBLE(VAR)
 #define  SET_LOW_NIBBLE(VAR)
 #define  CLR_HIGH_NIBBLE(VAR)
 #define  CLR_LOW_NIBBLE(VAR)
 */

                                         /**BOOL**/

#define TRUE      1
#define FALSE     0

#define HIGH     ~0

#define LOW       0
#define OUTPUT   ~0
#define INPUT     0


                                         /**LOOPS**/

#define FOREVER   for(;;)
#endif /* BIT_MATH_H_ */
