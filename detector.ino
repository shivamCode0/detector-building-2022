// #include "HX711.h"
// #define DOUT  3
// #define CLK  2
// #define voltPin A5

// #define ledpin1 11
// #define ledpin2 12
// #define ledpin3 13

// HX711 scale;

// float weight; 
// float calibration_factor = 452.12; 


// // 1. HX711 circuit wiring
// // const int LOADCELL_DOUT_PIN = 2;
// // const int LOADCELL_SCK_PIN = 3;

// // 2. Adjustment settings
// const long LOADCELL_OFFSET = 50682624;
// const long LOADCELL_DIVIDER = 5895655;

// // 3. Initialize library
// // scale.set_scale(LOADCELL_DIVIDER);
// // scale.set_offset(LOADCELL_OFFSET);

// void setup() {

//   pinMode(ledpin1, OUTPUT);
//   pinMode(ledpin2, OUTPUT);
//   pinMode(ledpin3, OUTPUT);
//   pinMode(voltPin, INPUT);

  

//   Serial.begin(9600);
//   Serial.println("HX711 calibration sketch");
//   Serial.println("Remove all weight from scale");
//   Serial.println("After readings begin, place known weight on scale");
//   Serial.println("Press + or a to increase calibration factor");
//   Serial.println("Press - or z to decrease calibration factor");

// scale.begin(DOUT, CLK);
//   scale.set_scale();
//   scale.tare(); 
//   long zero_factor = scale.read_average(); 
//   Serial.print("Zero factor: "); 
//   Serial.println(zero_factor);

// }
// void loop() {
// digitalWrite(ledpin1, HIGH);
//   digitalWrite(ledpin2, LOW);
//   digitalWrite(ledpin3, HIGH);

// }
// void loop1() {
//   scale.set_scale(calibration_factor); 
//   Serial.print("Reading: ");
//   weight = scale.get_units(5); 
//   Serial.print("Gram:");
//   float x = weight * -1;
//   Serial.print(x); 
//   Serial.print(" g");
//   Serial.print(" calibration_factor: ");
//   Serial.print(calibration_factor);
//   Serial.print(" Voltage: ");
//   Serial.print(analogRead(voltPin)* (x/1000));
//   Serial.println();
//   if (x >= 30 && x < 250) {
//     digitalWrite(ledpin1, HIGH);
//     digitalWrite(ledpin2, LOW);
//     digitalWrite(ledpin3, LOW);
//   }
//   else if (x >=250 && x < 500) {
//     digitalWrite(ledpin1, LOW);
//     digitalWrite(ledpin2, HIGH);
//     digitalWrite(ledpin3, LOW);
//   }
//   else if (x >= 500 && x < 1001) {
//     digitalWrite(ledpin1, LOW);
//     digitalWrite(ledpin2, LOW);
//     digitalWrite(ledpin3, HIGH);
//   }
//   if(Serial.available())
//   {
//     char temp = Serial.read();
//     if(temp == '+' || temp == 'a')
//       calibration_factor += .01;
//     else if(temp == '-' || temp == 'z')
//       calibration_factor -= .01; 
//   }
// }

/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}