
const int left_enable  = 11;   // ENABLE A
const int right_forward = 10;  // INPUT 1
const int right_backward = 9;  // INPUT 2
const int left_forward  = 8;   // INPUT 3
const int left_backward = 7;   // INPUT 4
const int right_enable = 6;    // ENABLE B
const int buzzer       = 5;    // Horn
const int led          = 4;    // Status LED

char incoming_data = 'S';      // Default: stopped

// Timer for LED
unsigned long previous_time = 0;
const unsigned long interval = 500;
bool led_state = false;

void setup() {
  pinMode(right_forward, OUTPUT);
  pinMode(right_backward, OUTPUT);
  pinMode(left_forward, OUTPUT);
  pinMode(left_backward, OUTPUT);
  pinMode(right_enable, OUTPUT);
  pinMode(left_enable, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  stopCar();
}

void loop() {
  // --- Automatic LED blinking (non-blocking) ---
  if (millis() - previous_time >= interval) {
    previous_time = millis();
    led_state = !led_state;
    digitalWrite(led, led_state);
  }

  // --- Bluetooth commands ---
  if (Serial.available() > 0) {
    incoming_data = Serial.read();
    Serial.println(incoming_data);

    switch (incoming_data) {
      case 'F': moveForward();  break;
      case 'B': moveBackward(); break;
      case 'L': turnLeft();     break;
      case 'R': turnRight();    break;
      case 'S': stopCar();      break;
      case 'Y': honk();         break;
    }
  }
}

/* ---- Horn (active buzzer) ---- */
void honk() {
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);
}

/* ---- Movement Functions ---- */
void moveForward() {
  digitalWrite(right_forward, 1); digitalWrite(right_backward, 0);
  digitalWrite(left_forward, 1);  digitalWrite(left_backward, 0);
  analogWrite(right_enable, 255);
  analogWrite(left_enable, 255);
}

void moveBackward() {
  digitalWrite(right_forward, 0); digitalWrite(right_backward, 1);
  digitalWrite(left_forward, 0);  digitalWrite(left_backward, 1);
  analogWrite(right_enable, 255);
  analogWrite(left_enable, 255);
}

void turnLeft() {
  digitalWrite(right_forward, 1); digitalWrite(right_backward, 0);
  digitalWrite(left_forward, 0);  digitalWrite(left_backward, 1);
  analogWrite(right_enable, 200);
  analogWrite(left_enable, 200);
}

void turnRight() {
  digitalWrite(right_forward, 0); digitalWrite(right_backward, 1);
  digitalWrite(left_forward, 1);  digitalWrite(left_backward, 0);
  analogWrite(right_enable, 200);
  analogWrite(left_enable, 200);
}

void stopCar() {
  digitalWrite(right_forward, 0); digitalWrite(right_backward, 0);
  digitalWrite(left_forward, 0);  digitalWrite(left_backward, 0);
  analogWrite(right_enable, 0);
  analogWrite(left_enable, 0);
}
