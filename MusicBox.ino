#include "Tone.h"

const int buzz1Pin = 7;
const int buzz2Pin = 8;
const int ledPin = 13;

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


typedef struct Note{
  uint16_t sound;
  uint16_t time;
  uint16_t silence;
} Note;


class BuzzController{
 Tone* Buzz;
 Note* Notes;
 int NumOfNotes;
 int TimeForNextNote;
 int CurrentNote;
 bool ShouldPlay;

public: 
  BuzzController(Tone* Buzz, Note* Notes, int NumOfNotes) : CurrentNote(0), Buzz(Buzz), Notes(Notes), NumOfNotes(NumOfNotes)
  {
    TimeForNextNote = Notes[CurrentNote].time + Notes[CurrentNote].silence;
    ShouldPlay = true;
  }

  void Play(int TimeToRecude)
  {
    if (TimeToRecude > TimeForNextNote)
      Error(500);
      
    if (ShouldPlay)
    {
      Buzz->play(Notes[CurrentNote].sound + 10, Notes[CurrentNote].time);
      ShouldPlay = false;
    }

    if (TimeForNextNote == TimeToRecude)
    {
      CurrentNote++;
      TimeForNextNote = Notes[CurrentNote].time + Notes[CurrentNote].silence;
      ShouldPlay = true;
    }
    else
      TimeForNextNote -= TimeToRecude;
  }

  int GetTimeForNextNote()
  {
    return TimeForNextNote;
  }

  int IsDone()
  {
    return (CurrentNote == NumOfNotes);
  }
};


void setup(){
  Buz1.begin(buzz1Pin);
  Buz2.begin(buzz2Pin);
  pinMode(ledPin, OUTPUT);

  
}


typedef struct state{
  uint16_t buz1Sound;
  uint16_t buz2Sound;
  uint16_t delay;
  uint16_t silence;
} state;

state song[] {

  // OPENING
  
  {0, NOTE_DS4, 650, 70},
  {0, NOTE_DS4, 650, 70},
  {0, NOTE_DS4, 650, 70},
  {0, NOTE_AS3, 650, 70},
 {0, NOTE_FS3, 650, 70},
{0, NOTE_CS4, 300, 70},
  {0, NOTE_B3, 900, 1000},
 {0, NOTE_AS3, 350, 30},
  {0, NOTE_DS4, 700, 70},
  {0, NOTE_DS4, 950, 130},
 {0, NOTE_AS3, 300, 30},
  {0, NOTE_DS4, 600, 70},
  {0, NOTE_AS3, 600, 30},
  {0, NOTE_FS3, 700, 70},
  {0, NOTE_CS4, 900, 70},
  {0, NOTE_FS3, 1000, 2000},

{0, NOTE_FS4, 1350, 50},
{0, NOTE_F4, 310, 30},
{0, NOTE_DS4, 1000, 20},

{0, NOTE_DS4, 400, 50},
{0, NOTE_CS4, 400, 50},

{0, NOTE_DS3, 450, 450},
{0, NOTE_CS4, 250, 200},
{0, NOTE_FS4, 250, 75},
{0, NOTE_DS4, 200, 1225},


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



Note song1[] {
{NOTE_DS2, 50, 400},
{NOTE_DS2, 50, 400},
{NOTE_DS2, 50, 400},
{NOTE_DS2, 50, 400},
{NOTE_DS2, 50, 400},
{NOTE_DS2, 50, 400},
{NOTE_DS2, 50, 400},
{NOTE_DS2, 50, 400},
{NOTE_DS2, 50, 400},
{NOTE_DS2, 50, 400},
{NOTE_DS2, 50, 400},
};

Note song2[] {
{NOTE_FS4, 1350, 50},
{NOTE_F4, 310, 30},
{NOTE_DS4, 1000, 20},

{NOTE_DS4, 400, 50},
{NOTE_CS4, 400, 50},

{NOTE_DS3, 450, 450},
{NOTE_CS4, 250, 200},
{NOTE_FS4, 250, 75},
{NOTE_DS4, 200, 1225},
};

#define NOTES (sizeof(song1) / sizeof (Note))



void loop(){
int minTime;
BuzzController Control1(&Buz1, song1, NOTES);
BuzzController Control2(&Buz2, song2, NOTES);


while(!Control1.IsDone() && !Control2.IsDone())
{
  //Error(1000);
  minTime = min(Control1.GetTimeForNextNote(), Control2.GetTimeForNextNote());
  Control1.Play(minTime);
  Control2.Play(minTime);
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

 for (int i = 0; i < SONG_STATES; i++)
 {
   handle_state(song[i]);
 }


while(1);
  


}
