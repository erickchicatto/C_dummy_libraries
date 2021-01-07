#ifndef GPIO_H_
#define GPIO_H_

#include "hw_gpio.h"
#include "hw_types.h"

typedef enum gpio_error {
	STATE_SUCESS,
	STATE_ERROR,
	STATE_INVALID_ADDR,
	STATE_INVALID_PIN,
	STATE_INVALID_DIR,
	STATE_PULLUP_OFF
}gpio_error_t;


typedef enum gpio_dir {
	DIR_OUTPUT = 1,
	DIR_INPUT = 0 ,
	DIR_PULLUP_INPUT
}gpio_dir_t;

gpio_error_t gpio_pin_init(uint8_t base_addr, uint8_t pin_num, gpio_dir_t dir);

#endif //GPIO_H_
