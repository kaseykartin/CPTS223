#pragma once
#include <iostream>
#include "AVLNode.h"

using namespace std;

template <class T>
class AVLTree {

public:
	AVLTree() : rootptr(nullptr) {};
	~AVLTree() {};
	
	int height(AVLNode<T>* rootptr);

	void insert(T value, AVLNode<T>*& root);

	int contains(T data, AVLNode<T>* root);

	int validate(AVLNode<T>* root);

	void leftRotate(AVLNode<T>* &k2);
	void rightRotate(AVLNode<T>* &k2);

	void doubleLeftRotate(AVLNode<T>* &k3);
	void doubleRightRotate(AVLNode<T>* &k3);

	//AVLNode<T>* getRootPtr();


	AVLNode<T>* rootptr;

private:

	//AVLNode<T>* rootptr;

};

template <class T>
int AVLTree<T>::height(AVLNode<T>* rootptr)
{
	if (rootptr->getHeight() == NULL)
	{
		return -1;
	}
	else
	{
		return rootptr->getHeight();
	}
}

template <class T> //class examples used for rotation functions
void AVLTree<T>::leftRotate(AVLNode<T>*& k2)
{
	AVLNode<T>* k1 = k2->getLeftPtr();
	k2->setLeftPtr(k1->getRightPtr());
	k1->setRightPtr(k2);
	k2->setHeight(max(height(k2->getLeftPtr()), height(k2->getRightPtr())) + 1);
	k1->setHeight(max(height(k1->getLeftPtr()), k2->getHeight()) + 1);
	k2 = k1;
}

template <class T>
void AVLTree<T>::rightRotate(AVLNode<T>*& k2)
{
	AVLNode<T>* k1 = k2->getRightPtr();
	k2->setRightPtr(k1->getLeftPtr());
	k1->setLeftPtr(k2);
	k2->setHeight(max(height(k2->getRightPtr()), height(k2->getLeftPtr())) + 1);
	k1->setHeight(max(height(k1->getRightPtr()), k2->getHeight()) + 1);
	k2 = k1;
}

template <class T>
void AVLTree<T>::doubleLeftRotate(AVLNode<T>*& k3)
{
	rightRotate(k3->getLeftPtr());
	leftRotate(k3);
}

template <class T>
void AVLTree<T>::doubleRightRotate(AVLNode<T>*& k3)
{
	leftRotate(k3->getRightPtr());
	rightRotate(k3);
}

template <class T>
void AVLTree<T>::insert(T data, AVLNode<T>*& root)
{
	if (root == NULL)
	{
		root = new AVLNode<T>(data);
	}
	else if (data < root->getData())
	{
		insert(data, root->getLeftPtr());
		if (height(root->getLeftPtr()) - height(root->getRightPtr()) == 2)
		{
			if (data < root->getLeftPtr()->getData())
			{
				leftRotate(root);
			}
			else
			{
				doubleLeftRotate(root);
			}
		}
	}
	else if (data > root->getData())
	{
		insert(data, root->getRightPtr());
		if (height(root->getRightPtr()) - height(root->getLeftPtr()) == 2)
		{
			if (data > root->getRightPtr()->getData())
			{
				rightRotate(root);
			}
			else
			{
				doubleRightRotate(root);
			}
		}
	}
	else //duplicate
	{
		root->setHeight(max(height(root->getLeftPtr()->getData()), height(root->getRightPtr()->getData())) + 1);
	}
}

template <class T>
int AVLTree<T>::contains(T data, AVLNode<T>* root)
{
	if (root->getData() == data)
	{
		return 1; //found
	}
	else if (data < root->getData())
	{
		return contains(data, root->getLeftPtr()); //repeats function with root's left node
	}
	else if (data > root->getData())
	{
		return contains(data, root->getRightPtr()); //repeats function with root's right node
	}
	else
	{
		return 0; //not found
	}
}

template <class T>
int AVLTree<T>::validate(AVLNode<T>* root)
{
	if (root == NULL)
	{
		return 1; //empty tree, techincally balanced
	}
	int leftHeight = root->getLeftPtr()->getHeight();
	int rightHeight = root->getRightPtr()->getHeight();

	if (abs(leftHeight - rightHeight) <= 1)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}
