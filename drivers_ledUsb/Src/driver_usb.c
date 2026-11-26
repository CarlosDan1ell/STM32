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

#define FALHA 0
#define SUCESSO 1
#define RX_MSG_MAX 256

char response[128];
size_t len;
char data[RX_MSG_MAX];


void tratar_json(char *data, size_t len, char *response){

	while(xQueueReceive(receiveQueue, &data,portMAX_DELAY)){
		if(data[0] == '{'){
			cJSON *json = cJSON_Parse(data);
			if(json == NULL){
				enviar_reply("Json_invalido", FALHA);
				return;
			}

			//	{"action":"post","data":{"id":1024,"device":"stm32_board_01","param":{"cmd":"on","speed":0,"repeat":0}}}
			//	{"action":"reply","data":{"id":1024,"device":"stm32_board_01","log":{"status":true,"error":"none"}}}

			if(cJSON_IsString(cJSON_GetObjectItemCaseSensitive(json, "action")) && (cJSON_GetObjectItemCaseSensitive(json, "action")->valuestring)){

				if(strcmp(cJSON_GetObjectItemCaseSensitive(json, "action")->valuestring, "post") == 0){
					cJSON *data_obj  = cJSON_GetObjectItemCaseSensitive(json, "data");
					cJSON *obj_param = cJSON_GetObjectItemCaseSensitive(data_obj, "param");
					if(cJSON_IsObject(obj_param)){
						if(cJSON_IsString(cJSON_GetObjectItemCaseSensitive(obj_param,"cmd")) && cJSON_GetObjectItemCaseSensitive(obj_param, "cmd")->valuestring){
							if(strcmp(cJSON_GetObjectItemCaseSensitive(obj_param, "cmd")->valuestring, "on")== 0){
								HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
								strcpy(response,"none"); //criar função ligar
								enviar_reply(response,SUCESSO);
							}
							else if(strcmp(cJSON_GetObjectItemCaseSensitive(obj_param, "cmd")->valuestring, "off")== 0){
								HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
								strcpy(response,"none");
								enviar_reply(response,SUCESSO);
							}

							else if((strcmp(cJSON_GetObjectItemCaseSensitive(obj_param, "cmd")->valuestring, "blink")== 0)  &&
								cJSON_IsNumber(cJSON_GetObjectItemCaseSensitive(obj_param,"speed")) &&
								cJSON_IsNumber(cJSON_GetObjectItemCaseSensitive(obj_param,"repeat"))){

								int repeat = cJSON_GetObjectItemCaseSensitive(obj_param, "repeat")->valueint;
								int speed = cJSON_GetObjectItemCaseSensitive(obj_param, "speed")->valueint;

								if((cJSON_GetObjectItemCaseSensitive(obj_param, "speed")->valueint > 5000) || (cJSON_GetObjectItemCaseSensitive(obj_param, "speed")->valueint <100)){
									strcpy(response, "speed invalido");
									enviar_reply(response,FALHA);
									return;
								}

								if(cJSON_GetObjectItemCaseSensitive(obj_param, "repeat")->valueint >1000 || (cJSON_GetObjectItemCaseSensitive(obj_param, "repeat")->valueint <= 0)){

									strcpy(response, "repeat invalido");
									enviar_reply(response,FALHA);
									return;
								}
								strcpy(response, "none");
								enviar_reply(response,SUCESSO);

								for(int i =0; i < repeat; i++){
									HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
									HAL_Delay(speed);
									HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
									HAL_Delay(speed);
								}
							}

						}else{
							strcpy(response, "cmd invalido");
							enviar_reply(response,FALHA);
							return;
						}
					}
				}else{
					strcpy(response, "action invalido");
					enviar_reply(response,FALHA);
					return;
			}

				cJSON_Delete(json);

			}else{

				enviar_reply("Json_invalido",FALHA);
			}

		}
	}
}

void enviar_reply(const char *buf_reply, bool status){

//	{"action":"reply","data":{"id":1024,"device":"stm32_board_01","log":{"status":true,"error":"none"}}}


	    cJSON *response_ptr = cJSON_CreateObject();
	    cJSON *json_data = cJSON_CreateObject();
	    cJSON *json_log = cJSON_CreateObject();

	    cJSON_AddStringToObject(response_ptr, "action", "reply");
	    cJSON_AddNumberToObject(json_data, "id", 1024);
	    cJSON_AddStringToObject(json_data, "device", "stm32_board_01");
	    cJSON_AddBoolToObject(json_log, "status", status);
	    cJSON_AddStringToObject(json_log, "error", buf_reply);
	    cJSON_AddItemToObject(json_data, "log", json_log);
	    cJSON_AddItemToObject(response_ptr, "data", json_data);

	    char *json_str = cJSON_PrintUnformatted(response_ptr);
	    if(json_str != NULL){
	    	int len = strlen(json_str);
	    	json_str[len+1] = '\n';
	        CDC_Transmit_FS((uint8_t*)json_str, strlen(json_str));
	        cJSON_free(json_str);
	    }
	    cJSON_Delete(response_ptr);

	    return;
}
