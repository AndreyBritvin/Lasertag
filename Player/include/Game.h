#ifndef GAME_H__
#define GAME_H__

struct Button_t {
	const int pin;
	int state;
	int last_state;
	unsigned long last_debounce_time;
	unsigned long debounce_delay; 
};

void debounce(Button_t *button);
void print_button(Button_t *button);

#endif // GAME_H__