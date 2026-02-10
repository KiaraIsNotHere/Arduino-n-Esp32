int led1 = 7;
int led2 = 8;
int butt = 3;
int poten = A0;
int sens = A5;
int buzz = 13;

int potenValue = 0;




void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(butt,INPUT);
  pinMode(sens,INPUT);
  pinMode(poten,INPUT);

  digitalWrite(butt,HIGH);
}
void suara(int speed, int freq){
  tone(buzz,freq);
  delay(speed);
  noTone(buzz);
}

void leded(int lft,int rgt){
  digitalWrite(led1,lft);
  digitalWrite(led2,rgt);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pht = analogRead(sens);
  int potenValue = analogRead(poten);
  int bted = digitalRead(butt);
  ledBrightness = map(potenValue, 0, 1023, 0, 255);

  if (bted == 0 && pht > 150){
    Serial.println(bted);
    
    leded(1,0);
    suara(500,1000);
  }else if (pht < 100 && bted == 1){
    Serial.println(pht);
    leded(0,1);
    suara(250,100);
    
  }else if (pht < 100 && bted == 0){
    Serial.println(pht);
    suara(1000,1000);
    leded(1,1);
    delay(1000);
    leded(0,0);
    delay(1000);
  }else{
    leded(0,0);
  }
  
  
  
}
