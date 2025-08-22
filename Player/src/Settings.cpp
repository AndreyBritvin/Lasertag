#include <arduino.h>
#include "../include/Settings.h"
#include "../include/Sounds.h"

void set_pin_mode()
{
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);

  pinMode(PIEZO_PIN, OUTPUT);
  pinMode(IR_LED_PIN, OUTPUT);

  pinMode(SHOT_PIN, INPUT_PULLUP);
  pinMode(IR_RCV_PIN, INPUT);
  pinMode(RELD_PIN, INPUT_PULLUP);
}

void test_pins(int duration)
{
  digitalWrite(IR_LED_PIN, HIGH);

  for (int i = 0; i < 4; i++)
  {
    digitalWrite(LED_PIN_ARR[i], HIGH);
    delay(500);
  }

//  noTone(PIEZO_PIN);
//  // play a note on pin PIEZO_PIN for 200 ms:
//  tone(PIEZO_PIN, 440, 200);
//  delay(200);
//  noTone(PIEZO_PIN);
//  tone(PIEZO_PIN, 494, 500);
//  delay(500);
//  noTone(PIEZO_PIN);
//  tone(PIEZO_PIN, 523, 300);
//  delay(300);
//  noTone(PIEZO_PIN);
//  
  soundHit();     delay(duration);
  soundDeath();   delay(duration);
  soundShot();    delay(duration);
  soundReload();  delay(duration);
  soundEmptyMag();delay(duration);
//  delay(duration);

  digitalWrite(IR_LED_PIN, LOW);

  for (int i = 0; i < 4; i++)
  {
    digitalWrite(LED_PIN_ARR[i], LOW);
    delay(500);
  }
}