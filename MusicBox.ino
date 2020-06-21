#include "Tone.h"
#include "BuzzController.h"
#include "Melody.h"
#include "Drums.h"
#include "Bass.h"

const int buzz1Pin = 7;
const int buzz2Pin = 8;
//const int buzz3Pin = 6;
const int ledPin = 13;

Tone Buz1;
Tone Buz2;
Tone Buz3;

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



void setup(){
  Buz1.begin(buzz1Pin);
  Buz2.begin(buzz2Pin);
  //Buz3.begin(buzz3Pin);
  pinMode(ledPin, OUTPUT);

  
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

  
  while(!Control1.IsDone() && !Control2.IsDone())
  {
    //Error(1000);
    minTime = min(Control1.GetTimeForNextNote(), Control2.GetTimeForNextNote());
    //minTime = min(minTime, Control3.GetTimeForNextNote());
    Control1.Play(minTime);
    Control2.Play(minTime);
   // Control3.Play(minTime);
    delay(minTime);
  }

Error(1000);


while(1);
  
bool ledStatus = false;
//Buz2.play(NOTE_AS4, 3000);
Buz1.play(NOTE_AS4);
delay(500);
Buz1.play(NOTE_GS4);
delay(500);
Buz1.play(NOTE_AS4);
delay(500);
Buz1.play(NOTE_GS4);
delay(500);
Buz1.stop();



while(1);
  


}
