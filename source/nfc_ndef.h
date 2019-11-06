#include <stdint.h>

#ifndef _NFC_NDEF_H_
#define _NFC_NDEF_H_

typedef struct __attribute__((__packed__))
{
	uint8_t tlv[4];
	uint8_t msg_type;
	uint8_t len;
	uint8_t header;
	uint8_t type_len;
	uint8_t payload_len;
	uint8_t type;
}ndef_msg_head_t;

typedef struct __attribute__((__packed__))
{
	uint8_t status;
	uint16_t lang;
}ndef_msg_head_rtd_text_t;

typedef struct __attribute__((__packed__))
{
	uint8_t type;
}ndef_msg_head_rtd_uri_t;

typedef struct __attribute__((__packed__))
{
	ndef_msg_head_t 			head;
	ndef_msg_head_rtd_text_t 	head_rtd;
}ndef_msg_rtd_text_t;

typedef struct __attribute__((__packed__))
{
	ndef_msg_head_t 			head;
	ndef_msg_head_rtd_uri_t 	head_rtd;
}ndef_msg_rtd_uri_t;

void ndef_msg_rtd_text(uint8_t * payload, uint8_t payload_len, uint8_t * msg, uint8_t * msg_len);
void ndef_msg_rtd_uri(uint8_t * payload, uint8_t payload_len, uint8_t * msg, uint8_t * msg_len);

#endif
