#include <iostream>
class GenQueue{
  public:
  GenQueue();//default constructor
  GenQueue(int maxSize);//overloaded constructor
  ~GenQueue();

  //core functions
  void insert(char d);
  char remove();

  //aux functions
  char peek();
  bool isFull();
  bool isEmpty();

  //vars
  int head; //front
  int rear; //tail
  int size;
  int numElements;
  int getSize();

  char *myQueue; //array 
};
