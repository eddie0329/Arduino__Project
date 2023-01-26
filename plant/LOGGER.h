/* LOGGER HEADER */
#ifndef LOGGER_H
#define LOGGER_H
#include <Arduino.h>

class Logger {
  private: 
    String startingMsg;
    bool debugMode;
  public:
    /* constructor */
    Logger(String msg, bool debug) {
      startingMsg = msg;
      debugMode = debug;
    };
    void init() {
      Serial.begin(9600);
    };
    void log(String str) {
      if (debugMode == false) return; /* guard */
      Serial.println(startingMsg + ": " + str); 
    };
};

#endif
