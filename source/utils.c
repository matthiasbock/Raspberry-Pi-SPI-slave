#include "utils.h"

void wait_us(unsigned int val)
{
  volatile unsigned int us = val;
  while(us--)
    wait(9);
}

void wait_ms(unsigned int val)
{
  volatile unsigned int ms = val;
  while(ms--)
    wait(12500);
}
