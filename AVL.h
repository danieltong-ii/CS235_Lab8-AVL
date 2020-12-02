#pragma once
#include "AVLInterface.h"
#include "Node.h"
#include <iostream>

using namespace std;

class AVL: public AVLInterface {
protected:
	Node *root;
	bool success = true;
public:
	AVL() {
		root = NULL;
	}
	virtual ~AVL() {
		clear();
	}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * getRootNode() const;

	/*
	* Attempts to add the given int to the AVL tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);
	bool rebalance(Node*& node);

	/*
	* Attempts to remove the given int from the AVL tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();
	void recursiveClear(Node *node);

	void rightRotate(Node *& node);
	void leftRotate(Node *& node);
	int updateHeight(Node*&X);
private:
	bool add(int data,Node*&node);
	bool remove(int data, Node *&node);
};
