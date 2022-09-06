# Arduino Soil Humidity Reader

Welcome to my version of an Arduino Soil Humidity Reader! 

The main loop of this program maps the analog moisture reading to an average percentage based on ten readings from the soil humidity sensor. The average percentage is printed onto the LCD screen. Then, conditionals determine whether to light up the red, green or blue LED based on the percentage value. 

- Red LED indicates that the soil humidity percentage is too low for the plant
- Green LED indicates that the soil humidity percentage is in a healthy range for the plant
- Blue LED indicates that the soil humidity percentage is too high for the plant

The conditional ranges should be customized to suit the needs of your specific plant, so that the LEDs indicate when (and how much) your plant needs to be watered.
