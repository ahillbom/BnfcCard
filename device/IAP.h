#include <stdint.h>

/*

The IAP (In Application Programming) provides APIs to program a blank device. The APIs
can also erase and reprogram a previously programmed device, or program the flash
memory by the application program in a running system.

*/

#ifndef _IAP_H_
#define _IAP_H_

uint8_t IAP_getUID(uint32_t uid[]);

#endif
