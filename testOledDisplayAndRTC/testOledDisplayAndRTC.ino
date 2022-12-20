// библиотеки для работы с OLED экраном Arduino IDE
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include <virtuabotixRTC.h>

// Creation of the Real Time Clock Object
virtuabotixRTC myRTC(4, 3, 2);
Adafruit_SSD1306 display(128, 64, &Wire, 4); // указываем размер экрана в пикселях

String time;

void setup() {
  // Set the current date, and time in the following format:
  // seconds, minutes, hours, day of the week, day of the month, month, year
  // myRTC.setDS1302Time(10, 15, 10, 2, 20, 12, 2022);
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // указываем адрес устройства на шине
  display.clearDisplay();
  display.setTextSize(2, 2); // указываем размер шрифта
  display.setTextColor(SSD1306_WHITE); // указываем цвет надписи

  display.setCursor(25, 24);
  display.println("ARDUINO");
  display.display();
  delay(3000);
  display.clearDisplay(); // очищаем экран
}

void loop() {
  time = "";
  time += myRTC.hours;
  time += ':';
  time += myRTC.minutes;

  myRTC.updateTime();

  display.setTextSize(3); // указываем размер шрифта
  display.setTextColor(SSD1306_WHITE); // указываем цвет надписи

  display.setCursor(22,30);
  display.println(time);
  display.display();
  delay(100);
  display.clearDisplay(); // очищаем экран

}