#include "nfc_ndef.h"
#include "string.h"

#define NDEF_TLV                    0xFD
#define NDEF_TLV_BLOCK_NDEFMSG      0x03
#define NDEF_TLV_TERMINATOR         0xFE

// Type Name Format
#define NDEF_HEADER_TNF_MASK        0b00000111
// NFC Forum well-known type [NFC RTD]
#define NDEF_HEADER_TNF_WELLKNOWN   0x01
// Media-type as defined in RFC 2046 [RFC 2046]
#define NDEF_HEADER_TNF_MEDIA       0x02
// Absolute URI as defined in RFC 3986 [RFC 3986]
#define NDEF_HEADER_TNF_ABSURI      0x03
// The IL flag indicates if the ID Length Field is preent or not. If this is set to 0, then the ID Length Field is ommitted in the record.
#define NDEF_HEADER_IL_MASK         0b00001000
// The SR flag is set to one if the PAYLOAD LENGTH field is 1 byte (8 bits/0-255) or less. This allows for more compact records.
#define NDEF_HEADER_SR_MASK         0b00010000
// The CF flag indicates if this is the first record chunk or a middle record chunk.
#define NDEF_HEADER_CF_MASK         0b00100000
// The ME flag indicates if this is the last record in the message.
#define NDEF_HEADER_ME_MASK         0b01000000
// The MB flag indicates if this is the start of an NDEF message.
#define NDEF_HEADER_MB_MASK         0b10000000

// NFC Forum Text RTD
#define NDEF_TYPE_TEXT  'T'
// NFC Forum URI RTD
#define NDEF_TYPE_URI   'U'
// NFC Forum Smart Poster RTD
#define NDEF_TYPE_SP    'SP'
// NFC Forum Device Information RTD
#define NDEF_TYPE_DI    'Di'
// NFC Forum Signature RTD
#define NDEF_TYPE_SIG   'Sig'

// Text RTD Status Byte
// Text encoding
#define NDEF_TYPE_TEXT_STAT_UTF_MASK        0b01000000
#define NDEF_TYPE_TEXT_STAT_UTF8            0x00
#define NDEF_TYPE_TEXT_STAT_UTF16           0x01
// RFU (MUST be set to zero)
#define NDEF_TYPE_TEXT_STAT_RFU_MASK        0b00100000
#define NDEF_TYPE_TEXT_STAT_RFU             0x00
// The length of the IANA language code.
#define NDEF_TYPE_TEXT_STAT_LANG_LEN_MASK   0b00011111
// IANA language codes
#define NDEF_TYPE_TEXT_STAT_LANG_EN         ( (uint16_t)('e') | ((uint16_t)('n') << 8) )
#define NDEF_TYPE_TEXT_STAT_LANG_SP         ( (uint16_t)('s') | ((uint16_t)('p') << 8) )
#define NDEF_TYPE_TEXT_STAT_LANG_FR         ( (uint16_t)('f') | ((uint16_t)('r') << 8) )
#define NDEF_TYPE_TEXT_STAT_LANG_DE         ( (uint16_t)('d') | ((uint16_t)('e') << 8) )

// URI RTD Types
#define NDEF_TYPE_URI_NONE          0x00
#define NDEF_TYPE_URI_HTTPWWW       0x01
#define NDEF_TYPE_URI_HTTPSWWW      0x02
#define NDEF_TYPE_URI_HTTP          0x03
#define NDEF_TYPE_URI_HTTPS         0x04
#define NDEF_TYPE_URI_TEL           0x05
#define NDEF_TYPE_URI_MAILTO        0x06


// Generates NDEF RTD TEXT message, assuming English language
// payload - pointer to uint8_t array or char string with the text
// payload_len - length of the payload pointer
// msg - pointer to the target buffer for storing the NDEF message
// msg_len - pointer to the msg length buffer
void ndef_msg_rtd_text(uint8_t * payload, uint8_t payload_len, uint8_t * msg, uint8_t * msg_len)
{
    ndef_msg_rtd_text_t * msg_head = (ndef_msg_rtd_text_t*)msg;
    uint8_t * msg_payload = (uint8_t*)msg_head + (uint8_t)sizeof(ndef_msg_rtd_text_t);
    uint8_t * msg_end = msg_payload + payload_len;

    *msg_len = msg_end - (uint8_t*)msg_head + 1;

    // Padding to 32 bits
    if (*msg_len % sizeof(uint32_t) != 0) *msg_len += sizeof(uint32_t) - *msg_len % sizeof(uint32_t);

    msg_head->head.tlv[0] = NDEF_TLV;
    msg_head->head.tlv[1] = 0x02;
    msg_head->head.tlv[2] = 0x00;
    msg_head->head.tlv[3] = 0x00;
    msg_head->head.msg_type = NDEF_TLV_BLOCK_NDEFMSG;

    msg_head->head.len =    sizeof(msg_head->head.header) +
                            sizeof(msg_head->head.type_len) +
                            sizeof(msg_head->head.payload_len) +
                            sizeof(msg_head->head.type) +
                            sizeof(msg_head->head_rtd) +
                            payload_len;

    msg_head->head.header = (NDEF_HEADER_TNF_WELLKNOWN & NDEF_HEADER_TNF_MASK) |
                            (0x00 & NDEF_HEADER_IL_MASK) |
                            NDEF_HEADER_SR_MASK |
                            (0x00 & NDEF_HEADER_CF_MASK) |
                            NDEF_HEADER_ME_MASK |
                            NDEF_HEADER_MB_MASK;

    msg_head->head.type_len = 0x01;
    msg_head->head.payload_len = payload_len + sizeof(msg_head->head_rtd);
    msg_head->head.type = NDEF_TYPE_TEXT;

    msg_head->head_rtd.status = (NDEF_TYPE_TEXT_STAT_UTF_MASK & NDEF_TYPE_TEXT_STAT_UTF8) |
                                (NDEF_TYPE_TEXT_STAT_RFU_MASK & NDEF_TYPE_TEXT_STAT_RFU)  |
                                (NDEF_TYPE_TEXT_STAT_LANG_LEN_MASK & sizeof(msg_head->head_rtd.lang));

    msg_head->head_rtd.lang = (uint16_t)NDEF_TYPE_TEXT_STAT_LANG_EN;

    memcpy(msg_payload, payload, payload_len);

    *msg_end = NDEF_TLV_TERMINATOR;
}

// Generates NDEF RTD URI message, assuming HTTPS
// payload - pointer to uint8_t array or char string with the URI
// payload_len - length of the payload pointer
// msg - pointer to the target buffer for storing the NDEF message
// msg_len - pointer to the msg length buffer
void ndef_msg_rtd_uri(uint8_t * payload, uint8_t payload_len, uint8_t * msg, uint8_t * msg_len)
{
    ndef_msg_rtd_uri_t * msg_head = (ndef_msg_rtd_uri_t*)msg;
    uint8_t * msg_payload = (uint8_t*)msg_head + (uint8_t)sizeof(ndef_msg_rtd_uri_t);
    uint8_t * msg_end = msg_payload + payload_len;

    *msg_len = msg_end - (uint8_t*)msg_head + 1;

    // Padding to 32 bits
    if (*msg_len % sizeof(uint32_t) != 0) *msg_len += sizeof(uint32_t) - *msg_len % sizeof(uint32_t);

    msg_head->head.tlv[0] = NDEF_TLV;
    msg_head->head.tlv[1] = 0x02;
    msg_head->head.tlv[2] = 0x00;
    msg_head->head.tlv[3] = 0x00;
    msg_head->head.msg_type = NDEF_TLV_BLOCK_NDEFMSG;

    msg_head->head.len =    sizeof(msg_head->head.header) +
                            sizeof(msg_head->head.type_len) +
                            sizeof(msg_head->head.payload_len) +
                            sizeof(msg_head->head.type) +
                            sizeof(msg_head->head_rtd) +
                            payload_len;

    msg_head->head.header = (NDEF_HEADER_TNF_WELLKNOWN & NDEF_HEADER_TNF_MASK) |
                            (0x00 & NDEF_HEADER_IL_MASK) |
                            NDEF_HEADER_SR_MASK |
                            (0x00 & NDEF_HEADER_CF_MASK) |
                            NDEF_HEADER_ME_MASK |
                            NDEF_HEADER_MB_MASK;

    msg_head->head.type_len = 0x01;
    msg_head->head.payload_len = payload_len + sizeof(msg_head->head_rtd);
    msg_head->head.type = NDEF_TYPE_URI;

    msg_head->head_rtd.type = NDEF_TYPE_URI_HTTPS;

    memcpy(msg_payload, payload, payload_len);

    *msg_end = NDEF_TLV_TERMINATOR;
}
