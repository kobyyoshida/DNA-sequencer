#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

template<class T>
class Stack {
	private:
    int size;
    int top;

		T *myArray;
		T *tempArray;

	public:
    Stack(); //default constructor
		Stack(int maxSize); //overloaded constructor
		~Stack(); //default constructor

		void push(const T &t); //pushes onto the stack
		T* pop(); //pops and returns the value from the top of the stack
		T* peek(); //aka top, returns the top values

		int getSize(); //gets the size of the stack
		bool isEmpty(); //returns if the stack is empty
	 	bool isFull(); //returns if the stack is full
		void growStack();
};

template<class T>
Stack<T>::Stack() //default constructor
{
  //initialization of default values
	myArray = new T[5]; //stack needs to be of size 5
  tempArray = new T[5]; //need 1 array for student and 1 for faculty, thats what i think temp array is for?
	size = 5;
	top = -1;
}

template<class T>
Stack<T>::Stack(int maxSize)
{
	myArray = new T[maxSize]; //dynamically allocating memory on the heap
  tempArray = new T[maxSize];
  size = maxSize;
	top = -1;
}

template<class T>
Stack<T>::~Stack() //deconstructor
{
	delete []myArray;
	delete []tempArray;
}

template<class T>
void Stack<T>::push(const T& t)
{
	if(isFull() == 1)
	{
		growStack();
		push(t);
	}
	else
	{
		myArray[++top] = t;
	}
}

template<class T>
T* Stack<T>::pop()
{
	if(isEmpty() == 1)
	{
		cout << "Cannot pop from an empty stack" << endl;
	}
	else
	{
		return myArray[top--];
	}
}

template<class T>
T* Stack<T>::peek()
{
	if(top == -1)
	{
		//the stack is empty cannot peek
    cout << "The stack is empty, cannot peek" << endl;
	}
	else
	{
		return myArray[top];
	}
}

template<class T>
int Stack<T>::getSize()
{
	return (size);
}

template<class T>
bool Stack<T>::isEmpty()
{
	return(top == -1);
}

template<class T>
bool Stack<T>::isFull()
{
	return((top+1)==size);
}

template<class T>
void Stack<T>::growStack()
{
	tempArray = new T[size];

	for(int i = top; i > -1; --i) //creates a temporary stack holding all the values from myArray
	{
		tempArray[i] = myArray[i];
	}

	size += 10;	//increasing the stack max
	myArray = new T[size];

	for(int i = top; i > -1; --i) //adds the copied values into the new stack
	{
		myArray[i] = tempArray[i];
	}
}

#endif
