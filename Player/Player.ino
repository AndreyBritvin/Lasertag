#include "include/Settings.h"
#include "include/Sounds.h"

void setup()
{
  Serial.begin(115200);
  set_pin_mode();
  test_pins(2000);
}

void loop()
{
  
}
