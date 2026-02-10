#define led2 2
#define led3 3
#define butt 6
#define bzz 7
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(bzz,OUTPUT);
  pinMode(butt,INPUT);

  digitalWrite(butt,HIGH);
}

void bunyi(int speeds,int freq){
  tone(bzz,freq);
  delay(speeds);
  noTone(bzz);
}

void loop() {
  // put your main code here, to run repeatedly:
  int butted = digitalRead(butt);
  if (butted == 0){
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    bunyi(200,5000);
    delay(100);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    bunyi(200,5000);
    delay(100);
  }else{
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    delay(1000);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    delay(1000);
  }
}
