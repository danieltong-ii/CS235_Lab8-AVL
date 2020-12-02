#pragma once
#include "NodeInterface.h"
#include <string>

using namespace std;

class Node: public NodeInterface {
	friend class AVL;
public:
	Node() {
	}
	Node(int value) {
		data = value;
		leftChild = NULL;
		rightChild = NULL;
		height = 0;
	}
	~Node() {}
	int getData() const;
	int getHeight();
	NodeInterface * getRightChild() const;
	NodeInterface * getLeftChild() const;
	void modifyData(Node*& node, int number);
	Node *& getRight();
	Node *& getLeft();
protected:
	Node *leftChild;
	Node *rightChild;
	int data;
	int height;

};
