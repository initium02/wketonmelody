/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

int greenPin = 6;
int redPin = 9;
int bluePin = 5;
int counter = 0;//狀態切換


// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_E5, NOTE_C5, NOTE_E5, 
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_F5, 
  NOTE_E5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_G5,
  NOTE_F5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5,
  NOTE_G5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5,
  NOTE_A5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_B5,
  NOTE_B5, NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_C6,
  NOTE_B5, NOTE_AS5, NOTE_A5, NOTE_F5, NOTE_B5, NOTE_G5,  NOTE_C6,
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
3, 5, 3, 5, 3, 3, 2,
3, 5, 6, 6, 6, 6, 1,
3, 5, 2, 4, 3, 3, 2,
3, 5, 6, 6, 6, 6, 1,
3, 5, 6, 6, 6, 6, 1,
3, 5, 6, 6, 6, 6, 1,
3, 5, 6, 6, 6, 6, 1,
5, 5, 3, 3, 3, 3, 1,
};

void setup() {
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 100; thisNote++) {
    
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    analogWrite(greenPin,NOTE_D2+thisNote*50);
    analogWrite(redPin,NOTE_E2+thisNote*30);
    analogWrite(bluePin,NOTE_FS2+thisNote*60);

    int pauseBetweenNotes = noteDuration * 2.00;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
    analogWrite(greenPin,0);
    analogWrite(redPin,0);
    analogWrite(bluePin,0);
  }

}

void loop() {
 
}

