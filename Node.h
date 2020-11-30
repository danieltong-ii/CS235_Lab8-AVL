#pragma once
#include "NodeInterface.h"
#include <string>

using namespace std;

class Node: public NodeInterface {

public:
	Node() {
	}
	Node(int value) {
		data = value;
		leftChild = NULL;
		rightChild = NULL;
	}
	~Node() {}
	int getData() const;
	NodeInterface * getRightChild() const;
	NodeInterface * getLeftChild() const;
	void modifyData(Node*& node, int number);
	Node *& getRight();
	Node *& getLeft();
protected:
	Node *leftChild;
	Node *rightChild;
	int data;

};
