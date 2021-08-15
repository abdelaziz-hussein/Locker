#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INT.h"
#include "LED_PRIV.h"
#include "LED_CONFIG.h"
#include "LED_INT.h"
void LED_VoidInit (void)
{

}

void LED_VoidOn (u8 LedNum)
{ if (LedNum==LED_0)
	{if (LED_0_Mode==Forward)
		{
		DIO_VoidSetPin(LED_0_Pin,High);
		}
	else if (LED_0_Mode==Reverse)
	    {
		DIO_VoidSetPin(LED_0_Pin,Low);
	    }

	}
else if (LedNum==LED_1)
	{if (LED_1_Mode==Forward)
		{
		DIO_VoidSetPin(LED_1_Pin,High);
		}
	else if (LED_1_Mode==Reverse)
	    {
		DIO_VoidSetPin(LED_1_Pin,Low);
	    }

	}
else if (LedNum==LED_2)
	{if (LED_2_Mode==Forward)
		{
		DIO_VoidSetPin(LED_2_Pin,High);
		}
	else if (LED_2_Mode==Reverse)
	    {
		DIO_VoidSetPin(LED_2_Pin,Low);
	    }

	}

}
void LED_VoidOff (u8 LedNum)
{
	 if (LedNum==LED_0)
		{if (LED_0_Mode==Forward)
			{
			DIO_VoidSetPin(LED_0_Pin,Low);
			}
		else if (LED_0_Mode==Reverse)
		    {
			DIO_VoidSetPin(LED_0_Pin,High);
		    }

		}
	else if (LedNum==LED_1)
		{if (LED_1_Mode==Forward)
			{
			DIO_VoidSetPin(LED_1_Pin,Low);
			}
		else if (LED_1_Mode==Reverse)
		    {
			DIO_VoidSetPin(LED_1_Pin,High);
		    }

		}
	else if (LedNum==LED_2)
		{if (LED_2_Mode==Forward)
			{
			DIO_VoidSetPin(LED_2_Pin,Low);
			}
		else if (LED_2_Mode==Reverse)
		    {
			DIO_VoidSetPin(LED_2_Pin,High);
		    }

		}

}
