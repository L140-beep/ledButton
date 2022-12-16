#define led_pin 3
#define btn_pin A2

bool led_state = false;
int currentValue, prevValue;
int power = 255;
bool go_fotward = false;

void setup(){
  pinMode(led_pin, OUTPUT);
  pinMode(btn_pin, INPUT);
  Serial.begin(9600);
}

void loop(){
  currentValue = digitalRead(btn_pin);
  if (currentValue != prevValue){
    delay(10);
    currentValue = digitalRead(btn_pin);
    long pressed = millis();
    while (digitalRead(btn_pin)){
      if (millis() - pressed >= 500 && led_state){
        while (digitalRead(btn_pin)){
          if (go_fotward){
            power = min(power + 1, 255);
          }
          else{
            power = max(power - 1, 20);
          }
          analogWrite(led_pin, power);
          delay(10);
        }
        go_fotward = !go_fotward;
      }
      delay(10);
    }
    if (millis() - pressed < 500){
      if (currentValue){
          led_state = !led_state;
      }
      if (led_state){
        analogWrite(led_pin, power);
      }
      else{
        analogWrite(led_pin, 0);
      }
    }
  }
  prevValue = currentValue;
}
