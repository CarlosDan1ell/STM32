/*
 * driver_RxUsb.c
 *
 *  Created on: 24 de nov. de 2026
 *      Author: carlos-leite
 */

#include "driver_rxUsb.h"
#include "FreeRTOS.h"
#include <string.h>
#include "cmsis_os.h"

#define RX_MSG_MAX 256

static uint16_t pos = 0;
static uint8_t buffer[RX_MSG_MAX];

void read_Rx(uint8_t* buf_msg, uint32_t len){

	for(uint32_t i = 0; i < len;i++){

		char b = buf_msg[i]; //passa byte por byte da mensagem que chegou

		if(b=='\n' && pos > 0){ //verifica se a mensagem acabou
			buffer[pos] = '\0';
			osMessageQueuePut(receiveQueue, &buffer, 0, 0);
			pos = 0;
		}

		if(b != '\n' && pos < RX_MSG_MAX -1 ){ //se ainda tem mensagem pra chegar, continua copiando byte a byte
			buffer[pos++] = b;
		}
	}
}
