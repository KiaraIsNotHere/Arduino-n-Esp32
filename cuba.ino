#include <Wire.h>               // I2C communication library
#include <LiquidCrystal_I2C.h>  // LCD I2C library

const int col = 16;
const int row = 2;
// Create LCD object with I2C address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, col, row);
// Pin for the photoresistor (LDR) connected to an analog pin
const int LDR_PIN = A0;

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(5, 0);
  lcd.print("NIGGER");
  lcd.setCursor(4, 1);
  lcd.print("DETECTOR");
  delay(2000);
  lcd.clear();

  // Initialize serial monitor for debugging
  Serial.begin(9600);


  
}
int pos = 0;

void loop() {
  // Read LDR value (0 - 1023)
  int ldrValue = analogRead(LDR_PIN);
  Serial.println(ldrValue);
  // Display status based on threshold
  lcd.setCursor(0, 1);
  if (ldrValue < 50) {
    lcd.setCursor(5, 0);
    lcd.print("NIGGER");
    lcd.setCursor(4, 1);
    lcd.print("DETECTED");
    delay(500);
    lcd.setCursor(5, 0);
    lcd.print("NIGGER");
    lcd.setCursor(4, 1);
    lcd.print("DETECTED");

    delay(500);
    lcd.clear();
  }else{
    lcd.setCursor(2,0);
    lcd.print(" NO NIGGER ");
    lcd.setCursor(2,1);
    lcd.print("AROUND HERE");

    delay(500);
    lcd.clear();
  }
}