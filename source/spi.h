#ifndef _SPI_H_
#define _SPI_H_

/**
 * Initializes SPI Pins
 *
 * SPI Configuration:
 *   clk - 122khz
 *   pol - clk is low when idle
 *   pha - data is sampled on rising clk edge
 */
void SPI_INIT();

/**
 * Performs a SPI SLAVE read & write by bit banging
 */
unsigned char SPI_SLAVE(unsigned char response);

#endif /* _SPI_H_ */
