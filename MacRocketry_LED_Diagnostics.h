#ifndef MacRocketry_LED_Diagnostics_h
#define MacRocketry_LED_Diagnostics_h

#define redPin 3
#define bluePin 6
#define greenPin 5

class MacRocketry_LED_Diagnostics {
  public:
    MacRocketry_LED_Diagnostics(void);  //constructor
    void StatusCheck(boolean BMP_test, int fix, boolean SD_check);
    //boolean CHECK_ALT(float BMP_alt, float GPS_alt); 
  
  private:
    int err;

    boolean CHECK_ALT(float BMP_alt, float GPS_alt);
    void displayLED(int msg);
};

#endif
