/* MOTOR PUMP HEADER */
#ifndef MOTOR_PUMP_H
#define MOTOR_PUMP_H
#include <Arduino.h>

class MotorPump {
  private:
    int mainMotorInput;
    int subMotorInput;
    Logger logger;
  public:
    /* constructor */
    MotorPump(bool debug): logger("motor", debug) {
      mainMotorInput = 8;
      subMotorInput = 7;
    };
    void init() {
      pinMode(mainMotorInput, OUTPUT);
      pinMode(subMotorInput, OUTPUT);
    };
    void startHydrate() {
      logger.log("/* START HYDRATE */");
      digitalWrite(mainMotorInput, LOW);
      digitalWrite(subMotorInput, HIGH);
    };
    void finishHydrate() {
      logger.log("/* FINISH HYDRATE */");
      digitalWrite(mainMotorInput, LOW);
      digitalWrite(subMotorInput, LOW);
    };
};

#endif
