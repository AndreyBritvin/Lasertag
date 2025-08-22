#include "include/Settings.h"
#include "include/Sounds.h"
#include "include/Game.h"

Button_t shot_btn = {SHOT_PIN, LOW, LOW, 0, 50};
Button_t reld_btn = {RELD_PIN, LOW, LOW, 0, 50};
  
void setup()
{
  Serial.begin(115200);
  set_pin_mode();
  test_pins(500);
}

void loop()
{
  debounce(&shot_btn);
  debounce(&reld_btn);

  print_button(&shot_btn);
}
