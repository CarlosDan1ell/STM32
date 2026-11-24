/*
 * driver_usb.h
 *
 *  Created on: 18 de nov. de 2026
 *      Author: carlos-leite
 */

#ifndef INC_DRIVER_USB_H_
#define INC_DRIVER_USB_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

extern char cpy_buffer[256];
extern volatile char IsJsonMsg;

int cpBuf_usb(char *buf,uint8_t *buf_origem, uint32_t len);
void tratar_json(char *data, size_t len, char *response);
void read_usb(void);
void enviar_reply(const char *buf_reply, bool status);

#endif /* INC_DRIVER_USB_H_ */
