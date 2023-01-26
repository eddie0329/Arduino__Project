/* LCD DISPLAY HEADER */
#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class LCDDisplay {
  private:
    LiquidCrystal_I2C lcd;
    Logger logger;
  public:
    /* constructor */
    LCDDisplay(bool debug): lcd(0x27, 16, 2), logger("lcd", debug) {};
    void init() {
      lcd.init();
      clear();
      welcomeMsg();
    };
    void welcomeMsg() {
      print(0, 0, "Welcome, Eddie.");
      blink();
    };
    /** @description: clear display */
    void clear() { lcd.clear(); };
    /** @description: off backlight of display */
    void noBacklight() { lcd.noBacklight(); };
    /** @description: on backlight of display */
    void backlight() { lcd.backlight(); };
    /** @description: print msg on display */
    void print(int cols, int rows, String msg) {
      lcd.begin(cols, rows); 
      lcd.print(msg); 
    }
    /** @description: blink backlight to notifiy */
    void blink() {
      backlight();
      delay(5000);
      noBacklight();
    };
};

#endif
