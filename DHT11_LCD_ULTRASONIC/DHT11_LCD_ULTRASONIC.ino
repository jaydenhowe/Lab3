/* the goal of this program is to display the temperature and humidity
  on an LCD when the pushbutton isn't pressed and for the LCD to display the
  distance the ultrasonic is reading when the button is pressed.
  */

#include <DHT.h>              //includes the dht library
#include <LiquidCrystal.h>    // includes the liquid crystal library (LCD)
#define Type DHT11             //defines the type of DHT we are using
int dhtpin = 8;           //sets dhtpin to pin 8
DHT HT(dhtpin, Type);           //names the object and defines it to which pin and which type
float humidity;        //floats the integer humidity
float temp;           //floats the integer temp
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   //sets an integer to each pin used
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                   // sets the arduino pin to the LCD pin
int trig = 9;                               //sets trig to pin 9
int echo = 13;                              //sets echo to pin 13
int pushbutton = 6;                   //sets pushbutton to pin 6

void setup() {
  // put your setup code here, to run once:

  lcd.begin(16, 2);       //sets up the LCD's columns and rows (16 and 2)
  HT.begin();          //start the object (DHT)
  pinMode(trig, OUTPUT);      //sets pin 9 to an output
  pinMode(echo, INPUT);        //sets pin 13 to an input
  pinMode(pushbutton, INPUT);      //sets pin 6 to an input
}

void loop() {
  // put your main code here, to run repeatedly:
    
  humidity = HT.readHumidity();         //reads the humidity
  temp = HT.readTemperature();       //reads the temperature
  int buttonstate = digitalRead(pushbutton);       //reads pin 6 and refers it to buttonstate
  digitalWrite(trig, LOW);        //writes pin 9 to LOW
  delayMicroseconds(10);        //delays it by 10 microseconds       
  digitalWrite(trig, HIGH);        //writes pin 9 to HIGH
  delayMicroseconds(10);        //delays it by 10 microseconds
  digitalWrite(trig, LOW);        //writes pin 9 to LOW
float duration = pulseIn(echo, HIGH);         // floats "duration" and sets pin 13 to HIGH
float distance = (duration / 2) * 0.0343;       //floats "distance" and creates equation for distance compared to duration

if (buttonstate == true) {
if (distance >=400 || distance <=2) {
  lcd.setCursor(0, 0);                   //sets the cursor of the LCD to column 0 and line 0                
  lcd.println("out of range");            //prints out "out of range" on the LCD
  delay(500);             //delays it by 500 milliseconds
    lcd.clear();        //clears the LCD

}  else {
  lcd.print("distance= ");      //prints out "distance= " on the LCD
  lcd.print(distance);         //prints out the value of the distance on the LCD
  lcd.print("cm");            //prints out "cm" on the LCD
  delay(500);             //delays it by 500 milliseconds
    lcd.clear();        //clears the LCD
} }else  {
  lcd.setCursor(0, 0);            //sets the cursor of the LCD to column 0 and line 0 
  lcd.print("humidity: ");       //prints out on the LCD "humidity:"
  lcd.print(humidity);         //prints out on the LCD the value of the humidity
  lcd.print("%");            //prints out on the LCD "%"

  lcd.setCursor(0,1);            //sets the cursor of the LCD to column 0 and line 1
  lcd.print("temp: ");            //prints out on the LCD "temp:"
  lcd.print(temp);             //prints out on the LCD the value of the temperature
  lcd.print("C");             //prints out on the LCD "C"
  delay(500);             //delays it by 15 milliseconds
    lcd.clear();        //clears the LCD
}
}
