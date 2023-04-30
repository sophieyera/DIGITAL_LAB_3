int ledPin1 = 7;
int ledPin2 = 8;
int ledPin3 = 9;
int ledPin4 = 10;
int ledPin5 = 11;

int buttonPin1 = 33;
int buttonPin2 = 34;
int buttonPin3 = 35;
int buttonPin4 = 18;
int buttonPin5 = 40;
int toggleSwitch1 = 26;
int toggleSwitch2 = 25;

int potValue = 0;

int octave = 12;

int randomOrderLed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  pinMode(potValue, INPUT);

  int num = 0;
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(A13);
  Serial.println(potValue);

  for (int i = 0; i < 4; i++) {
    num = num + i;
    Serial.println(num);


 if (digitalRead(buttonPin5) == HIGH) {
    randomOrderLed = random(7, 11);
    digitalWrite(randomOrderLed, HIGH);
    delay(500);
    digitalWrite(randomOrderLed, LOW);
    delay(500);
  }

  if (digitalRead(toggleSwitch2) == HIGH) {
    octave = 12;
  }
  if (digitalRead(toggleSwitch2) == LOW) {
    octave = 0;
  }

  if (digitalRead(toggleSwitch1) == HIGH) {
    arpeggiatorMode();
  }
  if (digitalRead(toggleSwitch1) == LOW) {
    keyboardMode();
  }
}

void arpeggiatorMode() {

  if (digitalRead(buttonPin1) == HIGH) {
    arpeggio(60);
  }
  if (digitalRead(buttonPin2) == HIGH) {
    arpeggio(64);
  }
  if (digitalRead(buttonPin3) == HIGH) {
    arpeggio(67);
  }
  if (digitalRead(buttonPin4) == HIGH) {
    arpeggio(71);
  }
}

void arpeggio(int note) {
  digitalWrite(ledPin1, HIGH);
  usbMIDI.sendNoteOn(note + octave, 127, 1);
  delay(potValue);
  usbMIDI.sendNoteOff(note + octave, 0, 1);
  digitalWrite(ledPin1, LOW);
  delay(potValue);
  digitalWrite(ledPin2, HIGH);
  usbMIDI.sendNoteOn(note + 4 + octave, 127, 1);
  delay(potValue);
  usbMIDI.sendNoteOff(note + 4 + octave, 0, 1);
  digitalWrite(ledPin2, LOW);
  delay(potValue);
  digitalWrite(ledPin3, HIGH);
  usbMIDI.sendNoteOn(note + 7 + octave, 127, 1);
  delay(potValue);
  usbMIDI.sendNoteOff(note + 7 + octave, 0, 1);
  digitalWrite(ledPin3, LOW);
  delay(potValue);
  digitalWrite(ledPin4, HIGH);
  usbMIDI.sendNoteOn(note + 11 + octave, 127, 1);
  delay(potValue);
  usbMIDI.sendNoteOff(note + 11 + octave, 0, 1);
  digitalWrite(ledPin4, LOW);
  delay(potValue);
}

void keyboardMode() {
  checkKeyboardButton1();
  checkKeyboardButton2();
  checkKeyboardButton3();
  checkKeyboardButton4();
}

void checkKeyboardButton1() {
  if (digitalRead(buttonPin1) == HIGH) {
    digitalWrite(ledPin1, HIGH);
    usbMIDI.sendNoteOn(60 + octave, 127, 1);
    delay(potValue);
    usbMIDI.sendNoteOff(60 + octave, 0, 1);
    digitalWrite(ledPin1, LOW);
  }
}

void checkKeyboardButton2() {
  if (digitalRead(buttonPin2) == HIGH) {
    digitalWrite(ledPin2, HIGH);
    usbMIDI.sendNoteOn(64 + octave, 127, 1);
    delay(potValue);
    usbMIDI.sendNoteOff(64 + octave, 0, 1);
    digitalWrite(ledPin2, LOW);
  }
}

void checkKeyboardButton3() {
  if (digitalRead(buttonPin3) == HIGH) {
    digitalWrite(ledPin3, HIGH);
    usbMIDI.sendNoteOn(67 + octave, 127, 1);
    delay(potValue);
    usbMIDI.sendNoteOff(67 + octave, 0, 1);
    digitalWrite(ledPin3, LOW);
  }
}

void checkKeyboardButton4() {
  if (digitalRead(buttonPin4) == HIGH) {
    digitalWrite(ledPin4, HIGH);
    usbMIDI.sendNoteOn(71 + octave, 127, 1);
    delay(potValue);
    usbMIDI.sendNoteOff(71 + octave, 0, 1);
    digitalWrite(ledPin4, LOW);
  }
}
