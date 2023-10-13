#pragma once
#include <iostream>

template <class T>
class AVLNode
{
public:
	AVLNode(T value);

	~AVLNode() {}

	void setData(T data);
	void setHeight(int height);
	void setRightPtr(AVLNode* rightptr);
	void setLeftPtr(AVLNode* leftptr);

	T getData();
	int getHeight();
	AVLNode<T>* getLeftPtr();
	AVLNode<T>* getRightPtr();



private:

	AVLNode* leftptr;
	AVLNode* rightptr;
	int height;
	T data;

};

template <class T>
AVLNode<T>::AVLNode(T value)
{
	this->height = 0;
	this->leftptr = NULL;
	this->rightptr = NULL;
	this->data = value;
}


template <class T>
T AVLNode<T>::getData()
{
	return this->data;
}


template <class T>
int AVLNode<T>::getHeight()
{
	return this->height;
}


template <class T>
AVLNode<T>* AVLNode<T>::getLeftPtr()
{
	return this->leftptr;
}


template <class T>
AVLNode<T>* AVLNode<T>::getRightPtr()
{
	return this->rightptr;
}


template <class T>
void AVLNode<T>::setLeftPtr(AVLNode<T>* leftptr)
{
	this->leftptr = leftptr;
}


template <class T>
void AVLNode<T>::setRightPtr(AVLNode<T>* rightptr)
{
	this->rightptr = rightptr;
}


template <class T>
void AVLNode<T>::setData(T data)
{
	this->data = data;
}


template <class T>
void AVLNode<T>::setHeight(int height)
{
	this->height = height;
}