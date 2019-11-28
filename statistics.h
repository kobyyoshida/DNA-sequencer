#include <iostream>
#include "statistics.cpp"
#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics{
public:
  double calcMeanIdle();
  double calcMeanWait();
  double calcMedianWait();
  int calcLongestWait();
  int calcNumWaitsOverTen();
  int calcLongestIdle();
  int calcNumIdleOverFive();
  //bool incrementTime(int c);


  string getMinutesMessage();

  Student* *windowArray;

  GenQueue<Student*> studentQueue;

  GenQueue<int> waitTimeStatsList;
  GenQueue<int> idleTimeStatsList;

  int *medianArray;
  int *idleArray;

  int totalNumWindows;
  int totalStudents;
private:

  int lineType;
  int studentEntryTime;
  int studentTimeAtWindow;
  int numStudentsAtClockTick;
  int medianArrayElementsCount;
  int idleArrayElementsCount;
};

#endif
