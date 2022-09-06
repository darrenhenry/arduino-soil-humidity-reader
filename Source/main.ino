// Darren Henry
// Arduino Soil Humidity Reader

// Library utilized for LCD functions
#include <LiquidCrystal.h>

// Setting constant pin value for soil moisture sensor
const int SENSOR_PIN = A5;

// Setting constant pin values for LEDs
const int RED_LED_PIN = 8;
const int GREEN_LED_PIN = 9;
const int BLUE_LED_PIN = 10;

// Setting constant pin values for LCD
const int RS_PIN = 2;
const int E_PIN = 3;
const int D4_PIN = 4;
const int D5_PIN = 5;
const int D6_PIN = 6;
const int D7_PIN = 7;

// Creating LCD object
LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

// Initializing variables for the soil humidity sensor values
int sensorValue;
int moisturePercentage;
int averagePercentage;

void setup() {
  
  // Setting pinModes for LEDs as outputs
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  delay(2000);

  // Initializing serial monitor
  Serial.begin(9600);

  // Initializing LCD Display
  lcd.begin(16, 2);
}

void loop() {

  // Mapping moisture to percentage based on average of ten sensor readings
  int total = 0;
  for(int i = 0; i < 10; i++) {
    sensorValue = analogRead(SENSOR_PIN);
    moisturePercentage = map(sensorValue, 1023, 0, 0, 100);
    total += moisturePercentage;
    }
  averagePercentage = total / 10;

  // Turning on the red LED if the soil humidity is less than desired and the plant needs water
  if (averagePercentage == 0) {
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    }

  // Turning on the green LED if the soil humidity is in a healthy percentage range for the plant
  if (averagePercentage >= 0 && moisturePercentage <= 30) {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    }

  // Turning on the blue LED if the soil humidity is greater than desired and the plant has too much water
  if (averagePercentage > 30) {
    digitalWrite(BLUE_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    }

  // Printing to serial monitor
  Serial.println(averagePercentage);

  lcd.setCursor(0, 0);
  lcd.print("Soil Humidity:");
  lcd.setCursor(0, 1);
  lcd.print(String(averagePercentage) + " %");

  delay(1000);
}
  
