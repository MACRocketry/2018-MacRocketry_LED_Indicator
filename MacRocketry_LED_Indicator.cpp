#include <MacRocketry_LED_Indicator.h>

MacRocketry_LED_Indicator::MacRocketry_LED_Indicator(){   //constructor
  Serial.begin(115200); //begin serial communication to PC for debugging
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  BMP_Status = false;
  GPS_Status = false;
  SD_Status = false;

}

/*  dis how error check work:
hundreds - BMP    tens - GPS    ones - SD
0 = good to go    >1 = error
*/


bool MacRocketry_LED_Indicator::Set_BMP_Status(bool status){
  BMP_Status = status;
  return BMP_Status;
}

bool MacRocketry_LED_Indicator::Set_GPS_Status(int fix){
  GPS_Status = 0 < fix;
  return GPS_Status;
}

bool MacRocketry_LED_Indicator::Set_SD_Status(bool status){
  BMP_Status = status;
}

int MacRocketry_LED_Indicator::StatusCheck(boolean BMP_test, int fix, boolean SD_test){   // will take more arguments here for BMP and SD
  err = 0;
  if (!BMP_test){
    err += 100;
  }
  if (fix == 0){
    err += 10;
  }
  if(!SD_test){
    err += 1;
  }
  displayLED(err); 
  return err;
}

boolean MacRocketry_LED_Indicator::CHECK_ALT(float BMP_alt, float GPS_alt){ //checks that alt readings agree within 1m
  if(BMP_alt-GPS_alt<1 && BMP_alt-GPS_alt>-1){
    return true;
  }else
    return false;
}

void MacRocketry_LED_Indicator::displayLED(int msg){
  switch (msg){
    case 111: // white --> BMP and GPS and SD errors
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
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
      analogWrite(redPin, 255);
      analogWrite(bluePin, 255);
      analogWrite(greenPin, 255);
      break;*/
  }
}
