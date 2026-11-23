/*
 * init_usb.c
 *
 *  Created on: 18 de nov. de 2026
 *      Author: carlos-leite
 */

#include "driver_usb.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
#include "cJSON.h"
#include <string.h>
#include "main.h"

char cpy_buffer[128];
char *pBuf = cpy_buffer;
size_t len;
char response[128];
volatile char IsJsonMsg;

int cpBuf_usb(char *buf,uint8_t *buf_origem, uint32_t len){
	memcpy(buf,buf_origem,len);
	buf[len] = '\0';
	IsJsonMsg = 1;
	return 0;

}

int tratar_json(char *data, size_t len, char *response){


	strcpy(response,"LED Comando invalido");
//	if(len <= 0){
//		printf("data len inválido");
//	}
	IsJsonMsg = 0;
	if(data[0] == '{'){
		cJSON *json = cJSON_Parse(data);
//		if(json == NULL){

//		}
		if(cJSON_IsString(cJSON_GetObjectItem(json, "LED")) && (cJSON_GetObjectItem(json, "LED")->valuestring)){
			if(strcmp(cJSON_GetObjectItemCaseSensitive(json, "LED")->valuestring, "LIGAR")== 0){
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
				strcpy(response,"LED LIGADO");
			}
			else if (strcmp(cJSON_GetObjectItemCaseSensitive(json, "LED")->valuestring, "DESLIGAR")== 0){
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
				strcpy(response,"LED DESLIGADO");
			}
			else{
				strcpy(response,"LED Comando invalido");
			}
		}

			cJSON *response_ptr = cJSON_CreateObject();

			cJSON_AddStringToObject(response_ptr, "payload",response);
			char *json_str = cJSON_PrintUnformatted(response_ptr);
			if(json_str != NULL){
				CDC_Transmit_FS((uint8_t*)json_str, strlen(json_str));
			}

			cJSON_free(json_str);
			cJSON_Delete(response_ptr);
			cJSON_Delete(json);
//			IsJsonMsg = 0;
	}

	return 0;
}

void read_usb(){


	if(IsJsonMsg){

		tratar_json(pBuf,len,response);
//		uint16_t bytesRecebidos = CDC_GetRxBufferBytesAvailable_FS();
	}
}
