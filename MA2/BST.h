#pragma once
#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
#include <queue>

using namespace std;


/*
 *  Data structure for a single tree node
 */
template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor

	/**
	 * Destructor - Needs to free *all* nodes in the tree
	 * TODO: Implement Destructor
	 */
	~BST() {
		destroyTree(_root);
	}

	//adding a function for recursive destructor
	void destroyTree(Node<T>* mpRoot)
	{
		if (mpRoot != NULL)
		{
			destroyTree(mpRoot->left);
			destroyTree(mpRoot->right);
			delete mpRoot;
		}
	}

	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}

	
	void printLevelOrder()  //queue method taken from geeksforgeeks, was trying iterative and it wasnt working out
	{
		queue<Node<T>*> q;
		q.push(this->_root);
		while (q.empty() == false)
		{
			int nodes = q.size();

			while (nodes > 0)
			{
				Node<T>* node = q.front();
				q.pop();
				if (node->left != NULL)
				{
					q.push(node->left);
				}
				if (node->right != NULL)
				{
					q.push(node->right);
				}
				nodes--;
			}
			cout << endl;
		}

	}

	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	/**
	 * Print the maximum path in this tree
	 * TODO: Implement printMaxPath
	 */
	void printMaxPath()
	{
		printMaxPathHelper(this->_root);
	}

	void printMaxPathHelper(Node<T> *mpRoot) { //need helper function to do recursively

		if (mpRoot == NULL)
		{
			return;
		}

		cout << mpRoot->value << endl;
		if (heightHelper(mpRoot->left) > heightHelper(mpRoot->right))
		{
			printMaxPathHelper(mpRoot->left);
		}
		else
		{
			printMaxPathHelper(mpRoot->right);
		}
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}

	/**
	 * Find if the BST contains the value
	 * TODO: Implement contains
	 */
	bool contains(T value) {
		return containsHelper(this->_root, value);
	}

	bool containsHelper(Node<T>* mpRoot, T value)
	{
		if (mpRoot == NULL)
		{
			return false;
		}
		else if (mpRoot->value == value)
		{
			return true;
		}
		else if (mpRoot->value > value) //go left
		{
			containsHelper(mpRoot->left, value);
		}
		else //go right
		{
			containsHelper(mpRoot->right, value);
		}

	}
};

#endif

