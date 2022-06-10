#ifndef _AVLTREE_H
#define _AVLTREE_H

#include <cmath>
#include <sstream>
#include <string>
#include <iostream>

using std::stringstream;
using std::string;

const static int MAX_IMBAL = 2;

template<class T>
class AVLTree;


template<class T>
class AVLNode {

public:
	friend class AVLTree<T>;
	AVLNode();
	AVLNode(const T& newData);
	AVLNode(const T& element, int theHeight);
	~AVLNode();
private:
	AVLNode<T>* left;
	AVLNode<T>* right;
	const T& data;
	int leftHeight;
	int rightHeight;
	int height();
};


template<class T>
class AVLTree {

public:
	friend class AVLNode<T>;
	AVLTree();
	AVLTree(const T& element);
	~AVLTree();
	void insert(const T& element);
	bool remove(const T& element);
	const T* find(const T& element);
	const T* findMax();
	const T* findMin();
	int size();
	const string inOrderTraversal();
	void clear();

private:
	AVLNode<T>* root;
	int treeSize;

	void delete_traversal(AVLNode<T>* subRoot);
	AVLNode<T>* insert(AVLNode<T>* subRoot, const T& element);
	AVLNode<T>* remove(AVLNode<T>* subRoot, const T& element, bool* val);
	AVLNode<T>* balance(AVLNode<T>* subRoot);
	AVLNode<T>* singleRotateRightChild(AVLNode<T>* subRoot);
	AVLNode<T>* singleRotateLeftChild(AVLNode<T>* subRoot);
	const T* find(AVLNode<T>* subRoot, const T& element);
	AVLNode<T>* findMin(AVLNode<T>* subRoot);
	AVLNode<T>* findMax(AVLNode<T>* subRoot);
	void inOrderTraversal(AVLNode<T>* subRoot, string& output, int depth);
};


template<class T>
AVLTree<T>::AVLTree() {
	root = NULL;
	treeSize = 0;
}


template<class T>
AVLTree<T>::AVLTree(const T& element) {
	root = new AVLNode<T>(element);
	treeSize = 1;
}


template<class T>
AVLTree<T>::~AVLTree() {

	delete_traversal(root);
}


template<class T>
void AVLTree<T>::delete_traversal(AVLNode<T>* subRoot) {

	if (!subRoot)
		return;

	delete_traversal(subRoot->left);
	delete_traversal(subRoot->right);
	delete subRoot;
}


template<class T>
void AVLTree<T>::insert(const T& element) {

	root = insert(root, element);
	treeSize++;
}


template<class T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* subRoot, const T& element) {

	AVLNode<T>* returnValue = subRoot;

	if (!subRoot) {

		returnValue = new AVLNode<T>(element);
	}
	else if (element >= subRoot->data) {

		subRoot->right = insert(subRoot->right, element);
		subRoot->rightHeight++;
	}
	else {

		subRoot->left = insert(subRoot->left, element);
		subRoot->leftHeight++;
	}

	return balance(returnValue);
}


template<class T>
bool AVLTree<T>::remove(const T& element) {

	if (!root) {

		return false;
	}
	else {

		bool val = true;
		root = remove(root, element, &val);
		return val;
	}
}


template<class T>
AVLNode<T>* AVLTree<T>::remove(AVLNode<T>* subRoot, const T& element, bool* val) {

	AVLNode<T>* returnValue;

	if (!subRoot) {

		*val = false;
		returnValue = NULL;
	}
	else if (subRoot->data == element) {

		treeSize--;

		if (!subRoot->left && !subRoot->right) {

			delete subRoot;
			returnValue = NULL;
		}
		
		else if (subRoot->left && subRoot->right) {

			AVLNode<T>* maxLeft = findMax(subRoot->left);
			AVLNode<T>* newSubRoot = new AVLNode<T>(maxLeft->data);
			newSubRoot->left = remove(subRoot->left, maxLeft->data, val);
			newSubRoot->right = subRoot->right;
			newSubRoot->leftHeight = subRoot->leftHeight;
			newSubRoot->rightHeight = subRoot->rightHeight;
			newSubRoot->leftHeight--;
			treeSize++;

			delete subRoot;
			returnValue = newSubRoot;
		}
		
		else {

			AVLNode<T>* temp = (subRoot->right) ? subRoot->right : subRoot->left;

			delete subRoot;
			returnValue = temp;
		}
	}
	else if (element >= subRoot->data) {

		subRoot->right = remove(subRoot->right, element, val);
		
		if (*val)
			subRoot->rightHeight--;
		returnValue = subRoot;
	}
	else {

		subRoot->left = remove(subRoot->left, element, val);
		
		if (*val)
			subRoot->leftHeight--;
		returnValue = subRoot;
	}

	return balance(returnValue);
}


template<class T>
AVLNode<T>* AVLTree<T>::balance(AVLNode<T>* subRoot) {

	AVLNode<T>* returnValue = subRoot;

	if (!subRoot) {

		returnValue = subRoot;
	}
	
	else if (subRoot->leftHeight - subRoot->rightHeight > MAX_IMBAL) {

		
		if (subRoot->left->leftHeight >= subRoot->left->rightHeight) {

			returnValue = singleRotateLeftChild(subRoot);
		}
		
		else {

			subRoot->left = singleRotateRightChild(subRoot->left);
			returnValue = singleRotateLeftChild(subRoot);
		}
	}
	
	else if (subRoot->rightHeight - subRoot->leftHeight > MAX_IMBAL) {

		
		if (subRoot->right->rightHeight >= subRoot->right->leftHeight) {

			returnValue = singleRotateRightChild(subRoot);
		}
		
		else {

			subRoot->right = singleRotateLeftChild(subRoot->right);
			returnValue = singleRotateRightChild(subRoot);
		}
	}

	return returnValue;
}


template<class T>
AVLNode<T>* AVLTree<T>::singleRotateLeftChild(AVLNode<T>* subRoot) {

	AVLNode<T>* temp = subRoot->left;
	subRoot->left = temp->right;
	subRoot->leftHeight = temp->rightHeight;
	temp->right = subRoot;
	temp->rightHeight = subRoot->height() + 1;

	return temp;
}


template<class T>
AVLNode<T>* AVLTree<T>::singleRotateRightChild(AVLNode<T>* subRoot) {

	AVLNode<T>* temp = subRoot->right;
	subRoot->right = temp->left;
	subRoot->rightHeight = temp->leftHeight;
	temp->left = subRoot;
	temp->leftHeight = subRoot->height() + 1;

	return temp;
}


template<class T>
const T* AVLTree<T>::find(const T& element) {

	return find(root, element);
}


template<class T>
const T* AVLTree<T>::find(AVLNode<T>* subRoot, const T& element) {

	if (!subRoot)
		return NULL;
	else if (subRoot->data == element)
		return &subRoot->data;
	else if (subRoot->data > element)
		return find(subRoot->left, element);
	else
		return find(subRoot->right, element);
}


template<class T>
const T* AVLTree<T>::findMin() {

	if (!root)
		return NULL;
	return findMin(root)->data;
}


template<class T>
AVLNode<T>* AVLTree<T>::findMin(AVLNode<T>* subRoot) {

	if (subRoot->left)
		return findMin(subRoot->left);
	else
		return subRoot;
}


template<class T>
const T* AVLTree<T>::findMax() {

	if (!root)
		return NULL;
	return findMax(root)->data;
}


template<class T>
AVLNode<T>* AVLTree<T>::findMax(AVLNode<T>* subRoot) {

	if (subRoot->right)
		return findMax(subRoot->right);
	else
		return subRoot;
}


template<class T>
const string AVLTree<T>::inOrderTraversal() {

	string output;

	if (root)
		inOrderTraversal(root, output, 0);
	else
		output += "--|";

	return output;
}


template<class T>
void AVLTree<T>::inOrderTraversal(AVLNode<T>* subRoot, string& output, int depth) {

	stringstream ss;

	if (!subRoot)
		return;

	if (subRoot->left)
		inOrderTraversal(subRoot->right, output, depth + 1);

	for (int i = 0; i < depth; i++)
		output += "----";
	output += "|";
	ss << subRoot->data;
	output += ss.str();
	output += "\n";

	if (subRoot->right)
		inOrderTraversal(subRoot->left, output, depth + 1);
}


template<class T>
int AVLTree<T>::size() {
	return treeSize;
}


template<class T>
void AVLTree<T>::clear() {

	delete_traversal(root);
	root = NULL;
	treeSize = 0;
}


template<class T>
AVLNode<T>::AVLNode(const T& element) : data(element) {

	leftHeight = 0;
	rightHeight = 0;
	left = NULL;
	right = NULL;
}


template<class T>
AVLNode<T>::~AVLNode() {

	left = NULL;
	right = NULL;
}


template<class T>
int AVLNode<T>::height() {

	return leftHeight + rightHeight;
}

#endif _AVLTREE_H
