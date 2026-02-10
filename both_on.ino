#define led1 4
#define led2 5
#define button 3

void setup() {
  Serial.begin(9600);
  pinMode(button,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);

  digitalWrite(button,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  int pencet = digitalRead(button);

  if (pencet == 0){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);

  }else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);

  }
}
