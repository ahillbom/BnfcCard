#include "IAP.h"
#include <stdint.h>

#define IAP_LOCATION 		0x1fff1ff1

#define IAP_CMD_READ_UID 	0x3A

// Function type pointer, which takes two parameters and returns void. Note
// the IAP returns the result with the base address of the table residing in R1.
// args: command_param, status_result
typedef void (*IAP)(unsigned int [],unsigned int[]);

IAP iap_call = (IAP) IAP_LOCATION;

uint8_t IAP_getUID(uint32_t uid[])
{
    uint32_t status_result[5] = {0};
    uint32_t command_param = IAP_CMD_READ_UID;

    iap_call(&command_param, status_result);

    uid[0] = status_result[1];
    uid[1] = status_result[2];

    return status_result[0];
}
