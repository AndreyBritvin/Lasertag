#ifndef SETTINGS_H__
#define SETTINGS_H__

#define USER_ID 0xDEED
#define TEAM_ID 0xC7

#define INITIAL_AMMO 5

#define LED_1_PIN 18
#define LED_2_PIN 5
#define LED_3_PIN 21
#define LED_4_PIN 19

#define IR_LED_PIN 33
#define IR_RCV_PIN 25

#define PIEZO_PIN 32

#define SHOT_PIN 27
#define RELD_PIN 26

#define RED_FRNT_ON  digitalWrite(LED_1_PIN, HIGH);
#define RED_FRNT_OFF digitalWrite(LED_1_PIN, LOW);

#define GRN_FRNT_ON  digitalWrite(LED_2_PIN, HIGH);
#define GRN_FRNT_OFF digitalWrite(LED_2_PIN, LOW);

#define RED_BACK_ON  digitalWrite(LED_3_PIN, HIGH);
#define RED_BACK_OFF digitalWrite(LED_3_PIN, LOW);

#define GRN_BACK_ON  digitalWrite(LED_4_PIN, HIGH);
#define GRN_BACK_OFF digitalWrite(LED_4_PIN, LOW);

const int LED_PIN_ARR[] =  {LED_1_PIN,
                            LED_2_PIN,
                            LED_3_PIN,
                            LED_4_PIN};
							
							
void set_pin_mode();
void test_pins(int duration);							

#endif // SETTINGS_H__