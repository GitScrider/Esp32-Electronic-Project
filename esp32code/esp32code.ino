#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Defining I2C address 
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ledPin = 5;     // Led Pin (Indicates the motor acionament)
const int buttonPin = 6;  // push button Pin
int buttonState = 0;      // variable to set the button state

// Endereço I2C do display (geralmente 0x27 ou 0x3F, verifique o seu)

void setup() {
  // Setting I2C pin for proteus simulator
  Wire.begin(1, 2);  // SDA = pin 1, SCL = pin 2
  lcd.backlight();  // Turn on the lcd backlight


  pinMode(ledPin, OUTPUT); // set the ledPin as outuput
  pinMode(buttonPin, INPUT_PULLUP); //set the buttonPin as input in internal pullup
}

void loop() {

  buttonState = digitalRead(buttonPin); //read the push button state

  if (buttonState == LOW) {
    // turn on the dc motor and dc motor led
    digitalWrite(ledPin, HIGH);
      // Exibe uma mensagem no display
    
    lcd.setCursor(0, 0);
    lcd.print("dc motor running"); //write this message on the lcd display
    
    //wait for 10seconds
    delay(10000);

    //turn off the dc motor
    digitalWrite(ledPin, LOW);
    //set display blanck
    lcd.setCursor(0, 0);
    lcd.print("");
  }
}
