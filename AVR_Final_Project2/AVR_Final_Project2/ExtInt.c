/******************************************************************************
 *
 * Module: Interrupts
 *
 * File Name: ExtInt.c
 *
 * Description: header file for the ATmega32 INT driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Registers.h"
#include "Interrupts.h"
#include "ExtInt.h"

#define NULL_PTR ((void*)0)
void (*Callback_Int0) (void) = NULL_PTR;
void (*Callback_Int1) (void) = NULL_PTR;
void (*Callback_Int2) (void) = NULL_PTR;



ISR(VECTOR_INT0)
{
	if (NULL_PTR != Callback_Int0) {
        Callback_Int0();
    }
}

ISR(VECTOR_INT1)
{
	if (NULL_PTR != Callback_Int1) {
        Callback_Int1();
    }
}

ISR(VECTOR_INT2)
{
	if (NULL_PTR != Callback_Int2) {
        Callback_Int2();
    }
}

void EXTI_voidSetCallBack(ExtInt_ChannelType channel, void (*funcPtr) (void)) {
    switch (channel)
    {
    case EXTINT_CHANNEL_INT0:
        Callback_Int0 = funcPtr;
        break;
    case EXTINT_CHANNEL_INT1:
        Callback_Int1 = funcPtr;
        break;
    case EXTINT_CHANNEL_INT2:
        Callback_Int2 = funcPtr;
        break;
    default:
        break;
    }
}

void EXTI_voidEXTIEnable(ExtInt_ChannelType Copy_u8EXTINo, ExtInt_TriggerEdgeType Copy_u8EXTISense)
{
	switch (Copy_u8EXTINo)
	{
		case EXTINT_CHANNEL_INT0:
		{
			switch (Copy_u8EXTISense)
			{
				case EXTINT_TRIGGER_LOW_LEVEL:
				CLR_BIT(MCUCR, MCUCR_ISC00);
				CLR_BIT(MCUCR, MCUCR_ISC01);
				SET_BIT(GICR, GICR_INT0);

				break;
				case EXTINT_TRIGGER_ON_CHANGE:
				SET_BIT(MCUCR, MCUCR_ISC00);
				CLR_BIT(MCUCR, MCUCR_ISC01);
				SET_BIT(GICR, GICR_INT0);

				break;
				case EXTINT_TRIGGER_FALLING_EDGE:
				CLR_BIT(MCUCR, MCUCR_ISC00);
				SET_BIT(MCUCR, MCUCR_ISC01);
				SET_BIT(GICR, GICR_INT0);

				break;
				case EXTINT_TRIGGER_RISING_EDGE:
				SET_BIT(MCUCR, MCUCR_ISC00);
				SET_BIT(MCUCR, MCUCR_ISC01);
				SET_BIT(GICR, GICR_INT0);

				break;
				default:
				break;
			}
			break;
		}
		case EXTINT_CHANNEL_INT1:
		{
			switch (Copy_u8EXTISense)
			{
				case EXTINT_TRIGGER_LOW_LEVEL:
				CLR_BIT(MCUCR, MCUCR_ISC10);
				CLR_BIT(MCUCR, MCUCR_ISC11);
				SET_BIT(GICR, GICR_INT1);

				break;
				case EXTINT_TRIGGER_ON_CHANGE:
				SET_BIT(MCUCR, MCUCR_ISC10);
				CLR_BIT(MCUCR, MCUCR_ISC11);
				SET_BIT(GICR, GICR_INT1);

				break;
				case EXTINT_TRIGGER_FALLING_EDGE:
				CLR_BIT(MCUCR, MCUCR_ISC10);
				SET_BIT(MCUCR, MCUCR_ISC11);
				SET_BIT(GICR, GICR_INT1);

				break;
				case EXTINT_TRIGGER_RISING_EDGE:
				SET_BIT(MCUCR, MCUCR_ISC10);
				SET_BIT(MCUCR, MCUCR_ISC11);
				SET_BIT(GICR, GICR_INT1);

				break;
				default:
				break;
			}
			break;
		}
		case EXTINT_CHANNEL_INT2:
		{
			switch (Copy_u8EXTISense)
			{
				case EXTINT_TRIGGER_FALLING_EDGE:
				CLR_BIT(MCUCSR, MCUCSR_ISC2);
				SET_BIT(GICR, GICR_INT2);

				break;
				case EXTINT_TRIGGER_RISING_EDGE:
				SET_BIT(MCUCSR, MCUCSR_ISC2);
				SET_BIT(GICR, GICR_INT2);

				break;
				default:
				break;
			}
			break;
		}
		default:
		break;
	}
}

void  EXTI_voidEXTIDisable(ExtInt_ChannelType Copy_u8EXTINo) {
    switch (Copy_u8EXTINo)
    {
    case EXTINT_CHANNEL_INT0:
        CLR_BIT(GICR, GICR_INT0);
        break;
    case EXTINT_CHANNEL_INT1:
        CLR_BIT(GICR, GICR_INT1);
        break;
    case EXTINT_CHANNEL_INT2:
        CLR_BIT(GICR, GICR_INT2);
        break;
    default:
        break;
    }

}
