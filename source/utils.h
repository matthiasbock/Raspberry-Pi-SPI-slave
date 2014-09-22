#ifndef _UTILS_H_
#define _UTILS_H_

/**
 * Waits the specified number of microseconds
 *
 * NOTE: this is not extremely reliable although it is close
 */
void wait_us(unsigned int us);

/**
 * Waits the specified number of milliseconds
 */
void wait_ms(unsigned int ms);

#endif /* _UTILS_H_ */
