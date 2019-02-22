#ifndef MacRocketry_LED_Indicator_h
#define MacRocketry_LED_Indicator_h

#define redPin 5
#define greenPin 6
#define bluePin 3

/*
#define ERROR_ALL
#define ERROR_BMP
#define ERROR_
*/




class MacRocketry_LED_Indicator {
  public:
    MacRocketry_LED_Indicator(void);  //constructor
    int StatusCheck(bool BMP_test, int fix, bool SD_check);
    //bool CHECK_ALT(float BMP_alt, float GPS_alt); 
  
  private:
    bool BMP_Status;
    bool GPS_Status;
    bool SD_Status;

    
    enum loopError {
      Error_BMP;
      ERROR_GPS;
      ERROR_SD;
    };
    loopError displayError;

    int err;

    bool CHECK_ALT(float BMP_alt, float GPS_alt);
    void displayLED(int msg);
};

#endif
