


int buzzer 10;
int green 12;
int red 11;
int blue 13;

void setup() {

  Serial.begin(9600);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

float getTemp(){
  float voltage = analogRead(A0) * (5.0 / 1023.0);
  return (750*voltage)-7.5;
}

void turnLedOn(char led){
  if (char == 'r'){
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
  }
  else if (char == 'g'){
    digitalWrite(blue, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }
  else if (char == 'b'){
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
  }
  else{
    exit(1);
  }
}

void loop() {
  int temp = getTemp();
  Serial.println(voltage);
  if(temp > 21) {
    if (temp < 27){
      turnLedOn('g');
    }
    else if (temp < 50){
      turnLedOn('r');
    }
    else (temp >= 50){
      //allarme
    }
  }

  else{
    turnLedOn('b');
  }
  delay(30000);
}
