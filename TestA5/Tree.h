#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class Tree
{
	public:
		Tree();	// constructor
		~Tree(); // deconstructor

		void insert(int k, T d); //inserts to tree
		bool deleteNode(int k); //deletes node
		bool contains(int k);	//returns bool whether a key is in the tree
		bool isEmpty();	//returns if the tree is empty
		T* find(int k);	//returns data of a node given the key
		void print();	//prints the tree
		void print(TreeNode<T>* node);	//prints the tree from a given node
		TreeNode<T>* getSuccessor(TreeNode<T> *node);	//gets the successor of a node
		T deleteRoot(); //returns the root of the tree and deletes it

		TreeNode<T> *getMin();//gets the min key value
		TreeNode<T> *getMax();//gets the max key value

	private:
		TreeNode<T> *root;
};

template<class T>
Tree<T>::Tree()
{
	root = NULL;
}

template<class T>
Tree<T>::~Tree()
{
	delete root;
}

template<class T>
T Tree<T>::deleteRoot()
{
		TreeNode<T> *curr = root;

		//case 1: no children
		if(curr->left == NULL && curr->right == NULL) {
			root = NULL;
		}

		//case 2: one child
		else if(curr->right == NULL){
			if(curr == root) root = curr->left;
		}

		else if(curr->left == NULL){
			if(curr == root) root = curr->right;
		}

		//case 3: two children
		else{
			TreeNode<T> *successor = getSuccessor(curr);

			if(curr == root) root = successor;
			successor->left = curr->left;
		}
		T temp = curr->data;
		delete curr;
		return temp;

}

template<class T>
bool Tree<T>::isEmpty()
{
	if(root == NULL){
    return true;
  }
	else{
    return false;
  }
}

template<class T>
void Tree<T>::print() //in order traversal
{
	TreeNode<T> *node = root;
	print(node);
}

template<class T>
void Tree<T>::print(TreeNode<T> *node) //in order traversal
{
	if(node == NULL) return;

	print(node->left);
	cout << node->key << endl;
	print(node->right);
}


template<class T>
TreeNode<T>* Tree<T>::getMax()
{
	TreeNode<T> *curr = root;

	if(root == NULL)
    return NULL;

	while(curr->right != NULL){
		curr = curr->right;
	}
	return curr;
}

template<class T>
TreeNode<T>* Tree<T>::getMin()
{
	TreeNode<T> *curr = root;

	if(root == NULL)
    return NULL;

	while(curr->left != NULL){
		curr = curr->left;
	}

	return curr;
}

template<class T>
void Tree<T>::insert(int k, T d)
{
	if(this->contains(k))
	{
		cout << "This key already exists in the tree";
		throw 1;
	}

	TreeNode<T> *node = new TreeNode<T>(k, d);

	if(root == NULL) root = node; //if empty tree

	else
	{
		TreeNode<T> *curr = root;
		TreeNode<T> *parent;

		while(true) //iterate to find insertion point
		{
			parent = curr;

			if(k < curr->key) //go left
			{
				curr = curr->left;
				if (curr == NULL) //found insertion point
				{
					parent->left = node;
					break;
				}
			}

			else
			{
				if(node->key > curr->key)
				{
					curr = curr->right;

					if (curr == NULL) //found insertion point
					{
						parent->right = node;
						break;
					}
				}
			}
		}
	}
}

template<class T>
bool Tree<T>::contains(int k)
{
	if(root == NULL) return false;

	else{
		TreeNode<T> *curr = root;

		while(curr->key != k){
			if(k < curr->key){
        curr = curr->left;
			}
			else{
        curr = curr->right;
			}

			if(curr == NULL){
        return false;
			}
		}
	}
	return true;
}

 template <class T>
 T* Tree<T>::find(int k)
 {
    if(root == NULL){
			 return NULL;
		 }
    if(contains(k))
    {
    	TreeNode<T> *curr = root;
    	while(curr->key != k)
    	{
        	if(k < curr->key){
            curr = curr->left;

					}
        	else{
            curr = curr->right;
					}

        	if(curr == NULL){
            return NULL;
					}
      	}
      	T* temp = &curr->data;
    	return temp;
    }

    else{
			return NULL;
		}

  }

template<class T>
bool Tree<T>::deleteNode(int k)
{
	if(root == NULL) return false; //empty TreeNode

	else
	{
		bool isLeft = true;
		TreeNode<T> *curr = root;
		TreeNode<T> *parent = root;

		//leverage the contains method
		while(curr->key != k)
		{
			parent = curr;
			if(k < curr->key)
			{
				curr = curr->left;
				isLeft = true;
			}
			else
			{
				curr = curr->right;
				isLeft = false;
			}

			if(curr == NULL) return false;
		}

		//Once we are here we have found the node

		//no children
		if(curr->left == NULL && curr->right == NULL)
		{
			if(curr == root)
        root = NULL; //null out the root
			else if(isLeft)
        parent->left = NULL;
			else
        parent->right = NULL;
		}

		//one child

		//no right child
		else if(curr->right == NULL)
		{
			if(curr == root)
        root = curr->left;
			else if(isLeft)
        parent->left = curr->left;
			else
        parent->right = curr->left;
		}

		//no left child
		else if(curr->left == NULL)
		{
			if(curr == root)
        root = curr->right;
			else if(isLeft)
        parent->left = curr->right;
			else
        parent->left = curr->right;
		}

		//two children
		else
		{
			TreeNode<T> *successor = getSuccessor(curr);

			if(curr == root)
        root = successor;
			else if(isLeft)
        parent->left = successor;
			else
        parent->right = successor;

			//connect left child
			successor->left = curr->left;
		}
	}
	return true;
}

template <class T>
TreeNode<T>* Tree<T>::getSuccessor(TreeNode<T> *d) //d is the node to be deleted
{
	TreeNode<T> *sp = d; //successor parent
	TreeNode<T> *successor = d;
	TreeNode<T> *curr = d->right;

	//loop until we find successor which will be one right all the way left
	while(curr != NULL)
	{
		sp = successor;
		successor = curr;
		curr = curr->left;
	}

	if(successor != d->right) //descendant of right child
	{
		sp->left = successor->right;
		successor->right = d->right;
	}
	return successor;
}

#endif
