#include <arduino.h>
#include "../include/Sounds.h"
#include "../include/Settings.h"

// --- Звук попадания (короткий "бип-бип") ---
void soundHit() {
  RED_FRNT_ON
  tone(PIEZO_PIN, 1000, 100); // высокий короткий
  delay(120);
  tone(PIEZO_PIN, 800, 150);  // чуть ниже
  delay(200);
  noTone(PIEZO_PIN);
  RED_FRNT_OFF
}

// --- Звук смерти (нисходящий "у-у-у") ---
void soundDeath() {
  RED_FRNT_ON
  RED_BACK_ON
  for (int f = 1000; f >= 200; f -= 50) {
    tone(PIEZO_PIN, f, 80);
    delay(90);
  }
  noTone(PIEZO_PIN);
  delay(10000);
  RED_FRNT_OFF
  RED_BACK_OFF
}

// --- Звук выстрела (короткий щелчок) ---
void soundShot() {
  GRN_FRNT_ON
  tone(PIEZO_PIN, 2000, 50); // очень короткий пик
  delay(60);
  tone(PIEZO_PIN, 1500, 30);
  delay(50);
  noTone(PIEZO_PIN);
  GRN_FRNT_OFF
}

// --- Звук перезарядки (восходящая мелодия) ---
void soundReload() {
  RED_BACK_ON
  int notes[] = {500, 700, 900, 1200};
  for (int i = 0; i < 4; i++) {
    tone(PIEZO_PIN, notes[i], 120);
    delay(150);
  }
  noTone(PIEZO_PIN);
  RED_BACK_OFF
  GRN_BACK_ON
  delay(1000);
  GRN_BACK_OFF
}

// --- Звук пустой обоймы (двойной щелчок) ---
void soundEmptyMag() {
  RED_BACK_ON
  for (int i = 0; i < 2; i++) {
    tone(PIEZO_PIN, 400, 80); // низкий щелчок
    delay(120);
    noTone(PIEZO_PIN);
    delay(100);
  }
  RED_BACK_OFF
}