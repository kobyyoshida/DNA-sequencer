#include <iostream>
#include "student.h"

using namespace std;

Student::Student(){ //default constuctor
  lineTime = 0;
  windowTime = 0;
  entryTime = 0;
  idleTime = 0;
}

Student::Student(int w, int e){ //overloaded constructor
  lineTime = 0;
  windowTime = w;
  entryTime = e;
  idleTime = 0;
}

Student::~Student(){ //deconstructor

}
