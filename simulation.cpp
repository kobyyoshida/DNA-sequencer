#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include "simulation.h"

using namespace std;

Simulation::Simulation()
{
  lineType = 1;
  studentEntryTime = 0;
  studentTimeAtWindow = 0;
  numStudentsAtClockTick = 0;

  medianArrayElementsCount = 0;
  idleArrayElementsCount = 0;

  totalNumWindows = 0;
  totalStudents = 0;
}

Simulation::~Simulation()
{
  delete [] windowArray;
  delete [] medianArray;
  delete [] idleArray;
}

bool Simulation::readFile(string file)
{
	ifstream inputFile;
	inputFile.open(file.c_str());
	string line;
  int lineNumber = 1;

	if (inputFile.is_open())
	{
    try
    {
   		getline(inputFile, line);
   		totalNumWindows = stoi(line);
      windowArray = new Student*[totalNumWindows];

      for (int i = 0; i < totalNumWindows; ++i)
      {
        Student* s = new Student();
        windowArray[i] = s;
      }

      lineNumber++;
    }

    catch (exception e)
    {
      cout << "\nThe line anticipated to hold total number of students was not formatted correctly" << endl;
      return false;
    }

    while (getline(inputFile, line))
    {
      switch (lineType)
      {
        case (1):
        {
          try
          {
            studentEntryTime = stoi(line);
            lineType++;
            lineNumber++;
          }

          catch (exception e)
          {
            cout << "\nThe line anticipated to hold the time was not formatted correctly" << endl;
            return false;
          }

          break;
        }

        case (2):
        {
          try
          {
            if (line != "")
            {
           		numStudentsAtClockTick = stoi(line);
              for (int i = 0; i < numStudentsAtClockTick; ++i)
              {
                getline(inputFile, line);
                lineNumber++;

                try
                {
                  studentTimeAtWindow = stoi(line);
                }
                catch(exception e)
                {
                  cout << "\nThe line anticipated to hold total number of windows was not formatted correctly" << endl;
                  return false;
                }

                totalStudents++;

                Student* stud = new Student(studentTimeAtWindow, studentEntryTime);
                studentQueue.insert(stud);
              }
              lineType = 1;
            }
          }
          catch (exception e)
          {
            cout << "\nThe line anticipated to hold number of students was not formatted correctly" << endl;
            return false;
          }
          break;
        }
        default:break;
      }
    }
  }
  else
  {
    return false; //file did not open
  }
  return true;
}

bool Simulation::incrementTime(int c)
{
  for (int i = 0; i < totalNumWindows; ++i)
  {
    if (windowArray[i]->windowTime > 0)
    {
      windowArray[i]->windowTime--;
    }

    else
    {
      windowArray[i]->idleTime++;
    }
  }

  if (!studentQueue.isEmpty())
  {
    GenNode<Student*> *curr = studentQueue.getFrontP();

    while (curr != NULL)
    {
      if (curr->data->entryTime < c)
      {
        curr->data->lineTime += 1;
      }
      curr = curr->next;
    }
  }

  return true;
}

double Simulation::calcMeanWait()
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

double Simulation::calcMedianWait()
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

int Simulation::calcLongestWait()
{
  return medianArray[medianArrayElementsCount - 1];
}

int Simulation::calcNumWaitsOverTen()
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

double Simulation::calcMeanIdle()
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

int Simulation::calcLongestIdle()
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

int Simulation::calcNumIdleOverFive()
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
