//https://github.com/adafruit/Adafruit_SH110x
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 128

// Declaration for the SH1107 (initialize with the I2C address 0x3C or 0x3D)
Adafruit_SH1107 display = Adafruit_SH1107(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Start I2C communication
  Wire.begin(26, 32);
  
  // Initialize the display
  if(!display.begin(0x3C, true)) {  // Address 0x3C or 0x3D
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.display();
  delay(2000);  // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  display.setRotation(1);//1 - with the longer dimension, 0 - with the shorter dimension 
  
  // Display initial message
  display.setTextSize(1);      
  display.setTextColor(SH110X_WHITE);  
  display.setCursor(10, 10);     
  display.println("Hello World");    
  
  display.drawFastVLine(0, 0, 64, SH110X_WHITE);
  display.drawFastHLine(0, 0, 128, SH110X_WHITE);

  display.fillRect(10,20,20,20,SH110X_WHITE);
  display.fillCircle(45,30,10,SH110X_WHITE);
  display.fillTriangle(60,40,70,20,80,40,SH110X_WHITE);

  display.drawLine(80,20,90,40,SH110X_WHITE);

  //display.invertDisplay(true);

  display.display();//writes elements on the screen
}

void loop() {
}

//Adafruit GFX is library that have graphics primitves such as lines, circles, text, etc. 



/*
// M5Stack-Atom << Board
// Arduino <<Framework
// monitor_speed = 115200 << platformio.ini
#include <Arduino.h>

const int buttonPin = 39; //BTN pin
//int a=0;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  Serial.println("hello-setup");
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  
  //Serial.print("loop");
  //Serial.println(a);
  //a+=1;

  if (buttonState == LOW) {  // The button is pressed (active low)
    Serial.println("Button pressed");
    delay(200);  // Debounce delay
  }
}

*/

