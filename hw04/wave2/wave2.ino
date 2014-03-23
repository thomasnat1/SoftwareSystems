/*
  

 Author: Allen Downey 
 
 Based on http://arduino.cc/en/Tutorial/AnalogInput
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 License: Public Domain
 
 */
 
#include "Waveforms.h"

#define oneHzSample 1000000/maxSamplesNum  // sample for the 1Hz signal expressed in microseconds 

const int button0 = 2, button1 = 3;
volatile int wave0 = 0, wave1 = 0;

int i = 0;
int sample;
 
 
int ledPin = 5;       // select the pin for the LED
int buttonPin1 = 2;
int buttonPin2 = 3;

void setup() {
  cli();//stop interrupts
  int FREQ = 15000;

  Serial.begin(9600);
  
  pinMode(buttonPin1, INPUT_PULLUP);  
  pinMode(buttonPin2, INPUT_PULLUP);  

  pinMode(ledPin, OUTPUT);
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  
  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624/FREQ;// = (16*10^6) / (1*1024/FREQ) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  
  attachInterrupt(1, changeWave, RISING);  // Interrupt attached to the button connected to pin 2
  
  sei();//allow interrupts
}

int waveSelected = 0;

void changeWave(){
  waveSelected++;
  if(waveSelected == 4){
    waveSelected = 0;
  }
}  

int low = 36;
int high = 255;
int stride = 5;
int counter = low;
int wavePace = 0;

ISR(TIMER1_COMPA_vect){//timer1 interrupt
  int button1 = digitalRead(buttonPin1);
//  Serial.println(button1);
  if (button1) return;
  
//  counter += stride;
//  if (counter > high) {
//    counter = low;
//    Serial.println(counter);
//  }
  
  // write to the digital pins  
  writeByte(waveformsTable[waveSelected][wavePace]);
  wavePace++;
  if(wavePace == maxSamplesNum){
    wavePace = 0;
  }
}

  

void writeByte(int x) {
  x = ~x;
  PORTD = (PORTD&B00111111)|(x<<6);
  PORTB = (x>>2)&B00111111;
}

void loop() {
  
}
