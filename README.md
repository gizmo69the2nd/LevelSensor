# LevelSensor
Arduino library for reading liquid level sensor. Level is translated to 0-5V signal. Sensorheight, maximum sensor depth are measured in centimeters.

### Usage
  - ## **Level(uint8_t pin, float max_depth, float sens_depth)**
    #### **Description** 
    Define a new sensor.

    #### **Parameters**
    - **pin** (uint8_t): Analog pin connected to the sensor
    - **max_depth** (float): Maximum depth the sensor can measure (in centimeters).
    - **sens_depth** (float): Offset from the bottom where the sensor is positioned (in centimeters)

    #### **Returns**
    *None*


  - ## **void begin()**
    #### **Description**
    Initialize the sensor

    #### **Parameters**
    *None*

    #### **Returns**
    *None*


  - ## **float get()**
    #### **Description**
    Measures the total liquid level of the holding tank in centimeters.
    This includes the sensor offset from the bottom.

    #### **Parameters**
    *none*

    #### **Returns**
    Liquid level in centimeters as type **float**


  - ## **float get(uint8_t unit)**
    #### **Description**
    Measures the total liquid level of the holding tank according to the units specified.

    #### **Parameters**
    - **unit** (uint8_t): Unit of length of the return measured value.
      - CM: centimeters
      - M: meters
      - IN: inches
      - FT: feet

    #### **Returns**
    Liquid level in centimeters, meters, feet or inches as type **float**


  - ## **float getRaw()**
    #### **Description**
    Measures the liquid above the sensor in the holding tank in centimeters.

    #### **Parameters**
    *none*

    #### **Returns**
    Liquid level in centimeters as type **float**

  - ## **void setADCResolution(int resolution)**
    #### **Description**
    Change te default ADC resolution of 1023 (10bit) to another value according to the ADC being used.

    #### **Parameters**
    - **resolution** (uint8_t): Maximum ADC value. *(default 1023)*
    
    #### **Returns**
    *none*

## Example

    #include <Arduino.h>
    #include "LevelSensor.h"

    Level l1(A0,300,10); //maximum depth 300cm, offset from the bottom 10cm

    void setup() {
      
      l1.begin();
      Serial.begin(9600);
      Serial.println("Starting example");
    }

    void loop() {
      Serial.print("L1 - raw value: ");
      Serial.print(l1.getRaw());
      Serial.print("cm - Total: ");
      Serial.print(l1.get());
      Serial.print("cm - ");
      Serial.print(l1.get(M));
      Serial.print("m - ");
      Serial.print(l1.get(IN));
      Serial.print("in - ");
      Serial.print(l1.get(FT));
      Serial.println("ft");

      delay(100);
    }