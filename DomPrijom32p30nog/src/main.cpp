#include "Arduino.h"
/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp32-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <esp_now.h>
#include <WiFi.h>
//#include "Shifr.h"

// Структура должна совпадать со структурой
// на плате-отправителе
typedef struct struct_message {
    char ob;
    char a[10];
    int b;
    float c;
   // float c1;
    String d;
    bool e;
} struct_message;
void setData();
float tVann;
float tKuhn;
char as[10];
char ad[10];

// Создаем myData
struct_message myData;
//Shifr shifr;

// Обратная функция при получении
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  //shifr.setAgmt(&myData);
  setData();
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Char: ");
  // Serial.println(myData.ob);
  // Serial.print("Char: ");
  //Serial.println(myData.a);
  Serial.print("Int: ");
  Serial.println(myData.b);
  Serial.print(ad);
  Serial.print(" ");
  Serial.println(tVann);//myData.c
  Serial.print(as);
  Serial.print(" ");
  Serial.println(tKuhn);
  Serial.print("String: ");
  Serial.println(myData.d);
  Serial.print("Bool: ");
  Serial.println(myData.e);
  Serial.println();
}

 
void setup() {
  // Запускаем монитор порта
  Serial.begin(115200);
  
  // Выставляем режим работы WiFi
  WiFi.mode(WIFI_STA);
//ESP_
  // Запускаем протокол ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Получаем состояние отправки    
  esp_now_register_recv_cb(OnDataRecv);
}
void loop() {
  char n [6] = "Hello";
 
}
void setData(){
  if (myData.ob == 'a'){
    strcpy(ad, "Vanna"); 
    strcpy(myData.a, "Vanna");
    tVann = myData.c;

  } else if (myData.ob == 'b'){
     strcpy(as, "Kuhnia");
        strcpy(myData.a, "Kuhnia");
           tKuhn = myData.c;
         }

}