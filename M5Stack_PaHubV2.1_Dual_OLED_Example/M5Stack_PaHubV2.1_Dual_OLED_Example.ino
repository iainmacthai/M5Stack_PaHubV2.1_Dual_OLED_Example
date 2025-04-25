/*  M5Stack_PaHubV2_1_Dual_OLED_Example.ino
* ESP32-CYD (ESP32 Dev Module)
* M5Stack PaHub V2.1 i2c Multiplexer (TCA9548A) 6CH Mux
* Unable to get working with M5 Libraries/Examples so used Rxample from this libarary
* https://github.com/WifWaf/TCA9548A
* https://github.com/WifWaf/TCA9548A/blob/master/examples/BasicUsage/BasicUsage.ino
* 
* TCA9548A V1.1.3
* M5UnitOLED from M5GFX Library V0.2.6
* Arduino IDE 2.3.2
* Boards Manager - ESP32 by Espressif V3.1.0
* Iain MacMillan
* 26/04/2025
*/

#include "TCA9548A.h"
#include <M5UnitOLED.h>
TCA9548A I2CMux;                  // Address can be passed into the constructor
M5UnitOLED display(27, 22, 400000);
void setup() {
  Serial.begin(115200);

  Wire.setPins(27, 22);           // ESP32 users, use setPins(sda, scl) if customised, *before* passing Wire to the library (the line below).  
  I2CMux.begin(Wire);             // Wire instance is passed to the library

  I2CMux.closeAll();              // Set a base state which we know (also the default state on power on)
}

void loop() {
  // OLED 1 Display
  I2CMux.openChannel(0);          // Channel O / Port 0
  display.init();
  display.setRotation(3); 
  display.setFont(&fonts::Font2);
  display.setTextSize(0);
  display.startWrite();
  display.clear();
  display.setCursor(0, 0);
  display.print("I Am Channel 0");
  display.endWrite();
  delay(750); // Display On OLED
  display.startWrite();
  display.clear();
  display.setCursor(0, 0);
  display.print("I like apples");
  display.endWrite();
  delay(750); // Display On OLED
  I2CMux.closeChannel(0); 

  // OLED 2 Display                 // Channel 1 / Port 1
  I2CMux.openChannel(1);
  display.init();
  display.setRotation(3); 
  display.setFont(&fonts::Font2);
  display.setTextSize(0);
  display.startWrite();
  display.clear();
  display.setCursor(0, 0);
  display.print("I Am Channel 1");
  display.endWrite();
  delay(750); // Display On OLED
  display.startWrite();
  display.clear();
  display.setCursor(0, 0);
  display.print("I like pears");
  display.endWrite();
  delay(750); // Display On OLED
  I2CMux.closeChannel(1); 

  delay(50);
  I2CMux.closeAll();
}
