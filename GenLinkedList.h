#ifndef GENLINKEDLIST_H
#define GENLINKEDLIST_H

#include <stdexcept>
#include "GenNode.h"

using namespace std;

template<class T>
class GenLinkedList{
  private:
    GenNode *front;
    unsigned int size;

  public:
    GenLinkedList();
    ~GenLinkedList();

    void windowOpened(const T &d);
    T occupyWindow() throw(runtime_error);

    bool windowsFull() const;
    unsigned int getSize() const;
};

template<class T>
GenLinkedList<T>::GenLinkedList(){
  size = 0;
  front = nullptr;
}

template<class T>
GenLinkedList<T>::~GenLinkedList(){
  while(!isEmpty()){
    removeFront();
  }
}

template<class T>
unsigned int GenLinkedList<T>::getSize() const
{
  return size;
}

template<class T>
bool GenLinkedList<T>::windowsFull() const
{
  return front==nullptr;
}

template<class T>
void GenLinkedList<T>::windowOpened(const T &d)
{
  GenNode* = new GenNode(d);
  node->next=front;
  front = node;
  size++;
}

template<class T>
T GenLinkedList<T>::occupyWindow() throw(runtime_error)
{
  if(!isEmpty()){
      GenNode *old = front;
    T temp = front -> next;
    front =  front->next;
    old->next =  nullptr; //null out a pointer to null before deleting
    delete old;
    size--;

    return temp;
  }else{
    throw runtime_error("There are no elements in the list to remove");
  }
}
}

#endif
