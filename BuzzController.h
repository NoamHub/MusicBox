#pragma once

void Error(int T);


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