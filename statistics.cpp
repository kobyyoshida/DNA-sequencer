#include <iostream>
#include "GenQueue.h"
#include "simulation.h"


Statistics::Statistics(){
  lineType = 1;
  studentEntryTime = 0;
  studentTimeAtWindow = 0;
  numStudentsAtClockTick = 0;

  medianArrayElementsCount = 0;
  idleArrayElementsCount = 0;

  totalNumWindows = 0;
  totalStudents = 0;
}

Statistics::~Statistics(){
  /*
  delete [] windowArray;
  delete [] medianArray;
  delete [] idleArray;
  */
}


double Statistics::calcMeanWait()
{
  GenNode<int> *curr = waitTimeStatsList.getFrontP();

  double meanWait = 0;
  int sum = 0;
  int count = 0;

  while (curr != NULL)
  {
    sum += curr->data;
    curr = curr->next;
    count++;
  }

  meanWait = double(sum) / double(count);

  return meanWait;
}

double Statistics::calcMedianWait()
{
  GenNode<int> *curr = waitTimeStatsList.getFrontP();

  double medianWait = 0;
  medianArrayElementsCount = 0;

  while (curr != NULL)
  {
    curr = curr->next;
    medianArrayElementsCount++;
  }
  medianArray = new int[medianArrayElementsCount];
  curr = waitTimeStatsList.getFrontP();
  for (int i = 0; i < medianArrayElementsCount; ++i)
  {
    medianArray[i] = curr->data;
    curr = curr->next;
  }

  sort(medianArray, medianArray + medianArrayElementsCount);
  if (medianArrayElementsCount % 2 == 1)
  {
    double d = 0;
    int t = 0;
    t = (medianArrayElementsCount / 2) + 1;
    d = medianArray[t];
    return d;
  }

  else
  {
    double d = 0;
    int t1 = 0;
    int t2 = 0;
    t1 = medianArrayElementsCount / 2;
    t2 = (medianArrayElementsCount / 2) + 1;
    d = double(medianArray[t1]) / double(medianArray[t2]);
    return d;
  }
}

int Statistics::calcLongestWait()
{
  return medianArray[medianArrayElementsCount - 1];
}

int Statistics::calcNumWaitsOverTen()
{
  int c = 0;
  for (int i = 0; i < medianArrayElementsCount; ++i)
  {
    if (medianArray[i] > 10)
    {
      ++c;
    }
  }
  return c;
}

double Statistics::calcMeanIdle()
{
  GenNode<int> *curr = idleTimeStatsList.getFrontP();
  double meanIdle = 0;
  int sum = 0;
  int count = 0;

  while (curr != NULL)
  {
    sum += curr->data;
    curr = curr->next;
    count++;
  }

  meanIdle = double(sum) / double(count);
  return meanIdle;
}

int Statistics::calcLongestIdle()
{
  GenNode<int> *curr = idleTimeStatsList.getFrontP();

  idleArrayElementsCount = 0;

  while (curr != NULL)
  {
    curr = curr->next;
    idleArrayElementsCount++;
  }
  idleArray = new int[idleArrayElementsCount];
  curr = idleTimeStatsList.getFrontP();

  for (int i = 0; i < idleArrayElementsCount; ++i)
  {
    idleArray[i] = curr->data;
    curr = curr->next;
  }
  sort(idleArray, idleArray + idleArrayElementsCount);

  return (idleArray[idleArrayElementsCount - 1]);
}

int Statistics::calcNumIdleOverFive()
{
  int c = 0;
  for (int i = 0; i < idleArrayElementsCount; ++i)
  {
    if (idleArray[i] > 5)
    {
      ++c;
    }
  }
  return c;
}
