#include <iostream>
#include <cstddef>

class ListNode{
  public:
    int data;
    ListNode*next;
    ListNode *prev;

    ListNode();
    ListNode(int d);
    ~ListNode();
};

ListNode::ListNode(){}

ListNode::ListNode(int d){
  data = d;
  next = NULL;
  prev = NULL;

}

ListNode::~ListNode(){
  next = NULL;
  prev = NULL;
}

//template class <T>
//DoublyLinkedList
class DoublyLinkedList{
  private:
    ListNode *front;
    ListNode *back;
    unsigned int size;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(int d);
    int removeFront();
    int removeBack();
    int deletePos(int pos); //aka removeAt()
    int find(int d);  //aka contains()
    void insertBack(int d);
    ListNode* remove(int d);

    bool isEmpty();
    void printList();
    unsigned int getSize();
};

//doubly linked list implementation

DoublyLinkedList::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;

}

DoublyLinkedList::~DoublyLinkedList(){
  //iterate thru list
}

void DoublyLinkedList::insertFront(int d){
  ListNode *node = new ListNode(d);
  if(size == 0){//empty list
    back = node;
  }
  else{
    //not empty
    node->next = front;
    front->prev = node;
  }
  front = node;
  size++;
}
/*
int DoublyLinkedList::removeFront(){//first check if its empty
  int tmp = front -> data;
  ListNode *ft = front; //ft stand for front temp
  front = front->next;
  ft->next = NULL;
  delete ft;
  size--;

  return tmp;
}
*/
int DoublyLinkedList::removeFront(){//check if empty before attempting to remove
  ListNode *ft = front;

  if(size==1){
    //its the node in the List
    back = NULL;
  }
  else{
    //we have more than one element in the List
    front->next->prev = NULL;
  }
  front = front->next;
  int temp = ft->data;
  ft->next = NULL;
  delete ft;
  size--;

  return temp;
}

void DoublyLinkedList::insertBack(int d){
  ListNode *node = new ListNode(d);

  if(isEmpty()){
      front = node;
    }
  else{//not an empty list
    //update pointers
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

ListNode* DoublyLinkedList::remove(int d){// aka int key
  //returning type listnode*
  //first make sure the list isnt empty
  ListNode *curr = front;
  while(curr->data != d){//
    curr = curr->next;
    if(curr == NULL){//we did not find the value
      return NULL;
    }
  }
  //if we get to this point it means we found it
  //lets check here if the node is the front
  if(curr == front){
    front = curr->next;
  }
  else{
    //its not the front
    curr->prev->next = curr->next;

  }
  if(curr == back){
    back = curr->prev;
  }
  else{//its not the back
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;
  size--;

  return curr;
}
