#ifndef HW_TYPES_H_
#define HW_TYPES_H_

#include "types.h"
#include <stdint.h>

#define REG_ADDR  (*((volatile uint8_t*) reg_addr))

/*
static void hw_bit_write(uint8_t reg_addr,uint8_t bit_num, bit_t val) {
	REG_ADDR = val ? REG_ADDR |= (1<< val) : REG_ADDR & (~(1 << bit_num));
	//uint8_t aux = REG_ADDR |= (1 << 3);
	//uint8_t aux = REG_ADDR << 3;
}
*/
/*
* static  uint8_t hw_reg8_read(uint8_t reg_addr) {
	return REG_ADDR;
}
*/



/*https://c-for-dummies.com/blog/?p=1848 
	For understand a little bit coding basic bits 
*/

static int modifyBits(int n , int p , int b ){
	int mask = 1 << p;
	int aux_a = (n & ~mask);
	int aux_b = ((b << p) & mask);
	return (n & ~mask) | ((b<<p)& mask);
}



static int hw_bit_read(uint8_t reg_addr) {
	int aux  = reg_addr & (1 << 3); /*Debbug */
	return aux;
}



#endif //HW_TYPES_H_
