#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include "GenLinkedList.h"

class Window{

public:
  int numStudentsInLine;//number of students in the queue
  int windows;
  int waitTime = 0;
  int time; //read in from fileio i think

  Window();
  ~Window();
  
};



void Window::addingStudentsToWindows(){
for(int i=0; i<time; i++){
  if(windowAvailable){
  queue.pop(a);
    a.occupyWindow();
    }
  else()
    lineWaitTime++;

  }
}
