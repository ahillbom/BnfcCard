# What is this for?
A smart business card based on ARM Cortex M0 with integrated NFC. The business card is powered with the harvested energy from NFC communication. For the enthusiasts, JTAG and I2C interface is exposed in a breakout, which makes it possible to tinker and even use it as a development board.

It uses NXP LPC8N04, and features nine 0.4 mm slim orange LEDs for the light show and feedback. The MCU itself consumes only 900uA at 8MHz and 200uA at 1MHz. Given that NFC readers provide power continuously, there are many application that could be implemented on the business card. I haven't came up with anything fancy yet, except for hooking up I2C sensors, and using LEDs and time interval that card is held against the NFC reader to change the mode of operation. 

Follow the whole project on [hackaday.io](https://hackaday.io/project/168099-beast-nfc-business-card)

# NFC NDEF library

A small [library](/source/nfc_ndef.c) is capable of generating NFC NDEF Text and URI messages.

An example of how to generate NFC NDEF URI message:

```c
// URL to add to the NDEF message, 
// "https://" is included already as a prefix
uint8_t url[]= "example.com";
// Buffer for storing the generated message
uint8_t msg[80] = {0};
// Buffer for storing the length of the generated message
uint8_t msglen = 0;
// Generate the message
ndef_msg_rtd_text(url, sizeof(url), msg, &msglen);
```

# NFC URI with UID

NXP LPC8N04 has a unique 64-bit serial number which is possible to read through their IAP (In Application Programming) interface. A function for reading UID is implemented [here](/device/IAP.c).

The UID is dynamically added to the URL as a `id` parameter and copied to the NFC front-end buffer memory in (main.c)[/source/main.c]
This exmaple summarizes it:
```c
#define URL_BASE  "beastdevices.com/nfccodes/25YDZ2SCIP/?id="

typedef struct{
    uint8_t base[sizeof(URL_BASE)-1];
    uint8_t id[16];
}url_t;

// Get MCU's serial number
IAP_getUID(uid);

// Prepare NDEF message
url_t url = {{URL_BASE},
             {0}};
             
// Convert UID to hex string
utils_word_to_hex(uid[0], &url.id[0]);
utils_word_to_hex(uid[1], &url.id[8]);

// Buffer for binary NDEF message
uint8_t msg[80] = {};

// Binary NDEF message length
uint8_t msg_len;

//Generate message
ndef_msg_rtd_uri((uint8_t*)&url, sizeof(url), msg, &msg_len);

// Write message to the NFC front-end buffer
NFC_write(0, (uint32_t*)msg, msg_len/(sizeof(uint32_t)));
```

# Useful resources about NFC
It wasn't very straightforward for me to find a good information about how NFC works and standards. Some useful resources are listed below.
[http://sweet.ua.pt/andre.zuquete/Aulas/IRFID/11-12/index-docs.html]
[https://www.nxp.com/docs/en/data-sheet/NTAG213_215_216.pdf]
[https://learn.adafruit.com/adafruit-pn532-rfid-nfc/ndef]
[https://stackoverflow.com/questions/22357664/android-nfc-smart-poster-ndef-record-with-concatenated-uri-and-text-content]
[https://www.netes.com.tr/netes/dosyalar/dosya/B6159F60458582512B16EF1263ADE707.pdf]
[https://flomio.com/2012/05/ndef-basics/]
[https://stackoverflow.com/questions/14669193/format-for-data-on-nfc-business-cards]
