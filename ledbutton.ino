#define ledPin 4
#define buttonPin 8

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}


// 0 - idle
// 1 - кнопка включена

//ledPin загорается при нажатии кнопки
void loop() {
  int data = digitalRead(buttonPin);
  if(digitalRead(buttonPin)){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
