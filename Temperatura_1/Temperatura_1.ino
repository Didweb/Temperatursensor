/*
Temperatura.
Termometro exterior e interior.

autor: Eduard Pinuaga
<info@did-web.com>
http://github.com/Didweb

*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int sensorA0 = A0; // entrada sensor LM35DH
const int sensorA1 = A1; // entrada sensor LM35


long mVA0 = 0; 
long mVA1 = 0;

long celsiusA0 = 0;
long celsiusA1 = 0;

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  

}

void loop(){
 

  mVA0 = (analogRead(sensorA0) * 5000L) / 1023;
  mVA1   = (analogRead(sensorA1) * 5000L) / 1023;
  
  celsiusA0 = mVA0 / 10;
  celsiusA1 = mVA1 / 10;

  
  
  Serial.print("A0: ");
  Serial.print(celsiusA0);
  Serial.println(" C");
  
  Serial.print("A1: ");
  Serial.print(celsiusA1);
  Serial.println(" C");
  
  delay(200);
  lcd.setCursor(0, 0);
  lcd.write("Exterior: ");
  lcd.print(celsiusA0);
  lcd.write(" C");
  
  
  lcd.setCursor(0, 1);
  lcd.write("Interior: ");
  lcd.print(celsiusA1);
  lcd.write(" C");
}
