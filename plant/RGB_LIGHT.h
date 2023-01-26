/* RGBLIGHT HEADER */
#ifndef RGB_LIGHT_H
#define RGB_LIGHT_H
#include <Arduino.h>

class RGBLight {
  private:
    int blueLightInput;
    int redLightInput;
    int greenLightInput;
    Logger logger;
    void setLight(int lightInput, bool lightOn) {
      if (lightOn) digitalWrite(lightInput, HIGH);
      else digitalWrite(lightInput, LOW);
    };
  public:
    /* constructor */
    RGBLight(bool debug): logger("rgb", debug) {
      blueLightInput = 11;
      redLightInput = 10;
      greenLightInput = 9;
    };
    void init() {
      pinMode(blueLightInput, OUTPUT);
      pinMode(redLightInput, OUTPUT);
      pinMode(greenLightInput, OUTPUT);
    };
    /* manipulate red light */
    void onRed() { setLight(redLightInput, true); };
    void offRed() { setLight(redLightInput, false); };
    /* manipulate green light */
    void onGreen() { setLight(greenLightInput, true); };
    void offGreen() { setLight(greenLightInput, false); };
    /* manipulate blue light */
    void onBlue() { setLight(blueLightInput, true); };
    void offBlue() { setLight(blueLightInput, false); };
    void turnAllOn() {
      onRed();
      onGreen();
      onBlue();
    };
    void turnAllOff() {
      offRed();
      offGreen();
      offBlue();
    }
};

#endif
