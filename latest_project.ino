#include <Servo.h>
int redLed = 8;
int greenLed = 9;
int buzz = 2;
int lightsens = A5;
int butt = 4;


int pos = 0;

Servo thisServo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(A5,INPUT);
  pinMode(butt,INPUT);

  thisServo.attach(7);

  digitalWrite(butt,HIGH);
}

void suara(int speed,int freq){
  tone(buzz,freq);
  delay(speed);
  noTone(buzz);
}

void bothled(int speed){
  digitalWrite(greenLed,HIGH);
  digitalWrite(redLed,HIGH);
  delay(speed);
  digitalWrite(greenLed,LOW);
  digitalWrite(redLed,LOW);
  delay(speed);
}

void servo(int speed){
  for (pos = 0; pos <= 90; pos+= 1){
    thisServo.write(pos);
    delay(speed);
  }
  for (pos = 90; pos >= 0; pos -= 1){
    thisServo.write(pos);
    delay(speed);
  }
} 

void loop() {
  // put your main code here, to run repeatedly:
  int sens_value = analogRead(lightsens);
  int butted = digitalRead(butt);

  if (butted == 0){
    bothled(100);
    suara(100,500);
  }else if (sens_value < 150){
    Serial.println(sens_value);
    bothled(500);
    suara(500,1000);
    servo(10);
  }else{
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
  }

}
