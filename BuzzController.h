#pragma once
#include "stdio.h"

void Error(int T);

typedef struct Note{
  uint16_t sound;
  uint16_t time;
  uint16_t silence;
} Note;

class BuzzController{
 Tone* Buzz;
 const Note* Notes;
 Note CurrentNote;
 int NumOfNotes;
 int TimeForNextNote;
 int CurrentNoteIndex;
 bool ShouldPlay;

public: 
  BuzzController(Tone* Buzz, const Note* Notes, int NumOfNotes) : CurrentNoteIndex(0), Buzz(Buzz), Notes(Notes), NumOfNotes(NumOfNotes)
  {
    memcpy_P(&CurrentNote, &Notes[CurrentNoteIndex], sizeof(Note)); 
    TimeForNextNote = CurrentNote.time + CurrentNote.silence;
    ShouldPlay = true;
  }

  void Play(int TimeToRecude)
  {
    if (TimeToRecude > TimeForNextNote)
      Error(500);
      
    if (ShouldPlay)
    {
      Buzz->play(CurrentNote.sound + 10,CurrentNote.time);
      ShouldPlay = false;
    }

    if (TimeForNextNote == TimeToRecude)
    {
      memcpy_P(&CurrentNote, &Notes[++CurrentNoteIndex], sizeof(Note)); 
      TimeForNextNote = CurrentNote.time + CurrentNote.silence;
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
    return (CurrentNoteIndex == NumOfNotes);
  }
};
