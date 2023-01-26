#include "CONTROLLER.h"
/* parameters defines wheter log or not */
Controller controller(true);

/* SET UPS */
void setup() {
  // put your setup code here, to run once:
  controller.init();
}

/* LOOP */
void loop() {
  // put your main code here, to run repeatedly;
  controller.start();
}
