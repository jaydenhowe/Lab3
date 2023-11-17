/* The goal of this program is to display the voltage using an LCD
bringing the voltage higher with a potentiometer will bring the number
displayed up. The theme of this program is Analog Input and Digital Output
*/

// include the library code: 
#include <LiquidCrystal.h> 


// initialize the library by associating any needed LCD interface pin 
// with the arduino pin number it is connected to 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);    // defines which arduino pin is connected to which LCD pin

void setup() { 
  // put your setup code here, to run once:

  lcd.begin(16, 2);    // defines the interface of the LCD screen (width and height)
} 

void loop() { 
  // put your main code here, to run repeatedly: 

  int pinvalue = analogRead(A0);   //reads pin A0 and refers it to "pinvalue"
  float V = (5.0/1023.0) * pinvalue ;   // equation of y= mx+b
  lcd.setCursor(0, 0);               // sets the start point of the LCD to 0, 0
  lcd.print("Voltage= ");       // the LCD prints Voltage=
  lcd.print(V);                   // the LCD prints the value of V
  delay(1);                     //delays it by 1 millisecond

} 
