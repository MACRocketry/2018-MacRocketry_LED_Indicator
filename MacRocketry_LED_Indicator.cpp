#include <Arduino.h>                   //Arduino library
#include <MacRocketry_LED_Indicator.h> //header file

MacRocketry_LED_Indicator::MacRocketry_LED_Indicator(){   //constructor
  Serial.begin(115200); //begin serial communication to PC for debugging
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  BMP_Status = false;
  GPS_Status = false;
  SD_Status = false;

  error = 0x0; //reset error to all
  //bit set means working, bit clear means error

}

bool MacRocketry_LED_Indicator::setStatusBMP(bool stats){
  BMP_Status = stats;
  if (BMP_Status) error |= 0x100; //set bit
  else error &= 0x011; //clear bit
  displayLED();
  return BMP_Status;
}

bool MacRocketry_LED_Indicator::setStatusGPS(int fix){
  GPS_Status = 0 < fix;
  if (GPS_Status) error |= 0x010; //set bit
  else error &= 0x101; //clear bit
  displayLED();
  return GPS_Status;
}

bool MacRocketry_LED_Indicator::setStatusSD(bool stats){
  SD_Status = stats;
  if (SD_Status) error |= 0x001; //set bit
  else error &= 0x110; //clear bit
  displayLED();
  return SD_Status;
}


void MacRocketry_LED_Indicator::displayLED(){
  switch (error){
    case 0x000: //white --> BMP and GPS and SD errors
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
    case 0x001: //red -> BMP and GPS errors
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 0);
      break;
    case 0x010: //cyan -> BMP + SD error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;
    case 0x011: //purple -> BMP error
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 0);
      break;    
    case 0x100: //cyan -> GPS + SD error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;
    case 0x101: //yellow -> GPS error
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 255);
      break;
    case 0x110: //blue -> SD error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 0);
      break;
    case 0x111: //green -> no errors
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 255);
      break;
    default: //off -> used if the input message matches none of the above for some reason
      analogWrite(redPin, 127);
      analogWrite(bluePin, 64);
      analogWrite(greenPin, 64);
      break;
  }
}