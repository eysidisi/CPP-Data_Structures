#pragma once
#include "Node.h"
#include <iostream>
template<class T>
class Stack
{
public:
	Node<T>* top;

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
	top = new Node<T>(data);
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
		 Node<T>* rLinkNode = top->rLink;
		 delete(top);
		 top = rLinkNode;
	 }
 }

template<class T>
void Stack<T>::Push(T data)
{
	if (top == nullptr)
	{
		top = new Node<T>(data);
	}

	else
	{
		Node<T>* newNode = new Node<T>(data);
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
		Node<T>* nodeToDelete = top;
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

