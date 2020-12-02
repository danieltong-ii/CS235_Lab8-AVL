#include "Node.h"
#include <string>
#include <iostream>

using namespace std;
/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData() const{
	return this->data;
};

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
NodeInterface*Node::getLeftChild() const{
	return (leftChild);
};

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
NodeInterface*Node::getRightChild() const{
	return (rightChild);
};

Node*&Node::getRight(){
	cout << "getRight" << endl;
	if (rightChild == NULL) {
		cout << "rightChild is NULL" << endl;
	}
	return (rightChild);
};
Node*&Node::getLeft(){
	cout << "getLeft" << endl;
	return (leftChild);
};

void Node::modifyData(Node*& node, int number){
	node->data = number;
};

int Node::getHeight(){
	cout << "getHeight" << endl;
	return height;
}
