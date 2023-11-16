#include "HX711.h"
#include <Arduino.h>
#define DOUT 3
#define CLK 2
#define voltPin A5

#define ledpin1 11
#define ledpin2 12
#define ledpin3 13

HX711 scale;

float weight;
float calibration_factor = 452.12;

void setup() {
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(ledpin3, OUTPUT);
  pinMode(voltPin, INPUT);

  Serial.begin(9600);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println(
      "Press a (.01) or b (.1) or c (1) to increase calibration factor");
  Serial.println(
      "Press d (.01) or e (.1) or f (1) to decrease calibration factor");

  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare();
  long zero_factor = scale.read_average();
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);
}

void loop() {
  scale.set_scale(calibration_factor);
  // Serial.print("Reading: ");
  weight = scale.get_units(5);
  // Serial.print("Gram:");
  Serial.print(weight);
  Serial.print(", ");
  // Serial.print(vot);
  // Serial.print("");
  // Serial.print(" g");
  // Serial.print(" calibration_factor: ");
  // Serial.print(calibration_factor);
  // Serial.print(" Voltage: ");
  Serial.print(analogRead(voltPin) * (1.0f / 1000.0f) * 0.01f * weight);
  Serial.println();
  if (weight >= 19 && weight < 200) {
    digitalWrite(ledpin1, LOW);
    digitalWrite(ledpin2, LOW);
    digitalWrite(ledpin3, HIGH);
  } else if (weight >= 200 && weight < 400) {
    digitalWrite(ledpin1, LOW);
    digitalWrite(ledpin2, HIGH);
    digitalWrite(ledpin3, LOW);
  } else if (weight >= 400 && weight < 1010) {
    digitalWrite(ledpin1, HIGH);
    digitalWrite(ledpin2, LOW);
    digitalWrite(ledpin3, LOW);
  } else {
    digitalWrite(ledpin1, LOW);
    digitalWrite(ledpin2, LOW);
    digitalWrite(ledpin3, LOW);
  }
  if (Serial.available()) {
    char temp = Serial.read();
    if (temp == 'a')
      calibration_factor += .01;
    if (temp == 'b')
      calibration_factor += .1;
    else if (temp == 'c')
      calibration_factor += 1;
    else if (temp == 'd')
      calibration_factor -= .01;
    else if (temp == 'e')
      calibration_factor -= .1;
    else if (temp == 'f')
      calibration_factor -= 1;
  }
}

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