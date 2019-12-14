#ifndef GENLINKEDLIST_H
#define GENLINKEDLIST_H
#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

template<class T>
class ListNode
{
  public:
    ListNode(); // constructor
    ListNode(T d); //overloaded constructor
    ~ListNode(); //destructor

    T data;
    ListNode<T> *next;
    ListNode<T> *prev;

};

template <class T>
class GenLinkedList{
  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;//unsigned because the size of a linked list cannot be negative

  public:
    GenLinkedList(); // constructor
    ~GenLinkedList(); //deconstructor

    void insertFront(T d);
    T removeFront();
    void insertBack(T d);
    T removeBack();
    T deletePosition(int pos);
    void deleteKey(int key);
    int find(T data);
    string toString(); //places list data in a string

    T returnIndex(int idx); //helper function to return data's index
    bool isEmpty();
    void printList();
    unsigned int getSize();
};

template<class T>
GenLinkedList<T>::GenLinkedList(){
  size = 0;
  front = NULL; //null pointer
  back = NULL; //null pointer
}

template<class T>
GenLinkedList<T>::~GenLinkedList(){
  //iterate through and delete all
  if(front != NULL)
    delete front;
}

template<class T>
unsigned int GenLinkedList<T>::getSize(){
  return size;
}

template<class T>
void GenLinkedList<T>::printList(){
    ListNode<T> *curr = front;
    while (true){
      cout << curr -> data << endl;
      if(curr -> next == NULL)
        break;
      curr = curr->next;
    }
}

template<class T>
void GenLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()){
    back = node;
  }else{
    front -> prev = node;
    node -> next = front;
  }
  front = node;
  size++;
}

template<class T>
T GenLinkedList<T>::removeFront(){
  ListNode<T> * ft = front; //front temp is ft
  if(front -> next = NULL)
    back = NULL;
  else
    front -> next -> prev = NULL;
  T temp= front -> data;
  front = front -> next;
  ft -> next = NULL;
  delete ft;
  size--;

  return temp;
}

template<class T>
void GenLinkedList<T>::insertBack(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty())
    front = node;
  else{
    back -> next = node;
    node -> prev = back;
  }
  back = node;
  size++;
}

template<class T>
T GenLinkedList<T>::removeBack()
{
  //check if empty before removing
  ListNode<T> *bt = back; //bt stands for back temp
  if(back -> prev == NULL)
    front = NULL;
  else
    back -> prev -> next = NULL;
  T temp = back -> data;
  back = back -> prev;
  bt -> prev = NULL;

  delete bt;
  size--;

  return temp;
}

template<class T>
string GenLinkedList<T>::toString()
{
	string r;
	if(size>0){
		ListNode<T> *curr = front;

    while(true)
		{
			r += to_string(curr->data);
			if(curr->next == NULL)
				break;
			curr = curr->next;
			r += ";";
		}
	}
	return r;
}

template<class T>
void GenLinkedList<T>::deleteKey(int key) //deletes from the list based on a given key
{
	ListNode<T> *curr = front;

	while(curr->data != key)
	{
		curr = curr->next;
		if(curr==NULL)
			return;
	}

	if(curr == front)
		front = curr->next;
	else
		curr->prev->next = curr->next;

	if (curr == back)
		back = curr->prev;
	else
		curr->next->prev = curr->prev;

	curr->next = NULL;
	curr->prev = NULL;
	size--;
	delete curr;
	return;
}

template<class T>
T GenLinkedList<T>::deletePosition(int pos){
   //deletes from the list based on a given position
	if(pos == 0)
		return removeFront();
	else if(pos == size)
		return removeBack();
	else if(pos < size)
	{
		int i= 0;

		ListNode<T> *curr = front;
		ListNode<T> *prev = front;

		while(i != pos)
		{
			prev = curr;
			curr = curr->next;
			i++;
		}

		prev->next = curr->next;
		curr->next = nullptr;
	  T temp = curr->data;
		delete curr;
		size--;
		return temp;
	}
	else
		cout << "The given index does not exist" << endl;
}

template<class T>
int GenLinkedList<T>::find(T data){ //returns the index containing specific data
  int index = -1;
  ListNode<T> *curr = front;

  while(curr != NULL){
    ++index;
    if(curr->data == data){//we found the value we were looking for
      break;
    }
    curr = curr->next;
  }

  if(curr == NULL){//we did not find the value
    index = -1;
    cout << "The data was not found in the list" << endl;
  }
  return index;
}

template<class T> //check if the list is is empty
bool GenLinkedList<T>::isEmpty(){
  return(size == 0);
}

template<class T>
T GenLinkedList<T>::returnIndex(int idx)
{
	if(idx == 0)
		return front->data;
	else if(idx == size)
		return back->data;
	else if(idx < size)
	{
		int i = 0;

		ListNode<T> *curr = front;
		ListNode<T> *prev = front;

		while(i != idx)
		{
			prev = curr;
			curr = curr->next;
			i++;
		}

		return curr->data;
	}
	else
		cout << "The index does not exist" << endl;
}

/*
List Node definition in file becuase of linker issues
Cannot have a generic class implementing another generic class
*/
template<class T>
ListNode<T>::ListNode()
{
	data = 0;
	next = NULL;
	prev = NULL;
}
template<class T>
ListNode<T>::ListNode(T d)
{
	data = d;
	next = NULL;
	prev = NULL;
}

template<class T>
ListNode<T>::~ListNode(){

}

#endif
