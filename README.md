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
