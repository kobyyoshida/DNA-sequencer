#ifndef GENNODE_H
#define GENNODE_H

template <class T>
class GenNode{
  public:
    T data;
    GenNode *next;
    GenNode *prev;

    GenNode(); //constructor

    GenNode(T d); //overloaded constructor
    ~GenNode(); //deconstructor
};

template<class T> GenNode<T>::GenNode(){}

template<class T> GenNode<T>::GenNode(T d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

template<class T> GenNode<T>::~GenNode()
{
  if(next != NULL){
    next = NULL;
    prev = NULL;

    delete next;
    delete prev;
  }
}

#endif
