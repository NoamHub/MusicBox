#include "Tone.h"
#include "BuzzController.h"
#include "Melody.h"
#include "Drums.h"
#include "Bass.h"

const int buzz1Pin = 7;
const int buzz2Pin = 8;
const int ledPin = 13;
const int buttonPin = 2;

const int led1Pin = 9;
const int led2Pin = 10;
const int led3Pin = 11;
const int led4Pin = 12;
const int ledStripPin = 3;


Tone Buz1;
Tone Buz2;

void Error(int T)
{
  Buz1.stop();
  Buz2.stop();
  while (1)
  {
    static bool ledStatus = false;
    ledStatus = !ledStatus;
    digitalWrite(ledPin, ledStatus);
    delay(T);
  }
}

void bassLedCallback()
{
  static bool state = false;
  digitalWrite(led1Pin, state);
  state = !state;
  digitalWrite(led2Pin, state);
}

void melodyLedCallback()
{
  static bool state = false;
  digitalWrite(led3Pin, state);
  state = !state;
  digitalWrite(led4Pin, state);
}

void setup(){
  Buz1.begin(buzz1Pin, bassLedCallback);
  Buz2.begin(buzz2Pin, melodyLedCallback);
  pinMode(ledPin, OUTPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(ledStripPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}


void Checkval(int a, int b)
{
  if (a != b)
  {
    Buz1.stop();
    Buz2.stop();
    while (1)
    {
      static bool ledStatus = false;
      ledStatus = !ledStatus;
      digitalWrite(ledPin, ledStatus);
      delay(100);
    }
  }
}


#define NUM_OF(song) (sizeof(song) / sizeof (Note))

void delayInLoop(long microSeconds)
{
   const unsigned long start = millis();
   while (true)
   {
       unsigned long now = millis();
       if (now - start >= microSeconds)
       {
           return;
       }
   }
}

void loop(){
int minTime;
BuzzController Control1(&Buz1, drums, NUM_OF(drums));
BuzzController Control2(&Buz2, melody, NUM_OF(melody));
//BuzzController Control3(&Buz3, melody, NUM_OF(melody));

int buttonVal = digitalRead(buttonPin);

  while (buttonVal == HIGH) 
  {
	delay(100);
	buttonVal = digitalRead(buttonPin);
  }

  long time = millis();

  while (buttonVal == LOW) 
  //if (false)
  {
  delay(100);
  buttonVal = digitalRead(buttonPin);
  }

  bool longPress = false;

  if (millis() - time > 1000)
    longPress = true;

 // if (longPress)
  //  Error(500);

 //  Error(2000);
  
  while(!Control1.IsDone() && !Control2.IsDone())
  {
    minTime = min(Control1.GetTimeForNextNote(), Control2.GetTimeForNextNote());
    Control1.Play(minTime);
    Control2.Play(minTime);
    delay(minTime);
  }

  Buz1.play(NOTE_F5, 420);
  Buz2.play(NOTE_F4, 420);
  digitalWrite(led1Pin, 1);
  digitalWrite(led2Pin, 1);
  digitalWrite(led3Pin, 1);
  digitalWrite(led4Pin, 1);
  //digitalWrite(ledStripPin, 1);

delay(420);

  digitalWrite(led1Pin, 0);
  digitalWrite(led2Pin, 0);
  digitalWrite(led3Pin, 0);
  digitalWrite(led4Pin, 0);
  digitalWrite(ledStripPin, 1);

Error(1000);


while(1);

}
