#ifndef GAME_H__
#define GAME_H__

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

void shoot (Player_t *player);
void hit   (Player_t *player);
void reload(Player_t *player);

#endif // GAME_H__