#include "include/Settings.h"
#include "include/Sounds.h"
#include "include/Game.h"

#define IS_PRESSED(TYPE)  (TYPE##_btn.state == LOW  && TYPE##_btn.last_state == HIGH)
#define IS_RELEASED(TYPE) (TYPE##_btn.state == HIGH && TYPE##_btn.last_state == LOW )

#include <IRsend.h>
#include <IRrecv.h>
#include <IRutils.h>

IRsend irsend(IR_LED_PIN);  // Set the GPIO to be used to sending the message.
IRrecv irrecv(IR_RCV_PIN);
decode_results results;

Button_t shot_btn = {SHOT_PIN, LOW, LOW, 0, 50};
Button_t reld_btn = {RELD_PIN, LOW, LOW, 0, 50};
Player_t player   = {true, true, INITIAL_AMMO, 100};

void setup()
{
  Serial.begin(115200);
  
  irsend.begin();
  irrecv.enableIRIn();

  set_pin_mode();
  test_pins(500);
}

void loop()
{
  debounce(&shot_btn); // TODO: make via interrupt
  debounce(&reld_btn);

  //print_button(&shot_btn);

  if (IS_PRESSED(shot))
  {
    shoot(&player, &irsend);
  }

  if (IS_PRESSED(reld))
  {
    reload(&player);
  }

  check_hit(&player, &irrecv, &results);
}
