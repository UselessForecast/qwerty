#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
LiquidCrystal_I2C lcd(0x27, 20, 4);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int A = 12;
int B = 13;
int counter = 0;
int aState;
int aLastState;
void setup(){
  Serial.begin(9600);
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  aLastState = digitalRead(A);
  sensors.begin();
  lcd.begin();
  lcd.backlight();
}
void loop(){
  lcd.setCursor(0,0);
  lcd.print("Counter");
  lcd.setCursor(0,2);
  lcd.print("Tmp:");
  lcd.setCursor(0,3);
  lcd.print(sensors.getTempCByIndex(0));
  aState = digitalRead(A);
  if (aState != aLastState){
    if (digitalRead(B)!= aState){
      counter ++;
    }else{ 
      counter --;
    }
    lcd.setCursor(0,1);
    lcd.print(counter);
  }
  aLastState = aState;
}