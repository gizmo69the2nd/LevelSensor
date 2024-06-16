#ifndef LEVELSENSOR_H
#define LEVELSENSOR_H

/*
Lib LevelSensor
version: 1.0.0
author: Davy Van Belle 
sentence: Pressure differential MXP serie
Description: library for reading liquid level sensor. Level is translated to 0-5V or 0-10v signal. Sensorheight, maximum sensor depth and waterlevel are measured in centimeters.
category: Sensor Analogic Liquid Level
*/

#include "Arduino.h"
class Level
{
  #define CM 0x00
  #define M 0x01
  #define IN 0x02
  #define FT 0x03

  public:
    Level(uint8_t pin); //pin
    Level(uint8_t pin, float max_depth); //pin, max_depth
    Level(uint8_t pin, float max_depth, float sens_depth); //pin, max_depth, sens_depth
    void begin();
    float get(); //Measure level, return in cm
    float get(uint8_t unit);
    float getRaw(); //Measure level, return in voltage
    void setADCResolution(int); //Set ADC bit resolution default 10bits = 1023

  private:
    uint8_t _pin;
    int _sens_depth = 0;
    int _max_depth;
    int _ADC_res = 1023;

};


#endif //LEVELSENSOR_H