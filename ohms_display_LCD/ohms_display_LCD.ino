/*  the goal of this program is to display on an LCD, the ohms of a unknown Resistor.
  the theme of this program is analog input and digital output
  */

// include the library code: 
#include <LiquidCrystal.h> 

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;    //sets an integer to each pin used
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                     // sets the arduino pin to the LCD pin

byte resistance[8] = {        //creates the symbol for ohms in a byte form

  B00000, 
  B00000, 
  B01110, 
  B10001, 
  B10001, 
  B10001, 
  B01010, 
  B11011 

}; 

void setup() { 
  lcd.begin(16, 2);                 //sets up the LCD's columns and rows (16 and 2)
  lcd.createChar(0, resistance);   //creates the ohms character
  lcd.write(byte(0));             //write the ohms character as byte(0)
} 
void loop() { 
  // put your main code here, to run repeatedly: 
  int pinvalue = analogRead(A0);                  //reads pin A0 and defines it as pinvalue
  float V = (5.0/1023.0) * pinvalue ;             //floats V and creates an equation (mx+b)
  float current = ((5.0 - V)/1000.0);             //floats current and creates the equation of ohms law
  float ohms = (V/current);                      //floats ohms and creates the equation to find Resistance
  lcd.setCursor(0, 0);                          //sets the cursor of the LCD to column 0 and line 0
  lcd.print("R= ");                           //prints out "R= ") on the LCD
  lcd.print(ohms);                            //prints out the value of ohms
  lcd.write(byte(0));                        //prints out/writes the ohms symbol
  lcd.clear();                               //clears the LCD screen
  delay(1000);                               //delays it by 1 second
} 