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

char response[128];
size_t len;
char data[RX_MSG_MAX];


void tratar_json(char *data, size_t len, char *response);
void enviar_reply(const char *buf_reply, bool status);

#endif /* INC_DRIVER_USB_H_ */
