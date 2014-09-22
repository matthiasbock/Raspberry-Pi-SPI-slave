#include "gpio.h"

#define CS 8
#define SCK 11
#define MISO 9
#define MOSI 10

void SPI_INIT()
{
  GPIO_FSEL(CS, INPUT);
  GPIO_FSEL(SCK, INPUT);
  GPIO_FSEL(MOSI, INPUT);
  GPIO_FSEL(MISO, OUTPUT);
}

unsigned char SPI_SLAVE(unsigned char response)
{ 
  unsigned char val = 0;
  unsigned int bits = 8;
  unsigned int gpio_state;
  volatile unsigned int* input = (unsigned int *)0x20200034;
  
  do{ // to reduce latency access register directly instead of calling GPIO_GET
    gpio_state = *(input);
  } while( (gpio_state &= (1 << CS)) );         // wait for cable select to go low
  
  GPIO_SET(MISO, (response >> --bits) & 0x01);  // send first bit before clk starts
  
  do{ // to reduce latency access register directly instead of calling GPIO_GET
    gpio_state = *(input);
  } while( !(gpio_state &= (1 << SCK)) );       // wait for sclk to go high
  
  val |= (unsigned char)GPIO_GET(MOSI) << bits; // read in first bit MSB first

  wait(12);                                     // wait to switch until we are in the middle of the clk cycle
  
  do{
    GPIO_SET(MISO, (response >> --bits) & 0x01);  // send next bit MSB first
            
    val |= (unsigned char)GPIO_GET(MOSI) << bits; // read in first bit MSB first

    wait(69);                                     // delay for half a cycle
    
  }while(bits > 0);

  return val;
}
