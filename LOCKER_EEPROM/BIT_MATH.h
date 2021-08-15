/************************
 * Name: Mario Ramzy Ayoub
 * Date: 28/11/2017
 * This header file contains all macro functions 
 * for bit calculations in a variable 
 * (it is assumed to be 16 bit variable)
***************************************************/
#define SETBIT(num, bit) (num) |= (1<<bit)

#define CLRBIT(num, bit) (num) &= ~(1<<bit)

#define TOGGLEBIT(num, bit) (num) ^= (1<<bit)

#define GETBIT(num, bit) (((num)>>(bit)) & 0x01)		//((((num) & (1 << bit)) != 0) ? 1:0)

#define SETLOWNIB(num) (num) |= 15	//0b00001111

#define CLRLOWNIB(num) (num) &= ~15

#define TOGLOWNIB(num) (num) ^= 15

#define set_high_nib(num) (num) |= 240  //0b11110000

#define clr_high_nib(num) (num) &= ~240

#define toggle_high_nib(num) (num) ^= 240


#define CONCHELP(B7,B6,B5,B4,B3,B2,B1,B0)  0b##B7##B6##B5##B4##B3##B2##B1##B0
#define CONCBIT(B7,B6,B5,B4,B3,B2,B1,B0) CONCHELP(B7,B6,B5,B4,B3,B2,B1,B0)
