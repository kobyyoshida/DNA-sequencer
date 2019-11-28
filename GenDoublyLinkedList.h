#ifndef GENDOUBLYLINKEDLIST_H
#define GENDOUBLYLINKEDLIST_H

#include "GenNode.h"
#include <iostream>

using namespace std;

template<class T>
class GenDoublyLinkedList{
  private:
    int size;
    GenNode<T>* front;
    GenNode<T>* back;

  public:
    GenDoublyLinkedList(); //constructor
    ~GenDoublyLinkedList(); //deconstructor

    void insertFront(T d);
    void insertBack (T d);
    T removeFront();
    T removeBack();
    T find(T d);
    T deletePos(int pos);
    bool contains(T d);
    T getBack();
    GenNode<T>* getFrontPointer();
    T getFront();

    bool isEmpty();
    void printList();
    unsigned int getSize();
};

template<class T>
GenDoublyLinkedList<T>::GenDoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

template<class T>
GenDoublyLinkedList<T>::~GenDoublyLinkedList(){
  if(front != NULL){
    delete front;
  }
}

template<class T>
unsigned int GenDoublyLinkedList<T>::getSize()
{
  return size;
}

template<class T>
bool GenDoublyLinkedList<T>::isEmpty()
{
  return(front==NULL && back==NULL);
}

template<class T>
void GenDoublyLinkedList<T>::printList(){
  GenNode<T> *curr =  front;

  while(curr != NULL){
    cout << curr->data <<endl;
    curr = curr->next;
  }
}

template<class T>
void GenDoublyLinkedList<T>::insertFront(T d)
{
  GenNode<T>* node = new GenNode<T>(d);
  if(!isEmpty())
  {
    //empty list
    back = node;
  }else
  {
    //not an empty list
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

template<class T>
T GenDoublyLinkedList<T>::removeFront()
{
  GenNode<T> *old = front;

  if(front->next == NULL){
    //one node in the list
    back = NULL;
  }else
  {
    //list has more then one node in the list
    front -> next -> prev = NULL;
  }

  front = front ->next;
  old->next = NULL;
  T temp = old-> data;

  delete old;
  size--;

  return temp;
}

template<class T>
T GenDoublyLinkedList<T>::find(T d)
{
  int idx = 0;
  GenNode<T> *curr = front;

  while(curr != NULL)
  {
    if(curr->data == d)
    {
      //break;
      return idx;
    }

    idx++;
    curr = curr->next;
  }
  return -1;
}

template <class T>
void GenDoublyLinkedList<T>::insertBack(T d){
  GenNode<T>* node = new GenNode<T>(d);
  if(!isEmpty())
  {
    //empty list
    front = node;
  }else
  {
    //not an empty list
    back -> next = node;
    node -> prev = back;

  }
  back = node;
  size++;
}

template<class T>
T GenDoublyLinkedList<T>::removeBack()
{
  GenNode<T> *old = back;

  back -> prev -> next = NULL;
  back = back -> prev;
  old -> prev = NULL;

  T temp = old -> data;

  delete old;
  size--;
  return temp;
}

template<class T>
bool GenDoublyLinkedList<T>::contains(T d){
  int idx = -1;
  GenNode<T>* curr = front;

  while(curr != NULL){
    ++idx;
    if(curr->data = d){
      return true;
    }else{
      curr = curr->next;
    }
  }

  if(curr == NULL){
    return false;
  }
  return false;
}

template<class T>
T GenDoublyLinkedList<T>::deletePos(int pos){

  int idx = 0;

  GenNode<T>* curr = front;
  GenNode<T>* prev = front;

  while(idx != pos){
    prev = curr;
    curr = curr -> next;
    idx++;
  }

  prev-> next = curr -> next;
  curr->next = NULL;
  T temp = curr -> data;

  delete curr;
  size--;
  return temp;
}

template<class T>
T GenDoublyLinkedList<T>::getBack(){
  return back->data;
}

template<class T>
GenNode<T>* GenDoublyLinkedList<T>::getFrontPointer(){
  return front;
}

template<class T>
T GenDoublyLinkedList<T>::getFront(){
  return front->data;
}

#endif
