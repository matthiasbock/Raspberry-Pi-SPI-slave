#ifndef _GPIO_H_
#define _GPIO_H_

typedef enum{
  LOW = 0,
  HIGH = 1
} LEVEL;

typedef enum{
  INPUT = 0,
  OUTPUT = 1,
  ALT0 = 2,
  ALT1 = 3,
  ALT2 = 4,
  ALT3 = 5,
  ALT4 = 6,
  ALT5 = 7
} FSEL;

/**
 * Sets the corresponding GPIO pin to the LEVEL passed in
 */
void GPIO_SET(unsigned int pin, LEVEL lvl);

/**
 * Gets the current LEVEL of the GPIO pin
 */
LEVEL GPIO_GET(unsigned int pin);

/**
 * Sets the function select for the corresponding GPIO pin
 */
void GPIO_FSEL(unsigned int pin, FSEL sel);

#endif /* _GPIO_H_ */
