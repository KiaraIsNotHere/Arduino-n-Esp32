#define led2 4
#define led4 5
#define button 3
void setup() {
  Serial.begin(9600); //Monitoting log input
  pinMode(button,INPUT);
  // put your setup code here, to run once:
  pinMode(led2,OUTPUT);
  pinMode(led4,OUTPUT);
  

  digitalWrite(button,HIGH);
}

void speedMode(int option){
  if (option == 1) {
    digitalWrite(led2,HIGH);
    digitalWrite(led4,HIGH);
    delay(500);

    digitalWrite(led2,LOW);
    digitalWrite(led4,LOW);
    delay(500);
  }else{
    digitalWrite(led2,HIGH);
    delay(500);
    digitalWrite(led2,LOW);
    digitalWrite(led4,HIGH);
    delay(500);
    digitalWrite(led4,LOW);
  }
}


void loop(){
  // put your main code here, to run repeatedly:
  int isPressed = digitalRead(button);
  if (isPressed == 0) {
    speedMode(0);
  }else{
    speedMode(1);
  }
}

