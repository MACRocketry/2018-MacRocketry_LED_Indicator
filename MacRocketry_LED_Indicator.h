#ifndef MacRocketry_LED_Indicator_h
#define MacRocketry_LED_Indicator_h

#include <Arduino.h>  //include Arduino library

#define redPin 9
#define greenPin 6
#define bluePin 5

class MacRocketry_LED_Indicator {
  public:
    MacRocketry_LED_Indicator(void); //constructor

    bool Set_BMP_Status(bool stats); //check BMP error
    bool Set_GPS_Status(int fix); //check GPS error
    bool Set_SD_Status(bool stats); //check SD error

    void displayLED(void);
    
  private:
    bool BMP_Status;
    bool GPS_Status;
    bool SD_Status;
    char error;

};

#endif