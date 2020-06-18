#include "Tone.h"
//#include "Thread.h"

const int buzzer1 = 7; //buzzer to arduino pin 9
const int buzzer2 = 8; //buzzer to arduino pin 9

const int ledPin = 13; //buzzer to arduino pin 9


Tone Buz1;
Tone Buz2;

//Thread myThread = Thread();

// callback for myThread
void niceCallback(){
  static bool ledStatus = false;
  ledStatus = !ledStatus;

  digitalWrite(ledPin, ledStatus);
}


void setup(){
 
 // pinMode(buzzer1, OUTPUT); // Set buzzer - pin 9 as an output
 // pinMode(buzzer2, OUTPUT); // Set buzzer - pin 9 as an output
  Buz1.begin(7);
  //Buz2.begin(8);
 // pinMode(ledPin, OUTPUT);
 // myThread.onRun(niceCallback);
 // myThread.setInterval(500);
}

typedef struct state{
  uint16_t buz1Sound;
  uint16_t buz2Sound;
  uint16_t delay;
  uint16_t silence;
} state;

#define M 650


state song[] {
  /*
  {0, NOTE_DS4, M, 70},
  {0, NOTE_DS4, M, 70},
  {0, NOTE_DS4, M, 70},
  {0, NOTE_AS3, M, 70},
 {0, NOTE_FS3, M + 50, 70},
{0, NOTE_CS4, 300, 70},
  {0, NOTE_B3, 800, 1000},
 {0, NOTE_AS3, 350, 30},
  {0, NOTE_DS4, 700, 70},
  {0, NOTE_DS4, 1000, 70},
 {0, NOTE_AS3, 300, 30},
  {0, NOTE_DS4, 600, 70},
  {0, NOTE_AS3, 600, 30},
  {0, NOTE_FS3, 700, 70},
  {0, NOTE_CS4, 900, 70},
    {0, NOTE_FS3, 1000, 700},
*/


{0, NOTE_FS4, 1350, 50},
{0, NOTE_F4, 310, 30},
{0, NOTE_DS4, 1000, 20},

{0, NOTE_DS4, 400, 80},
{0, NOTE_CS4, 500, 80},

{0, NOTE_GS2, 500, 400},
{0, NOTE_CS3, 150, 300},
{0, NOTE_CS3, 150, 300},
{0, NOTE_DS3 + 8, 300, 300},

/*
{0, NOTE_FS5, 240, 0},
{0, NOTE_DS5, 240, 0},
{0, NOTE_CS5, 240, 0},
{0, NOTE_DS5, 240, 0},
{0, NOTE_FS5, 240, 0},
{0, NOTE_DS5, 240, 0},
{0, NOTE_CS5, 240, 0},
{0, NOTE_DS5, 240, 0},
{0, NOTE_CS5, 230, 10},
{0, NOTE_AS4, 400, 50},
{0, NOTE_AS5, 800, 0},
*/
// 0

{0, NOTE_AS4, 460, 190},
{0, NOTE_AS4, 180, 90}, 
{0, NOTE_AS4, 250, 200}, 

{0, NOTE_FS4, 200, 130},// 430
{0, NOTE_F4, 170, 170},//20 + 225 + 245
{0, NOTE_DS4, 210, 250},

{0, NOTE_DS4, 150, 70},


{0, NOTE_DS4, 150, 75},
{0, NOTE_AS4, 150, 75},
{0, NOTE_GS4, 150, 75},
{0, NOTE_AS4, 150, 75},
{0, NOTE_GS4, 150, 300},

{0, NOTE_AS4, 150, 75}, // *
{0, NOTE_AS4, 150, 75},
{0, NOTE_AS4, 150, 75}, // *
{0, NOTE_DS4, 150, 75},

{0, NOTE_FS4, 240, 110}, // *
{0, NOTE_DS4, 110, 75},
// **
/*
{0, NOTE_FS5, 50, 400},
{0, NOTE_FS5, 50, 400},
{0, NOTE_FS5, 50, 400},
{0, NOTE_FS5, 50, 400},
{0, NOTE_FS5, 50, 400},
{0, NOTE_FS5, 50, 400},
{0, NOTE_FS5, 50, 400},
{0, NOTE_FS5, 50, 400},
*/
//{0, 0, 1000, 0},
};

#define SONG_STATES (sizeof(song) / sizeof (state))

void handle_state(struct state s)
{
  if (s.buz1Sound)
    Buz1.play(s.buz1Sound);
  else
    Buz1.stop();
  if (s.buz2Sound)
    Buz2.play(s.buz2Sound + 10);
  else
    Buz2.stop();
  delay(s.delay); 
  
  if (s.silence)
  {
  Buz1.stop();
  Buz2.stop();
  delay(s.silence);
  }
}

void loop(){
  
 for (int i = 0; i < SONG_STATES; i++)
 {
   handle_state(song[i]);
 }
 
// if(myThread.shouldRun())
  // myThread.run();

   //Buz1.play(NOTE_AS4, 100);

//while(1);
}
