/* Bluetooth Kontrollü Araç + Korna + Yanıp Sönen LED */

const int sol_enable = 11;
const int sag_ileri  = 10;
const int sag_geri   = 9;
const int sol_ileri  = 8;
const int sol_geri   = 7;
const int sag_enable = 6;
const int buzzer     = 5;
const int led        = 4;   // 🔴 LED pini

char gelen_veri = 'S';

// LED için zamanlayıcı
unsigned long oncekiZaman = 0;
const unsigned long aralik = 500;
bool ledDurum = false;

void setup() {
  pinMode(sag_ileri, OUTPUT);
  pinMode(sag_geri, OUTPUT);
  pinMode(sol_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sag_enable, OUTPUT);
  pinMode(sol_enable, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  dur();
}

void loop() {
  // --- LED otomatik yanıp sönsün ---
  if (millis() - oncekiZaman >= aralik) {
    oncekiZaman = millis();
    ledDurum = !ledDurum;
    digitalWrite(led, ledDurum);
  }

  // --- Bluetooth komutları ---
  if (Serial.available() > 0) {
    gelen_veri = Serial.read();
    Serial.println(gelen_veri);

    switch (gelen_veri) {
      case 'F': ileri(); break;
      case 'B': geri();  break;
      case 'L': sola();  break;
      case 'R': saga();  break;
      case 'S': dur();   break;
      case 'Y': korna(); break;
    }
  }
}

/* ---- Korna (aktif buzzer) ---- */
void korna() {
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);
}

/* ---- Hareket Fonksiyonları ---- */
void ileri() {
  digitalWrite(sag_ileri, 1); digitalWrite(sag_geri, 0);
  digitalWrite(sol_ileri, 1); digitalWrite(sol_geri, 0);
  analogWrite(sag_enable, 255);
  analogWrite(sol_enable, 255);
}
void geri() {
  digitalWrite(sag_ileri, 0); digitalWrite(sag_geri, 1);
  digitalWrite(sol_ileri, 0); digitalWrite(sol_geri, 1);
  analogWrite(sag_enable, 255);
  analogWrite(sol_enable, 255);
}
void sola() {
  digitalWrite(sag_ileri, 1); digitalWrite(sag_geri, 0);
  digitalWrite(sol_ileri, 0); digitalWrite(sol_geri, 1);
  analogWrite(sag_enable, 200);
  analogWrite(sol_enable, 200);
}
void saga() {
  digitalWrite(sag_ileri, 0); digitalWrite(sag_geri, 1);
  digitalWrite(sol_ileri, 1); digitalWrite(sol_geri, 0);
  analogWrite(sag_enable, 200);
  analogWrite(sol_enable, 200);
}
void dur() {
  digitalWrite(sag_ileri, 0); digitalWrite(sag_geri, 0);
  digitalWrite(sol_ileri, 0); digitalWrite(sol_geri, 0);
  analogWrite(sag_enable, 0);
  analogWrite(sol_enable, 0);
}