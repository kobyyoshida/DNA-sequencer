#ifndef SYNTAXGENSTACK_H
#define SYNTAXGENSTACK_H
#include <iostream>
#include <stdexcept>

//#include "stackNotes.cpp"
using namespace std;

template <class T>

class syntaxGenStack{
  public:
    syntaxGenStack(); // constructor
    syntaxGenStack(int maxSize); //overloaded constructor
    ~syntaxGenStack(); //destructor

    void push(const T& d); //pushes the &object of class T
    T pop();
    T peek();
    void resize(T stack);

    bool isFull();
    bool isEmpty();

    int maxSize;
    int size;
    int top;
    T *myArray; //pointer because the over loaded constructor is not set to how many elements there will be
};

template <class T>
syntaxGenStack<T>::syntaxGenStack(){
  myArray = new T[128];
  size = 128;
  top = -1;
}

template <class T>
syntaxGenStack<T>::syntaxGenStack(int maxSize){
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

template <class T>
syntaxGenStack<T>::~syntaxGenStack(){
  delete(myArray);
}

template <class T>
void syntaxGenStack<T>::push(const T& d){
  myArray[++top] = d;
}

template<class T>
T syntaxGenStack<T>::peek(){
  //check if empty
  return myArray[top];
}

template <class T>
T syntaxGenStack<T>::pop(){
  if(top<0){
    throw std::runtime_error("Stack is empty.");
    //return '/0';
  }
  else{
    return myArray[top--];
  }
}

template <class T>
bool syntaxGenStack<T>::isEmpty(){
  return (top == -1);
}

template <class T>
bool syntaxGenStack<T>::isFull(){
  return (top == size-1);
}

template <class T>
void syntaxGenStack<T>::resize(T stack){
    size *= 2;
    syntaxGenStack stack2(size);
    while(!stack.isEmpty()){
      for(int i =0; i < stack.size(); i++){
        stack2.push(stack[i]);
      }
      delete myArray;
    }
    myArray = new T[size];
    while(!stack2.isEmpty()){
      for(int i = 0; i < stack2.size();i++){
        stack.push(stack2[i]);
      }
    }
}
#endif
