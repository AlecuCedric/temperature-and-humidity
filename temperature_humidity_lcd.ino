#include "dht.h"
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define dht_apin A0 // Analog Pin sensor is connected to
dht DHT;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  //read sensor data
  DHT.read11(dht_apin);

  //output temperature data on the display
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(0, 1);
  lcd.print(DHT.temperature);
  lcd.print("C");

  //Wait 5 seconds before displaying the humidity
  delay(5000);
  lcd.clear();

  //output humidity data on the display
  lcd.setCursor(0, 0);
  lcd.print("Humidity:");
  lcd.setCursor(0, 1);
  lcd.print(DHT.humidity);
  lcd.print("%");

  //Wait 5 seconds before accessing sensor again.
  delay(5000);
}

