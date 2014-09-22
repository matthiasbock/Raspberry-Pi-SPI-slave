#include "gpio.h"

void GPIO_FSEL(unsigned int pin, FSEL sel)
{
  volatile unsigned int* GPIO_BASE = (unsigned int *)0x20200000;
  unsigned int curState = 0;
  
  // get right address for pin
  if(pin >= 10)
    GPIO_BASE++;
  if(pin >= 20)
    GPIO_BASE++;
  if(pin >= 30)
    GPIO_BASE++;
  if(pin >= 40)
    GPIO_BASE++;
  if(pin >= 50)
    GPIO_BASE++;

  pin %= 10; // we can set 10 pins per register
  
  curState = *(GPIO_BASE);       // get GPIO reg state
  
  curState &= ~(7 << (pin * 3)); // clear bits in question
  curState |= sel << (pin * 3);  // set bits in question
  
  *(GPIO_BASE) = curState;       // right state back to GPIO reg
}

void GPIO_SET(unsigned int pin, LEVEL lvl)
{
  volatile unsigned int* GPIO_BASE = (unsigned int *)0x20200000;

  // determine which base address to use
  if(pin > 31)
    GPIO_BASE += 4;
  
  // determine whether we are setting or clearing
  if(lvl == HIGH)
    GPIO_BASE += 7;
  else
    GPIO_BASE += 10;

  pin %= 32; // we can set 32 pins per register
  
  *(GPIO_BASE) = 1 << pin;
}

LEVEL GPIO_GET(unsigned int pin)
{
  volatile unsigned int* GPIO_BASE = (unsigned int *)0x20200034;
  unsigned int val = 0;
  
  // determine which base address to use
  if(pin > 31)
    GPIO_BASE += 4;
  
  val = *(GPIO_BASE); // get all values

  pin %= 32; // we can get 32 pins per register
    
  val = (val >> pin) & 0x01; // isolate pin in quesetion

  if(val == 1)
    return HIGH;
  return LOW;
}

