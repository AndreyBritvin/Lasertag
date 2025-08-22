#include <arduino.h>
#include "../include/Settings.h"
#include "../include/Sounds.h"
#include "../include/Game.h"

void debounce(Button_t *button) {
  int reading = !digitalRead(button->pin);

  if (reading != button->last_state) {
    button->last_debounce_time = millis();
  }

  if ((millis() - button->last_debounce_time) > button->debounce_delay) {
    if (reading != button->state) {
      button->state = reading;
    }
  }
  button->last_state = reading;
}

void print_button(Button_t *button)
{
    Serial.print("Pin: ");
    Serial.print(button->pin);

    Serial.print(" State: ");
    Serial.print(button->state);

    Serial.print(" Last State: ");
    Serial.print(button->last_state);

    Serial.print(" Last Debounce Time: ");
    Serial.print(button->last_debounce_time);

    Serial.print(" Debounce Delay: ");
    Serial.println(button->debounce_delay);

    //Serial.println("----------------------");
}