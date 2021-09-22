#include<LiquidCrystal.h>

#define long int

const int rs = 7, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const int chargePin = 8, inputPin = 1, dischargePin = 9;

 long t0;
 long t1;

 const float r = 975.0;     // charging resistance value      

void setup() {

  lcd.begin(16, 2);
  
  pinMode(chargePin, OUTPUT);
  digitalWrite(chargePin, LOW);
//  Serial.begin(9600);
}

void loop() {

  // charge capacitor
  digitalWrite(chargePin, HIGH);
  t0 = millis();

  while(analogRead(inputPin) < 648) {
    
  }
  
  t1 = millis();

   int T = t1 - t0;

  // print

  float C = (float)T * 1000.0f / r;     // in uF 
  lcd.setCursor(0, 0);
  lcd.print(C);
  lcd.print(" uF");

//Serial.println(C);
//Serial.println(r);
//Serial.println(T);

  
  // discharge the capacitor

  digitalWrite(chargePin, LOW);

  pinMode(dischargePin, OUTPUT);
  digitalWrite(dischargePin, LOW);

  while(analogRead(inputPin) > 0) {
    
  }

  pinMode(dischargePin, INPUT);
  
}
