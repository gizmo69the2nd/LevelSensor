/*
Lib LevelSensor
version: 1.0.0
author: Davy Van Belle 
Description: library for reading liquid level sensor. Level is translated to 0-5V or 0-10v signal. Sensorheight, maximum sensor depth and waterlevel are measured in centimeters.
category: Sensor Analogic Liquid Level
*/

#include "LevelSensor.h"

Level::Level(uint8_t pin) //pin
{
  _pin = pin;
  _max_depth = 500;
  _sens_depth = 0;
}

Level::Level(uint8_t pin, float max_depth) //pin, max_depth
{
  _pin = pin;
  _max_depth = max_depth;
  _sens_depth = 0;
}

Level::Level(uint8_t pin, float max_depth, float sens_depth) //pin, max_depth, sens_depth
{
  _pin = pin;
  _max_depth = max_depth;
  _sens_depth = sens_depth;
}

void Level::begin() //Initiate all parameters
{
  pinMode(_pin,INPUT);
}

void Level::setADCResolution(int resolution)
{
  _ADC_res = resolution;
}

float Level::getRaw() //Measure level above sensor, return in cm
{
  return ((float)analogRead(_pin) * _max_depth) / _ADC_res;
}

float Level::get() //Measure total level, return in cm
{
  return _sens_depth + getRaw();
}

float Level::get(uint8_t unit)
{
  switch (unit)
  {
  case CM:  //value in centimeters
    return get();
    break;
  case M:   //value in meters
    return get()/100;
    break;
  case IN:  //value in inches
    return get()/2.54; 
    break;
  case FT:  //value in feet
    return get()/30.48;
    break;
  
  default:
    break;
  }
}