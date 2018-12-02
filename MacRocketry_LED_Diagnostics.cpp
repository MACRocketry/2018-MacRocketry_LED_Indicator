#include <MacRocketry_LED_Diagnostics.h>
#include "Arduino.h"

MacRocketry_LED_Diagnostics::MacRocketry_LED_Diagnostics(){   //constructor
  Serial.begin(115200); //not sure if this should go here
  
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

/*  dis how error check work:

hundreds - BMP    tens - GPS    ones - SD
0 = good to go    >1 = error

*/

int MacRocketry_LED_Diagnostics::StatusCheck(bool BMP_check, int fix, bool SD_check){
  err = 0;
  if (BMP_check){
    err += 100;
  }
  if (fix == 0){
    err += 10;
  }
  if(SD_check){
    err += 1;
  }
  displayLED(err); 
  return err;
}

boolean MacRocketry_LED_Diagnostics::CHECK_ALT(float BMP_alt, float GPS_alt){ //checks that alt readings agree within 1m
  if(BMP_alt-GPS_alt<1 && BMP_alt-GPS_alt>-1){
  //compare BMP and GPS outputs
  //return true if they don't agree within a certain range
    return true;
  }
  return false;
}

void MacRocketry_LED_Diagnostics::displayLED(int msg){
  switch (msg){
    case 111: //white -> BMP and GPS and SD errors
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;
    case 110: //red -> BMP and GPS errors
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 0);
      break;
    case 101: //cyan -> BMP + SD error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;   
    case 100: //purple -> BMP error
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 0);
      break;
    case 11: //cyan -> GPS + SD error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;
    case 10: //yellow -> GPS error
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 255);
      break;
    case 1: //blue -> SD error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 0);
      break;
    case 0: //green -> no errors
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 255);
      break;
/*    default: //off -> used if the input message matches none of the above for some reason
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 0);
      break;*/
  }
}
