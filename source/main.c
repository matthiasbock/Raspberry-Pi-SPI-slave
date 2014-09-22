#include "gpio.h"
#include "spi.h"
#include "utils.h"

/**
 * Tests GPIO Input and Output by reading from the input pin
 * and echoing to the output pin
 */
void BLINK()
{
  GPIO_FSEL(0, INPUT);
  GPIO_FSEL(25, OUTPUT);

  while(1)
  {
    if(GPIO_GET(0) == HIGH)
      GPIO_SET(25, HIGH);
    else
      GPIO_SET(25, LOW);
  }  
}

/**
 * Tests SPI by echo what was read
 */
void SPI_TEST()
{
  volatile unsigned char val = 0;
  SPI_INIT();
  
  while(1)
  { 
    val = SPI_SLAVE(val);
  }
}

void main ()
{
  SPI_TEST();
}



  
