#ifndef GAME_H__
#define GAME_H__

#include <IRsend.h>
#include <IRrecv.h>
#include <IRutils.h>

struct Button_t {
	const int pin;
	int state;
	int last_state;
	unsigned long last_debounce_time;
	unsigned long debounce_delay; 
};

struct Player_t {
	bool is_alive;
	bool can_fire;
	int ammo;
	int hp;
};

void debounce(Button_t *button);
void print_button(Button_t *button);

void shoot    (Player_t *player, IRsend *irsend);
void check_hit(Player_t *player, IRrecv *irrecv, decode_results *results);
void reload   (Player_t *player);

unsigned long generate_code(int team_id, int player_id);
bool check_code(unsigned long code);

#endif // GAME_H__