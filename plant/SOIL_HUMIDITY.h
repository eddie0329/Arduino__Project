/* SOIL HUMIDITY HEADER */
#ifndef SOIL_HUMIDITY_H
#define SOIL_HUMIDITY_H
#include <Arduino.h>

class SoilHumidity {
  private:
    int soilHumidityInput;
    Logger logger;
  public:
    /* constructor */
    SoilHumidity(bool debug): logger("soil", debug) {
      soilHumidityInput = A0;
    };
    int calc() {
      int soilHumidity = map(analogRead(soilHumidityInput), 1000, 400, 0 , 100);
      if (soilHumidity > 100) return 100;
      else if (soilHumidity < 0) return 0;
      else return soilHumidity;
    };
};

#endif
