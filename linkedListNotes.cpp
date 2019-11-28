//linked list
//header file
class ListNode{
  public:
    int data;
    ListNode *next;
    //constructor
    ListNode();
    ListNode(int d);
    ~ListNode;


};

//separate file
ListNode::ListNode(){}

ListNode::ListNode(int d){
  data = d;
  next = NULL;
}

ListNode::~ListNode(){
  if(next == NULL){
    delete next;
  }
}

//header file
class GenLinkedList{
  private:
    ListNode *front;
    unsigned int size;//unsigned because the size of a linked list cannot be negative
                      // unsigned means 0 thru max int size

  public:
    GenLinkedList();
    ~GenLinkedList();

    void insertFront(int d);
    int removeFront();
    int deletePosition(int position);
    int find();

    bool isEmpty();
    void printList();
    unsigned int getSize();
};


//implementation file

GenLinkedList::GenLinkedList(){
  size = 0;
  front = NULL; //null pointer


}

GenLinkedList::~GenLinkedList(){
  //generate on your own
}

unsigned int GenLinkedList::getSize(){
  return size;
}

void GenLinkedList::printList(){
    ListNode *curr = front;
    while (curr->next != NULL){
      cout << curr -> data << endl;
      curr = curr->next;
    }
}

void GenLinkedList::insertFront(int d){
  ListNode *node = new ListNode(d);
  node->next = front;
  front = node;
  size++;
}

int GenLinkedList::removeFront(){
  int tmp = front -> data;
  ListNode *ft = front; //ft stand for front temp
  front = front->next;
  ft->next = NULL;
  delete ft;
  size--;

  return tmp;
}

int GenLinkedList::deletePos(int position){
  //can pass in number for the position, or pass in a value that you want to find and delete by using find()
  int index = 0;
  ListNode *curr = front;
  ListNode *prev = front;

  while(index != position){
    //needs to update the previous node to point to the next node if you delete a node in the middle of the LL
    prev = curr;
    curr = curr->next;
    index++;
  }
  //we have found the position of the node to be deleted and hopefully our pointers are in the right spot
  prev->next = curr->next;
  curr->next = NULL;
  int tmp = curr->data;
  delete curr;
  size--;

  return tmp;

}

int GenLinkedList::find(int d){
  int index = 0;
  ListNode *curr = front;

  while(curr != NULL){
    
    if(curr->data == d){//we found the value we were looking for
      break;
    }
    index++;
    curr = curr->next;
  }

  if(curr == NULL){//we did not find the value
    index = -1;
  }
  return index;
}
