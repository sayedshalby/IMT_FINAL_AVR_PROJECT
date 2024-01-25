 /******************************************************************************
 *
 * File Name: bit_math.h
 *
 * Description: header file for control bits in register
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BitNo)              (REG) |= (1<<BitNo)
#define CLR_BIT(REG,BIT)               (REG&=(~(1<<BIT)))
#define ASS_BIT(REG,BitNo,VAL)          (VAL==0)? CLR_BIT(REG,BitNo) : SET_BIT(REG,BitNo)
#define TOG_BIT(REG,BitNo)              REG ^= (1<<BitNo)
#define GET_BIT(REG,BitNo)              ((REG>>BitNo) & 0x01)

#define SET_NIBBLE(REG,NibbleHalf)      (NibbleHalf == LOW)? (REG |= 00001111) : (REG |= 11110000)
#define CLR_NIBBLE(REG,NibbleHalf)      (NibbleHalf == LOW)? (REG &= 11110000) : (REG &= 00001111)
#define ASS_NIBBLE(REG,NibbleHalf,VAL)  (VAL == 0)? (CLR_NIBBLE(REG,NibbleHalf)) : (SET_NIBBLE(REG,NibbleHalf))
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

#endif /* BIT_MATH_H_ */
