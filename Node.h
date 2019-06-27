#pragma once
#include <algorithm>    // std::max

template<class T>
class Node
{
public:
	Node* lLink;
	Node* rLink;
	T data;
	int height;
public:
	Node(T data);
	Node();
	int FindHeight(Node<T>* node );
	int FindBalanceFactor(Node<T>* node );
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

template<class T>
int Node<T>::FindHeight(Node<T>* node)
{
	
	int rHeight = 0;
	int lHeight = 0;

	if (node->rLink != nullptr)
	{
		rHeight = FindHeight(node->rLink) + 1;
	}

	if (node->lLink != nullptr)
	{
		lHeight = FindHeight(node->lLink) + 1;
	}

	return ( height=std::max(rHeight, lHeight));
}

template<class T>
int Node<T>::FindBalanceFactor(Node<T>* node)
{


	int rHeight = 0;
	int lHeight = 0;
	
	if (node != nullptr)
	{
		if (node->rLink != nullptr)
		{
			rHeight = FindHeight(node->rLink) + 1;
		}

		if (node->lLink != nullptr)
		{
			lHeight = FindHeight(node->lLink) + 1;
		}
	}

	return (lHeight - rHeight);
}



