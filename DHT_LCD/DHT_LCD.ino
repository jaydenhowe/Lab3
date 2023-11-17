/*  the goal of thid program is to display the temperature and humidity
  on the LCD. the theme of this program is digital input, digital output
  */


#include <DHT.h>              //includes the dht library
#include <LiquidCrystal.h>    // includes the liquid crystal library (LCD)
#define Type DHT11             //defines the type of DHT we are using
int dhtpin = 8;           //sets pin dhtpin to pin 8
DHT HT(dhtpin, Type);           //names the object and defines it to which pin and which type
float humidity;        //floats the integer humidity
float temp;           //floats the integer temp
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   //sets an integer to each pin used
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                   // sets the arduino pin to the LCD pin



void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);       //sets up the LCD's columns and rows (16 and 2)
  HT.begin();          //start the object (DHT)

}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(0, 0);          //sets the cursor of the LCD to column 0 and line 0
  humidity = HT.readHumidity();         //reads the humidity
  temp = HT.readTemperature();       //reads the temperature

  lcd.print("humidity: ");       //prints out on the LCD "humidity:"
  lcd.print(humidity);         //prints out on the LCD the value of the humidity
  lcd.print("%");            //prints out on the LCD "%"

  lcd.setCursor(0,1);            //sets the cursor of the LCD to column 0 and line 1

  lcd.print("temp: ");            //prints out on the LCD "temp:"
  lcd.print(temp);             //prints out on the LCD the value of the temperature
  lcd.print("C");               //prints out on the LCD "C"

  delay(15);             //delays it by 15 milliseconds

}
