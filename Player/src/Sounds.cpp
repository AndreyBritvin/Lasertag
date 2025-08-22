#include <arduino.h>
#include "../include/Sounds.h"
#include "../include/Settings.h"

// --- Звук попадания (короткий "бип-бип") ---
void soundHit() {
  tone(PIEZO_PIN, 1000, 100); // высокий короткий
  delay(120);
  tone(PIEZO_PIN, 800, 150);  // чуть ниже
  delay(200);
  noTone(PIEZO_PIN);
}

// --- Звук смерти (нисходящий "у-у-у") ---
void soundDeath() {
  for (int f = 1000; f >= 200; f -= 50) {
    tone(PIEZO_PIN, f, 80);
    delay(90);
  }
  noTone(PIEZO_PIN);
}

// --- Звук выстрела (короткий щелчок) ---
void soundShot() {
  tone(PIEZO_PIN, 2000, 50); // очень короткий пик
  delay(60);
  tone(PIEZO_PIN, 1500, 30);
  delay(50);
  noTone(PIEZO_PIN);
}

// --- Звук перезарядки (восходящая мелодия) ---
void soundReload() {
  int notes[] = {500, 700, 900, 1200};
  for (int i = 0; i < 4; i++) {
    tone(PIEZO_PIN, notes[i], 120);
    delay(150);
  }
  noTone(PIEZO_PIN);
}

// --- Звук пустой обоймы (двойной щелчок) ---
void soundEmptyMag() {
  for (int i = 0; i < 2; i++) {
    tone(PIEZO_PIN, 400, 80); // низкий щелчок
    delay(120);
    noTone(PIEZO_PIN);
    delay(100);
  }
}