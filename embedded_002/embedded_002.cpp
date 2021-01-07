#include "gpio.h"
#include <stdio.h>
#include "hw_types.h"

/*Algorithm to understand how to initialize gpio ports*/

gpio_error_t gpio_pin_init(uint8_t base_addr, uint8_t pin_num, gpio_dir_t dir);
gpio_error_t gpio_pin_read(uint8_t base_addr, uint8_t pin_num);

int main(){

    printf("Call to the function /n");

    /*Use the functions */
    gpio_pin_init(BASE_A,3, DIR_OUTPUT);
    
    gpio_pin_read(BASE_B, 3);
    return 0;
}


gpio_error_t gpio_pin_init(uint8_t base_addr, uint8_t pin_num, gpio_dir_t dir) {
    
    gpio_error_t state = STATE_SUCESS;

    if (base_addr == BASE_A || base_addr == BASE_B || base_addr == BASE_C || base_addr == BASE_D){

        if (pin_num < 8) {
            if(dir==DIR_OUTPUT){
                //hw_bit_write(base_addr, pin_num, HIGH); /*need to an addrs*/
                modifyBits(base_addr, pin_num, HIGH);
            }
        }

        else {
          state = STATE_INVALID_ADDR;
        }
    }

    return state;
}



gpio_error_t gpio_pin_read(uint8_t base_addr, uint8_t pin_num) {

    gpio_error_t state = STATE_SUCESS;

    int *result = 0 ;

    if (base_addr == BASE_A || base_addr == BASE_B || base_addr == BASE_C || base_addr == BASE_D) {
        if (pin_num < 8 ) {
            *result = hw_bit_read(base_addr+OFFSET_PIN );
        }
    }
    else {
        state = STATE_INVALID_PIN;
    }

    return state;
}
