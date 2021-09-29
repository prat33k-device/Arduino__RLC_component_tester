
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;

// ohm meter

const int resistanceRead = 0;    // A0
float R ;
float Rknown = 1.0;        // int Kohms reference resistance

// Cmeter


const int chargePin = 8, inputPin = 1, dischargePin = 9;

 long t0;
 long t1;

 const float r = 975.0;     // charging resistance value      



LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define float double

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.

  pinMode(chargePin, OUTPUT);
  digitalWrite(chargePin, LOW);
}

void loop() {


  //resistance

  int raw = analogRead(resistanceRead);
  float Vout = float(raw) * 5.0 / 1023.0; 
  float Vratio = 5.0 / Vout;
  R = Rknown / (Vratio - 1.0);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("R = ");
  if(int(R) > 1) {
    lcd.print(R);
    lcd.print(" Kohms");
  } else {
    lcd.print(R * 1000);
    lcd.print(" ohms"); 
  }

  

  // capacitance

  digitalWrite(chargePin, HIGH);
  t0 = millis();

  while(analogRead(inputPin) < 648) {
    
  }
  
  t1 = millis();

   int T = t1 - t0;

  // print

  float C = (float)T * 1000.0f / r;     // in uF 
  lcd.setCursor(0, 1);
  lcd.print("C = ");
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



   delay(1000);

  
}
