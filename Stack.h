#pragma once
#include "BinaryTreeNode.h"
#include <iostream>
template<class T>
class Stack
{
public:
	BinaryTreeNode<T>* top;

	Stack(T data);
	Stack();
	~Stack();

	void Push(T data);
	T Pop();
	bool IsEmpty();
	void Display();
};

template<class T>
Stack<T>::Stack(T data)
{
	top = new BinaryTreeNode<T>(data);
}

template<class T>
 Stack<T>::Stack()
{
	 top = nullptr;
}

 template<class T>
 Stack<T>::~Stack()
 {
	 while (top != nullptr)
	 {
		 BinaryTreeNode<T>* rLinkNode = top->rLink;
		 delete(top);
		 top = rLinkNode;
	 }
 }

template<class T>
void Stack<T>::Push(T data)
{
	if (top == nullptr)
	{
		top = new BinaryTreeNode<T>(data);
	}

	else
	{
		BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(data);
		newNode->rLink = top;
		top = newNode;
	}
}

template<class T>
T Stack<T>::Pop()
{
	if (IsEmpty()) throw "Stack is empty aq";

	else
	{
		T dataToReturn = top->data;
		BinaryTreeNode<T>* nodeToDelete = top;
		top = top->rLink;
		delete(nodeToDelete);
		return dataToReturn;
	}
}

template<class T>
bool Stack<T>::IsEmpty()
{
	return top == nullptr;
}

template<class T>
void Stack<T>::Display()
{
	printf("\n");
	while (top != nullptr)
	{
		printf("%d, ", top->data);
		top = top->rLink;
	}
	printf("\n");
}

