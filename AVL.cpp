#include "AVL.h"

using namespace std;

//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
NodeInterface * AVL::getRootNode() const {
	cout << "getRootNode" << endl;
	return this->root;

};

/*
* Attempts to add the given int to the AVL tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool AVL::add(int data){
	if (root == NULL) {
		cout << "root is NULL" << endl;
	}
	return add(data, this->root);


};

bool AVL::add(int data, Node *&node){
	cout << "datais :" << data;
	if (node == NULL) { //only place where a new node is made and inserted
		node = new Node(data);
		cout << "just made a new node with data: " << data << endl;
		updateHeight(node);
		return true;
	} else if (node->data == data) {
		return false;
	} else if (data < node->data) {
		cout << "looking left" << endl;
		bool retval = add(data, node->leftChild); // updateheight here
		rebalance(node);
		node->height = updateHeight(node);
		return retval;
	}
	else {
		cout << "looking right" << endl;
		bool retval = add(data, node->rightChild); // updateheight here
		rebalance(node);
		node->height = updateHeight(node);
		return retval;
	}
};

bool AVL::rebalance(Node*& node){
	//Left imbalance
	cout << "rebalancing" << endl;
	//we need to make sure if getRight or getLeft is NULL, then the height is -1
	if ((node->rightChild != NULL) && (node->leftChild != NULL)) {
		cout << "the right height was: " << node->rightChild->height << endl;
		cout << "the left height was: " << node->leftChild->height << endl;
		if (((node->leftChild->height) - (node->rightChild->height)) >= 2) {
			cout << "height of left was greater than left by 2" << endl;
			if ((node->leftChild->leftChild->height) >= (node->leftChild->rightChild->height)) {
				//left-left imbalance = right rotation
				rightRotate(node);
			}
			else {
				//left-right imbalance
				leftRotate(node->leftChild);
				rightRotate(node);
			}
		}
		//Right imbalance
		else if (((node->rightChild->height) - (node->leftChild->height)) >= 2) {
			if ((node->rightChild->rightChild->height) >= (node->rightChild->leftChild->getHeight())) {
				//right-right imbalance
				leftRotate(node);
			}
			else {
				rightRotate(node->rightChild);
				leftRotate(node);
			}
		}
		else {
			cout << "the node was balanced";
		}
	}
	else {
		cout << "either the height of the left or right child was NULL" << endl;
		int leftHeight = -1;
		int rightHeight = -1;

		if (node->rightChild != NULL) {
			rightHeight = node->rightChild->height;
		}
		if (node->leftChild != NULL) {
			leftHeight = node->leftChild->height;
		}
		if (leftHeight - rightHeight >= 2) {
			cout << "left imbalance" << endl;
			int leftRightHeight = -1;
			if (node->leftChild->rightChild != NULL) {
				leftRightHeight = node->leftChild->rightChild->height;
			}
			if (node->leftChild->leftChild->height > leftRightHeight) {
				cout << "**right rotate time" << endl;
				rightRotate(node);
				cout << node->leftChild->data << node->rightChild->data << endl;
			}
			else {
				leftRotate(node->leftChild);
				rightRotate(node);
			}
		}
		else if (rightHeight - leftHeight >= 2) {
			cout << "right imbalance" << endl;
			int rightLeftHeight = -1;
			if (node->rightChild->leftChild != NULL) {
				rightLeftHeight = node->rightChild->leftChild->height;
			}
			if (node->rightChild->rightChild->height > rightLeftHeight) {
				leftRotate(node);
			}
			else {
				rightRotate(node->rightChild);
				leftRotate(node);
			}
		}
		else {
			// cout << "the right height was: " << node->rightChild->height << endl;
			// cout << "the left height was: " << node->leftChild->height << endl;
			cout << "the node was balanced" << endl;

		}
	}
};

void AVL::leftRotate(Node *& X){
	Node * newRoot = X->rightChild;
	X->rightChild = newRoot->leftChild;
	newRoot->leftChild = X;
	X = newRoot;
	X->leftChild->height = updateHeight(X->leftChild);
	X->height = updateHeight(X);

};
void AVL::rightRotate(Node *& X){
	Node * newRoot = X->leftChild;
	X->leftChild = newRoot->rightChild;
	newRoot->rightChild = X;
	X = newRoot;
	X->rightChild->height = updateHeight(X->rightChild);
	X->height = updateHeight(X);


};

int AVL::updateHeight(Node*&X){
	int Lheight = -1;
	int Rheight = -1;
	int newHeight = 0;
	if (X->leftChild != NULL) {
		Lheight = X->leftChild->height;
	}
	if (X->rightChild != NULL) {
		Rheight = X->rightChild->height;
	}
	newHeight = 1 + max(Lheight,Rheight);
	return newHeight;
}

/*
* Attempts to remove the given int from the AVL tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool AVL::remove(int data){
	cout << "in remove" << endl;
	return remove(data,this->root);
};

bool AVL::remove(int data, Node *&node){
	cout << "we need to delete: " << data << endl;
	if (node == NULL) { //node doesn't exist
		cout << "the node was NULL" << endl;
		return false;
	}
	else if (node->data==data) { // program found the node with the right "data" to be removed
		if ((node->leftChild != NULL && (node->rightChild == NULL))) {
			Node * temp = node;
			node = node->leftChild;
			delete(temp);
			temp = NULL;
			return true;
		}
		else if ((node->leftChild == NULL && (node->rightChild != NULL))) {
			Node * temp = node;
			node = node->rightChild;
			delete(temp);
			temp = NULL;
			return true;
		}
		else if ((node->leftChild == NULL && (node->rightChild == NULL))) {
			delete(node);
			node = NULL;
			return true;
		}
		else if ((node->leftChild != NULL && (node->rightChild != NULL))) {
			Node * it_node = node;
			Node * old_root = node;
			it_node = it_node->leftChild;
			while (it_node->rightChild != NULL) {
				it_node = it_node->rightChild; //finds the furthest right node on the left side
			}
			node->modifyData(node,it_node->data);
			cout << "it_node value is: " << it_node->data << endl;
			remove(it_node->data,old_root->leftChild);
			it_node = NULL;
			return true;
		}
	}
	else {
		if (data < node->data) { // Data is smaller than current node
			cout << data << " is smaller than " << node->data << endl;
			return remove(data,node->leftChild);
		}
		else if (data > node->data) { //Data is larger than current node
			cout << data << " is larger than " << node->data << endl;
			return remove(data,node->rightChild);
		}
	}
};

void AVL::clear(){
	recursiveClear(this->root);
	this->root = NULL;
};

void AVL::recursiveClear(Node *node) {
	if (node != NULL) {
		recursiveClear(node->leftChild);
		recursiveClear(node->rightChild);
		delete node;
	}
}
