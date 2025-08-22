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

void shoot(Player_t *player, IRsend *irsend)
{
	if (player->hp == 0) // TODO: rethink this logic
	{
		soundDeath();
		return;
	}
	
	if (player->ammo == 0)
	{
		soundEmptyMag();
		return;
	}
	
	player->ammo--;
	
	irsend->sendNEC(0x00FFE01FUL);	// TODO: redo with user_id
	
	soundShot();
}

void hit(Player_t *player)
{
	
}

void reload(Player_t *player)
{
	soundReload();
	// need more delay?
	player->ammo = INITIAL_AMMO;
}

