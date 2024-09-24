#include <LiquidCrystal_I2C.h>
#include "dht.h"

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display


#define dht_apin A0 // Analog Pin sensor is connected to
dht DHT;

void setup() {
  lcd.init();         // initialize the lcd
  lcd.backlight();    // Turn on the LCD screen backlight
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

