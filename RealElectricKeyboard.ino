#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 Altered by: Brandon Contino
   2/22/2015
   Quick Code written for the Series workshop. This code allows the
   Arduino Uno to become a makeshift electric keyboard by using
   capacitive touch sensing and piezo buzzers.
   Limitations: Can only play one note at a time and for a preset amount 
               of time. Requires user to "calibrate" their touch
               sensors.   
   Easy Alterations: 
             speakerPin
             noteDuration
             note
             calib
    
 note 	frequency
  c     262 Hz
  d     294 Hz
  e     330 Hz
  f     349 Hz
  g     392 Hz
  a     440 Hz
  b     494 Hz
  C     523 Hz
  
  It does not seem to be very accurate with this
  */
 
//Initializing Global Variables 
  int note1 = 262;  //Change to change note 1
  int note2 = 330;   //Change to change note 2
  int note3 = 392;   //Change to change note 3
  int note4 = 494;   //Change to change note 4
  int note5 = 440;   //Change to change note 5
  int speakerPin = 11;  //Pin # that hooks up to speaker
  int noteDuration = 150; //Controls the duration of each note
  int calib = 200; //Use to calibrate sensor

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 1M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 1M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    long total2 =  cs_4_6.capacitiveSensor(30);
    long total3 =  cs_4_8.capacitiveSensor(30);

    //Serial.print(millis() - start);        // check on performance in milliseconds
    //Serial.print("\t");                    // tab character for debug windown spacing

    if(total1 > calib)
    {
      tone(speakerPin,note1,noteDuration);
    }
    if(total2 > calib)
    {
      tone(speakerPin,note2,noteDuration);
    }
    if(total3 > calib)
    {
      tone(speakerPin,note3,noteDuration);  
    }
    Serial.print(total1);                  // print sensor output 1
    Serial.println("\t");
    Serial.print(total2);                  // print sensor output 2
    Serial.print("\t");
    Serial.println(total3);                // print sensor output 3

    //delay(10);                             // arbitrary delay to limit data to serial port 
}
