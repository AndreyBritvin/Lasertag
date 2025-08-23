#ifndef SETTINGS_H__
#define SETTINGS_H__

#define USER_ID 0xDEAD
#define TEAM_ID 0xC7

#define INITIAL_AMMO 5

#define LED_1_PIN 18
#define LED_2_PIN 5
#define LED_3_PIN 17
#define LED_4_PIN 16

#define IR_LED_PIN 33
#define IR_RCV_PIN 25

#define PIEZO_PIN 32

#define SHOT_PIN 26
#define RELD_PIN 27


const int LED_PIN_ARR[] =  {LED_1_PIN,
                            LED_2_PIN,
                            LED_3_PIN,
                            LED_4_PIN};
							
							
void set_pin_mode();
void test_pins(int duration);							

#endif // SETTINGS_H__