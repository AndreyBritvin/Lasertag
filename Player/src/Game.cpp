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
	
	irsend->sendNEC(generate_code(TEAM_ID, USER_ID));
	
	soundShot();
}

void check_hit(Player_t *player, IRrecv *irrecv, decode_results *results)
{
	if (!(irrecv->decode(results))) 
  {
    return;
  }
  unsigned long hit_code = results->value; 
  serialPrintUint64(results->value, HEX);
  Serial.println("");
  irrecv->resume();
  if (!check_code(hit_code))
  {
    Serial.println("Wrong CRC");
    return;
  }
  if (hit_code == generate_code(TEAM_ID, USER_ID)) // TODO: add team filter
  {
    Serial.println("Shoot (((");
    soundDeath();
  }
}

void reload(Player_t *player)
{
	soundReload();
	// need more delay?
	player->ammo = INITIAL_AMMO;
}

unsigned long generate_code(int team_id, int player_id) {
  // контрольная сумма: сумма байтов team_id и player_id (младший и старший)
  int checksum = (team_id + (player_id & 0xFF) + (player_id >> 8)) & 0xFF;

  unsigned long long code = 0;
  code |=  (unsigned long long)team_id;            // биты 0-7
  code |= ((unsigned long long)player_id << 8);    // биты 8-23
  code |= ((unsigned long long)checksum << 24);    // биты 24-31

  return code;
}

bool check_code(unsigned long code) {
  int team_id   = (uint8_t)  (code        & 0xFF);
  int player_id = (uint16_t)((code >>  8) & 0xFFFF);
  int checksum =  (uint8_t) ((code >> 24) & 0xFF);

  int calc_checksum = (team_id + (player_id & 0xFF) + (player_id >> 8)) & 0xFF;

  return (checksum == calc_checksum);
}
