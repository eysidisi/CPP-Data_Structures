#pragma once
#include <algorithm>    // std::max

template<class T>
class BinaryTreeNode
{
public:
	BinaryTreeNode* lLink;
	BinaryTreeNode* rLink;
	T data;
	int height;
public:
	BinaryTreeNode(T data);
	BinaryTreeNode();
	int FindHeight(BinaryTreeNode<T>* node );
	int FindBalanceFactor(BinaryTreeNode<T>* node );
};

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(T data)
	: data(data)
{
	rLink = lLink = nullptr;
}

template<class T>
inline BinaryTreeNode<T>::BinaryTreeNode()
{
	rLink = lLink = nullptr;
}

template<class T>
int BinaryTreeNode<T>::FindHeight(BinaryTreeNode<T>* node)
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
int BinaryTreeNode<T>::FindBalanceFactor(BinaryTreeNode<T>* node)
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



