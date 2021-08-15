#include "STD_TYPES.h"
#include "avr/io.h"
#include "BIT_MATH.h"
#include"DIO_PRIV.h"
#include "DIO_CONFIG.h"
#include "DIO_INT.h"



void DIO_VoidInit (void)
{
	DDRA=CONCBIT(DIO_PIN_7_DIR,DIO_PIN_6_DIR,DIO_PIN_5_DIR,DIO_PIN_4_DIR,DIO_PIN_3_DIR,DIO_PIN_2_DIR,DIO_PIN_1_DIR,DIO_PIN_0_DIR);
    DDRB=CONCBIT(DIO_PIN_15_DIR,DIO_PIN_14_DIR,DIO_PIN_13_DIR,DIO_PIN_12_DIR,DIO_PIN_11_DIR,DIO_PIN_10_DIR,DIO_PIN_9_DIR,DIO_PIN_8_DIR);
    DDRC=CONCBIT(DIO_PIN_23_DIR,DIO_PIN_22_DIR,DIO_PIN_21_DIR,DIO_PIN_20_DIR,DIO_PIN_19_DIR,DIO_PIN_18_DIR,DIO_PIN_17_DIR,DIO_PIN_16_DIR);
    DDRD=CONCBIT(DIO_PIN_31_DIR,DIO_PIN_30_DIR,DIO_PIN_29_DIR,DIO_PIN_28_DIR,DIO_PIN_27_DIR,DIO_PIN_26_DIR,DIO_PIN_25_DIR,DIO_PIN_24_DIR);
}
void DIO_VoidSetPin (u8 PinNum, u8 Value)
{ if (PinNum<8 && PinNum>=0)
   {if (Value==High)
      {SETBIT(PORTA,PinNum);
      }
   else if (Value == Low)
      {
	   CLRBIT(PORTA,PinNum);
      }

   }
else if (PinNum<16 && PinNum>=8)
  {if (Value==High)
     {SETBIT(PORTB,PinNum-8);
     }
  else if (Value == Low)
     {
	   CLRBIT(PORTB,PinNum-8);
     }

  }
else if (PinNum<24 && PinNum>=16)
  {if (Value==High)
     {SETBIT(PORTC,PinNum-16);
     }
  else if (Value == Low)
     {
	   CLRBIT(PORTC,PinNum-16);
     }

  }
else if (PinNum<32 && PinNum>=24)
  {if (Value==High)
     {SETBIT(PORTD,PinNum-24);
     }
  else if (Value == Low)
     {
	   CLRBIT(PORTD,PinNum-24);
     }

  }
}
u8 DIO_U8GetPin (u8 PinNum)
{u8 PinValue ;
 if(PinNum<8 && PinNum>=0)
   { PinValue=GETBIT(PINA,PinNum);

   }
 else if(PinNum<16 && PinNum>=8)
    { PinValue=GETBIT(PINB,PinNum-8);

    }
 else if(PinNum<24 && PinNum>=16)
    { PinValue=GETBIT(PINC,PinNum-16);

    }
 else if(PinNum<32 && PinNum>=24)
    { PinValue=GETBIT(PIND,PinNum-24);

    }
 return PinValue ;
}
