
/*Thanks. Remember to visit my Youtube channel
  If you don't whant to Serial print the valeus just delete the serial. print lines
  and leave just the LCD print ones.
  I've used a i2c LCD screen module. 
*/
//LCD config
#include <LiquidCrystal.h>

const int rs = 7, en = 6, d4 = 2, d5 = 3, d6 = 4, d7 = 5;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


//13 is the input to the circuit (connects to 150ohm resistor), 11 is the comparator/op-amp output.
double pulse, frequency, capacitance, inductance;
void setup(){
 
  Serial.begin(9600);
  pinMode(11, INPUT);
  pinMode(13, OUTPUT);
  Serial.println("Why hello!");
  delay(200);
}
void loop(){
  digitalWrite(13, HIGH);
  delay(5);//give some time to charge inductor.
  digitalWrite(13,LOW);
  delayMicroseconds(100); //make sure resination is measured
  pulse = pulseIn(11,HIGH,5000);//returns 0 if timeout
  if(pulse > 0.1){ //if a timeout did not occur and it took a reading:
    
    
  
  capacitance = 2.E-6; // - insert value here
  
  
  frequency = 1.E6/(2*pulse);
  inductance = 1./(capacitance*frequency*frequency*4.*3.14159*3.14159);//one of my profs told me just do squares like this
  inductance *= 1E6; //note that this is the same as saying inductance = inductance*1E6

  //Serial print
  Serial.print("High for uS:");
  Serial.print( pulse );
  Serial.print("\tfrequency Hz:");
  Serial.print( frequency );
  Serial.print("\tinductance uH:");
  Serial.println( inductance );
  delay(10);

  //LCD print
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("L = ");
//  lcd.setCursor(0, 1); 
  lcd.print(inductance);
  lcd.setCursor(14,0); 
  lcd.print("uH");          
  delay(10);
  }
}
