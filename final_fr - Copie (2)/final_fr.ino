#define pin_buzz 8
char data;

void setup() {
  pinMode(pin_buzz, OUTPUT);
  digitalWrite(pin_buzz, HIGH); // set buzzer pin HIGH to buzz by default
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    data = Serial.read();
    if (data == '0') {
      Serial.write('0');
      // Do nothing, let the buzzer continue to buzz
    } else if (data == '1') {
      Serial.write('1');
      noTone(pin_buzz); // Stop buzzing
    }
  }
}
