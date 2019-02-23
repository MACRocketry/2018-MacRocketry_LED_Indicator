#include <MacRocketry_LED_Indicator.h>
#include <MacRocketry_SD_Logger.h>
#include <MacRocketry_GPS_Shield.h>

//includes for Adafruit BMP
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

MacRocketry_SD_Logger sd;
MacRocketry_GPS_Shield gps;
MacRocketry_LED_Indicator led;
Adafruit_BMP085_Unified bmp;

bool bmpStat;

void setup() {
  Serial.begin(115200);
  bmpStat = bmp.begin(); //begin() function returns true if chip ID is BMP
}

void loop() {
  //check for BMP error
  led.setStatusBMP(bmpStat); //if chip is BMP
  
  //check for GPS error
  gps.readData();
  led.setStatusGPS(gps.fix); //if GPS has a fix

  //check for SD error
  led.setStatusSD(sd.connectFile); //if file is open to write

}
