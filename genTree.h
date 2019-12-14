#include <iostream>
/*
class TreeNode{
  public:
    TreeNode();
    TreeNode(int k); //k=key, which in this example is also the value
    ~TreeNode(); //when creatinga  temp;ate class, destructor must be virtual

    int key
    TreeNode *left;
    TreeNode *right;


};


TreeNode::TreeNode(){
  key = NULL;
  left = NULL;
  right = NULL;
}

TreeNode::TreeNode(int k){
  key = k;
  left = NULL;
  right = NULL;
}

TreeNode::~TreeNode(){
  //whatever
}
*/


template <class T>
class BST{
  private:
    TreeNode *root;

  public:
    BST();
    ~BST();

    bool search(int value);
    void insert(T value);

    //delete placeholder
    bool deleteNode(int key);

    //helper function
    bool isEmpty();
    TreeNode *getMin();
    TreeNode *getMax();
    void printTree(TreeNode *node);
    void recPrint(TreeNode *node);

};
template <class T>
BST<T>::BST(){
  root = NULL; //empty tree
}


BST::~BST(){

}

void BST::recPrint(TreeNode *node){
  if(node == NULL)
    return;

  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);

}
void BST::printTree(){
  recPrint(root);
}
TreeNode* BST::getMax(){
  TreeNode *curr = root;

  if(root == NULL){//empty tree
    return NULL;
  }

  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr;

}

void BST::insert(int value){
  TreeNode *node = new TreeNode(value);
  if(root==NULL){//empty tree
    root = node;
  }
  else{//tree is not empty, need to find insertion location
    TreeNode *curr = root;
    //need to keep track of parent to attach it to
    TreeNode *parent = NULL;

    while(curr!=NULL){
      parent = current;
      if(value < curr->key){
        curr = curr->left;

        if(curr == NULL){//we found our insertion point
          parent->left = node;
          break;
        }
      }
      else{
        curr = curr->right;

        if(curr == NULL){//we found our insertion point
          parent->left = node;
          break;
        }
      }
    }//end while loop
  }
}

bool BST::search(int value){
  if(root == NULL){
    return false;
  }
  else{
    //tree is not empty, lets attempt to look for it
    TreeNode *curr = root;
    while(curr->key != value){

      if(value < curr->key){
        curr = curr->left;
      }
      else{
        curr = curr->right;
      }
      if(curr == NULL){//we did not find the value
        return false;
      }
      else{
        return true;
      }

    }
  }
}

bool BST::deleteNode(int value){

  if(root == NULL){
    return false;
  }

  TreeNode *curr = root;
  TreeNode *parent = root;
  bool isLeft = true;

  //now lets look for the node

  while(curr->key != value){
    if(value < curr->key){
      curr = curr->left;
    }
    else{
      isLeft = false;
      curr = curr->right;
    }
    if(curr == NULL){//did not find the value
      return false;
    }
  }//end while loop
  //if we make it here, hen we found the node that needs to be deleted

  //no children
  if(curr->left == NULL && curr->right == NULL){
    if(curr == root){
      root = NULL;
    }
    else if (isLeft){
      parent->right = NULL;
    }
    else
      parent->left = NULL;
  }

  //node to be deleted has one child, we need to determine if child is left or right and proceed
  else if(curr->right == NULL){//has no right child
    if(curr==root){
      root = curr->left;
    }
    else if (isLeft){
      parent->left = curr->left;
    }
    else{
      parent->right = curr->left;
    }
  }


  else if(curr->left == NULL){//has no left child
    if(curr==root){
      root = curr->right;
    }
    else if (isRight){
      parent->left = curr->right;
    }
    else{
      parent->right = curr->right;
    }
  }


  else{//node to be deleted has 2 children
    TreeNode *successor = getSuccessor(current);

    if(curr==root){
      root = successor;
    }
    else if (isLeft){
      parent->left = successor;
    }
    else{
      parent->right = successor;
    }
    successor->left = current->left;

  }
  return true;
}

TreeNode* BST::getSuccessor(TreeNode *d){ //d is the node to be deleteNode
  TreeNode *sp = d; //sp = successors parent and is initialized to d
  TreeNode *successor = d;
  TreeNode *current = d->right;

  while(current != NULL){//one right all the way left
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right){//successor is a decendent of the right child
    sp->left = successor->right;
    successor->right = d->right;

  }
  return successor;
}
