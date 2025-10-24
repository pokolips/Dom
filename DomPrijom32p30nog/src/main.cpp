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

// Структура должна совпадать со структурой
// на плате-отправителе
typedef struct struct_message {
    char a[32];
    int b;
    float c;
    String d;
    bool e;
} struct_message;

// Создаем myData
struct_message myData;

// Обратная функция при получении
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Char: ");
  Serial.println(myData.a);
  Serial.print("Int: ");
  Serial.println(myData.b);
  Serial.print("Float: ");
  Serial.println(myData.c);
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
  char n [32] = "Hello";
  String Uzel = "vanna";
  if (myData.a == "a"){
    myData.a = n;
  }
}