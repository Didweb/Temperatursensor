/*
Temperatura.
Termometro exterior e interior.
Con minimas y maximas.

autor: Eudard Pinuaga
<info@did-web.com>
http://github.com/Didweb

*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int sensorA0 = A0; // entrada sensor LM35DH
const int sensorA1 = A1; // entrada sensor LM35

int IntMax = 0;
int IntMin = 30;

int ExtMax = 0;
int ExtMin = 30;

int nDelay = 200;

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
  
  delay(nDelay);
  
  ExtMax = CalculaMax(celsiusA0, ExtMax);
  ExtMin = CalculaMin(celsiusA0, ExtMin);
  
  IntMax = CalculaMax(celsiusA1, IntMax);
  IntMin = CalculaMin(celsiusA1, IntMin);
  
  lcd.setCursor(0, 0);
  lcd.write("E: ");
  lcd.print(celsiusA0);
  lcd.print((char)223);
  lcd.write("C");
  lcd.write(" (");
  lcd.print(ExtMax);
  lcd.write("/");
  lcd.print(ExtMin);
  lcd.write(")");
  
  
  lcd.setCursor(0, 1);
  lcd.write("I: ");
  lcd.print(celsiusA1);
  lcd.print((char)223);
  lcd.write("C");
  lcd.write(" (");
  lcd.print(IntMax);
  lcd.write("/");
  lcd.print(IntMin);
  lcd.write(")");
}

int CalculaMax(int ValorActual, int Max){
  int result = Max;
  if(ValorActual > Max){
  result = ValorActual;
  }
  return result;

}


int CalculaMin(int ValorActual, int Min){
  int result = Min;
  if(ValorActual < Min){
  result = ValorActual;
  }
  return result;

}
