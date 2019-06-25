#pragma once
template<class T>
class Node
{
public:
	Node* lLink;
	Node* rLink;
	T data;

public:
	Node(T data);
	Node();

};

template<class T>
Node<T>::Node(T data)
	: data(data)
{
	rLink = lLink = nullptr;
}

template<class T>
inline Node<T>::Node()
{
	rLink = lLink = nullptr;
}

