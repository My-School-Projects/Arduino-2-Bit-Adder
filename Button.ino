
const int buttonAPin = 2;
const int buttonBPin = 3;
const int buttonCPin = 4;
const int buttonDPin = 5;
const int ledEPin = 10;
const int ledFPin = 12;
const int ledGPin = 11;

int buttonAState = 0;
int buttonBState = 0;
int buttonCState = 0;
int buttonDState = 0;
bool xorAC = 0;
bool carry = 0;

void setup() {
  pinMode(ledEPin, OUTPUT);
  pinMode(ledFPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  pinMode(buttonAPin, INPUT);
  pinMode(buttonBPin, INPUT);
  pinMode(buttonCPin, INPUT);
  pinMode(buttonDPin, INPUT);
}

void loop() {
  buttonAState = digitalRead(buttonAPin);
  buttonBState = digitalRead(buttonBPin);
  buttonCState = digitalRead(buttonCPin);
  buttonDState = digitalRead(buttonDPin);

  if ((buttonAState && !buttonCState) || (!buttonAState && buttonCState))
  {
    xorAC = HIGH;
  }
  else
  {
    xorAC = LOW;
  }

  if (buttonBState && buttonDState)
  {
    carry = HIGH;
  }
  else
  {
    carry = LOW;
  }

  if ((xorAC && !carry) || (!xorAC && carry))
  {
    digitalWrite(ledFPin, HIGH);
  }
  else
  {
    digitalWrite(ledFPin, LOW);
  }
  
  if ((buttonBState && !buttonDState) || (!buttonBState && buttonDState))
  {
    digitalWrite(ledGPin, HIGH);
  }
  else
  {
    digitalWrite(ledGPin, LOW);
  }

  if ((buttonBState && buttonDState) && (buttonAState || buttonCState) || (buttonAState && buttonCState))
  {
    digitalWrite(ledEPin, HIGH);
  }
  else
  {
    digitalWrite(ledEPin, LOW);
  }
}

