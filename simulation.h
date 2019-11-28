#ifndef SIMULATION_H
#define SIMULATION_H
#include "GenQueue.h"
#include "Student.h"

using namespace std;

class Simulation{
  public:
    Simulation(); //constuctor
    ~Simulation(); //deconstructor

    bool readFile(string readFile);
    bool incrementTime(int c);

    double calcMeanWait();
    double calcMedianWait();
    int calcLongestWait();
    int calcNumWaitsOverTen();

    double calcMeanIdle();
    int calcLongestIdle();
    int calcNumIdleOverFive();

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
