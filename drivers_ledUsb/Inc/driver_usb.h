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

extern char cpy_buffer[128];
extern volatile char IsJsonMsg;

int cpBuf_usb(char *buf,uint8_t *buf_origem, uint32_t len);
int tratar_json(char *data, size_t len, char *response);
void read_usb(void);

#endif /* INC_DRIVER_USB_H_ */
