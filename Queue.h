#pragma once
#include "Node.h"

template<class T>
class Queue
{
	Node<T>* front;
	Node<T>* rear;

public:
	Queue();
	~Queue();
	void Enqueue(T data);
	T Dequeue();
	T Peek();
	bool IsEmpty();
	void Display();
};


template<class T>
Queue<T>::Queue()
{
	front = rear = nullptr;
}

template<class T>
Queue<T>::~Queue()
{
	while (rear != nullptr)
	{
		Node<T>* tempNode = rear->rLink;
		delete(rear);
		rear = tempNode;
	}
}

template<class T>
void Queue<T>::Enqueue(T data)
{
	if (front == nullptr)
	{
		front = rear = new Node<T>(data);
	}

	else
	{
		Node<T>* newNode = new Node<T>(data);
		front->rLink = newNode;
		newNode->lLink = front;
		front = newNode;
	}
}

template<class T>
T Queue<T>::Dequeue()
{
	if (IsEmpty()) throw "Empty queue";

	T dataToReturn = rear->data;

	if (rear->rLink == nullptr)
	{
		delete(rear);
		rear = front = nullptr;
	}

	else
	{
		Node<T>* nodeToDelete = rear;
		rear = rear->rLink;
		delete(nodeToDelete);
	}

	return dataToReturn;
}

template<class T>
T Queue<T>::Peek()
{
	if (IsEmpty()) throw "Empty queue";

	return (rear->data);

}

template<class T>
bool Queue<T>::IsEmpty()
{
	return rear == nullptr;
}

template<class T>
void Queue<T>::Display()
{
	while (rear != nullptr)
	{
		printf("%d, ", rear->data);
		rear = rear->rLink;
	}
}
