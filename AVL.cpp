#include "BST.h"

using namespace std;

//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
NodeInterface * BST::getRootNode() const {
	cout << "getRootNode" << endl;
	return this->root;

};

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data){
	if (root == NULL) {
		cout << "root is NULL" << endl;
	}
	return add(data, this->root);

};

bool BST::add(int data, Node *&node){
	cout << "datais :" << data;
	if (node == NULL) {
		node = new Node(data);
		cout << "just made a new node with data: " << data << endl;
		return true;
	} else if (node->getData() == data) {
		return false;
	} else if (data < node->getData()) {
		return add(data, node->getLeft());
	}
	else {
		return add(data, node->getRight());
	}
};

/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int data){
	cout << "in remove" << endl;
	return remove(data,this->root);
};

bool BST::remove(int data, Node *&node){
	cout << "we need to delete: " << data << endl;
	if (node == NULL) { //node doesn't exist
		cout << "the node was NULL" << endl;
		return false;
	}
	else if (node->getData()==data) { // program found the node with the right "data" to be removed
		if ((node->getLeft() != NULL && (node->getRight() == NULL))) {
			Node * temp = node;
			node = node->getLeft();
			delete(temp);
			temp = NULL;
			return true;
		}
		else if ((node->getLeft() == NULL && (node->getRight() != NULL))) {
			Node * temp = node;
			node = node->getRight();
			delete(temp);
			temp = NULL;
			return true;
		}
		else if ((node->getLeft() == NULL && (node->getRight() == NULL))) {
			delete(node);
			node = NULL;
			return true;
		}
		else if ((node->getLeft() != NULL && (node->getRight() != NULL))) {
			Node * it_node = node;
			Node * old_root = node;
			it_node = it_node->getLeft();
			while (it_node->getRight() != NULL) {
				it_node = it_node->getRight(); //finds the furthest right node on the left side
			}
			node->modifyData(node,it_node->getData());
			cout << "it_node value is: " << it_node->getData() << endl;
			remove(it_node->getData(),old_root->getLeft());
			it_node = NULL;
			return true;
		}
	}
	else {
		if (data < node->getData()) { // Data is smaller than current node
			cout << data << " is smaller than " << node->getData() << endl;
			return remove(data,node->getLeft());
		}
		else if (data > node->getData()) { //Data is larger than current node
			cout << data << " is larger than " << node->getData() << endl;
			return remove(data,node->getRight());
		}
	}
return success;
};

void BST::clear(){
	recursiveClear(this->root);
	this->root = NULL;
};

void BST::recursiveClear(Node *node) {
	if (node != NULL) {
		recursiveClear(node->getLeft());
		recursiveClear(node->getRight());
		delete node;
	}
}
