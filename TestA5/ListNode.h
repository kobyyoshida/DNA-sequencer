#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

template <class T>
class ListNode
{ //node needs to hold Student or Faculty data listed in each respective class
  public:
    T data;
    ListNode<T> *next;
    ListNode<T> *prev;
    ListNode(); // constructor
    ListNode(T data); // overloaded constructor
    ~ListNode(); // deconstructor
};
#endif


template <class T>
ListNode<T>::ListNode()
{}

template <class T>
ListNode<T>::ListNode(T d){//data will be type student/faculty
{
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode()
{
  if(next != NULL)
  {
    next = NULL;
    prev = NULL;
    delete next;
    delete prev;
  }
}
