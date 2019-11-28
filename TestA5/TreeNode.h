#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>

/*
Abby Bechtel and Koby Yoshida
abechtel@chapman.edu and koyoshida@chapman.edu
2312284 and 1023362
*/

using namespace std;

template <class T>
class TreeNode{
  public:
    TreeNode();
    TreeNode(int k, T d); //k = key, which in this example is also the value
    ~TreeNode();

    int key;
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

template<class T>
TreeNode<T>::TreeNode(){
}

template<class T>
TreeNode<T>::TreeNode(int k, T d){//needs a way to hold a student object and all of its attributes
  key = k;
  data = d;
}
template<class T>
TreeNode<T>::~TreeNode(){
}


#endif
