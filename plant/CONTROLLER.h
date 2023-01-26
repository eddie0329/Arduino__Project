/* CONTROLLER HEADER */
#ifndef CONTROLLER_H
#define CONTROLLER_H

/* INCLUDES */
#include <Arduino.h>
#include "LOGGER.h"
#include "RGB_LIGHT.h"
#include "SOIL_HUMIDITY.h"
#include "MOTOR_PUMP.h"
#include "LCD_DISPLAY.h"

class Controller {
  private:
    Logger logger;
    RGBLight rgb;
    SoilHumidity soilHumidity;
    MotorPump motorPump;
    LCDDisplay lcd;
  public:
    /* constructor */
    Controller(bool debug): logger("controller", debug), rgb(debug), soilHumidity(debug), motorPump(debug), lcd(debug) {};
    void notifyStatus() { lcd.print(0, 0, "Humidity: " + String(soilHumidity.calc()) + "%"); };
    void init() {
      logger.init();
      rgb.init();
      motorPump.init();
      lcd.init();
    };
    
    void finishHydrate() {
      motorPump.finishHydrate();
    };
    void start() {
      notifyStatus();
      if (soilHumidity.calc() < 20) { /* needs hydration */
        motorPump.startHydrate();
        lcd.blink();
      } else { /* no need hydration */
        finishHydrate();
        motorPump.finishHydrate();
      }
    }
};

#endif
