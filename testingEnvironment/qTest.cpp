#include <iostream>
#include "GenQueue.h"
#include "Student.h"

using namespace std;

int main (int argc, char **argv){
  GenQueue<Student*>* queue = new GenQueue<Student*>;

  Student* test = new Student(1,2);

  queue->put(test);


  queue->print();


}
