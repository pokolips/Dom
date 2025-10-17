#pragma once

#include <GyverDS18.h>

GyverDS18Single ds(2);  // пин 2

class Temperature
{
private:
  float _termo = 0;
  
public:

void settemp() {
    ds.requestTemp();  // первый запрос на измерение
}

float gettemp() {
    if (ds.ready()) {         // измерения готовы по таймеру
        if (ds.readTemp()) {  // если чтение успешно
            Serial.print("temp: ");
            Serial.println(ds.getTemp());
            _termo = ds.getTemp();
        } else {
            Serial.println("read error");
        }

        ds.requestTemp();  // запрос следующего измерения
    } return _termo;
}


//     Temperature(/* args */);
//     ~Temperature();
 };

// Temperature::Temperature(/* args */)
// {
// }

// Temperature::~Temperature()
// {
// }





