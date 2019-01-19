#ifndef MacRocketry_LED_Diagnostics_h
#define MacRocketry_LED_Diagnostics_h

#define redPin 5
#define bluePin 3
#define greenPin 6

class MacRocketry_LED_Diagnostics {
  public:
    MacRocketry_LED_Diagnostics(void);  //constructor
    int StatusCheck(bool BMP_test, int fix, bool SD_check);
    //bool CHECK_ALT(float BMP_alt, float GPS_alt); 
  
  private:
    int err;

    bool CHECK_ALT(float BMP_alt, float GPS_alt);
    void displayLED(int msg);
};

#endif
