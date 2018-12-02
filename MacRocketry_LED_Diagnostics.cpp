#include <MacRocketry_LED_Diagnostics.h>

MacRocketry_LED_Diagnostics::MacRocketry_LED_Diagnostics(){   //constructor
  Serial.begin(9600); //not sure if this should go here
  
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

/*  dis how error check work:

hundreds - BMP    tens - GPS    ones - SD
0 = good to go    >1 = error

*/

void MacRocketry_LED_Diagnostics::StatusCheck(boolean BMP_test, int fix, boolean SD_test){   // will take more arguments here for BMP and SD
  err = 0;
  if (BMP_test){
    err += 100;
  }
  if (fix == 0){
    err += 10;
  }
  if(SD_test){
    err += 1;
  }
  displayLED(err); 
  //if(case != PRE_LAUNCH)
  //  return; 
}

boolean MacRocketry_LED_Diagnostics::CHECK_ALT(float BMP_alt, float GPS_alt){ //checks that alt readings agree within 1m
  if(BMP_alt-GPS_alt<1 && BMP_alt-GPS_alt>-1){
    return true;
  }
  return false;
}

void MacRocketry_LED_Diagnostics::displayLED(int msg){
  switch (msg){
    case 110//red -> BMP and GPS errors
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 0);
      break;
    case 1: //blue -> SD card error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 0);
      break;
    case 0: //green -> no errors
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 255);
      break;
    case 100//purple -> GPS error
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 0);
      break;
    case 10: //yellow -> BMP error
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      analogWrite(greenPin, 255);
      break;
    case 11: //cyan -> sensor + SD error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;
    case 101: //cyan -> sensor + SD error
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;
    default: //white -> used if the input message matches none of the above for some reason
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;
  }
}
