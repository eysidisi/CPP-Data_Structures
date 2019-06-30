#pragma once
#include "BinaryTreeNode.h"
#include "Stack.h"
#include "Queue.h"

template<class T>
class BinaryTree
{
	Queue<BinaryTreeNode<T>*>* queue;
public:
	BinaryTree();

	~BinaryTree();

	void Add(T* arr, int size);

	void Add(T element);

	void PreorderTraversal(BinaryTreeNode<T>* node);

	BinaryTreeNode<T>* root;

	void PostorderTraversal(BinaryTreeNode<T>* node);

	void InorderTraversal(BinaryTreeNode<T>* node);

	void LevelorderTraversal();

	int Count(BinaryTreeNode<T>* node);

	int CalcHeight(BinaryTreeNode<T>* node);

	int CalcNumOfLeafNodes(BinaryTreeNode<T>* node);

	BinaryTreeNode<T>* RecursiveBinarySearch(BinaryTreeNode<T>* node, T key);

	BinaryTreeNode<T>* IterativeBinarySearch(T key);

	bool InsertElementInBinaryTree(T key);

	BinaryTreeNode<T>* LLRotation(BinaryTreeNode<T>* node);

	BinaryTreeNode<T>* LRRotation(BinaryTreeNode<T>* node);

	BinaryTreeNode<T>* RRRotation(BinaryTreeNode<T>* node);

	BinaryTreeNode<T>* RLRotation(BinaryTreeNode<T>* node);

	BinaryTreeNode<T>* RecursiveInsertElementInBinaryTree(BinaryTreeNode<T>*& node, T key);

	BinaryTreeNode<T>* FindPrecessor(BinaryTreeNode<T>* node);

	BinaryTreeNode<T>* FindSuccessor(BinaryTreeNode<T>* node);

	BinaryTreeNode<T>* DeleteElement(T key, BinaryTreeNode<T>* node);

	void CreateBinarySearchTreeUsingPreorder(T arr[], int size);

	void CreateBinarySearchTreeUsingPostorder(T arr[], int size);

	void CheckAVLTree();

	BinaryTreeNode<T>* CheckAVLNode(BinaryTreeNode<T>* node);
};

template<class T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
	queue = new Queue<BinaryTreeNode<T>*>();
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
	Queue<BinaryTreeNode<T>*>* newQueue = new Queue<BinaryTreeNode<T>*>();

	if (root != nullptr)
		newQueue->Enqueue(root);

	BinaryTreeNode<int>* currentNode;

	while (!newQueue->IsEmpty())
	{
		currentNode = newQueue->Dequeue();

		if (currentNode->lLink != nullptr)
		{
			newQueue->Enqueue(currentNode->lLink);
		}

		if (currentNode->rLink != nullptr)
		{
			newQueue->Enqueue(currentNode->rLink);
		}

		delete(currentNode);
	}

	delete(newQueue);

	delete(queue);

}

template<class T>
void BinaryTree<T>::Add(T* arr, int size)
{
	if (root == nullptr)
	{
		root = new BinaryTreeNode<T>(arr[0]);
		queue->Enqueue(root);
	}


	BinaryTreeNode<T>* currentNode;

	for (size_t i = 1; i < size; i++)
	{
		currentNode = queue->Peek();

		if (currentNode->lLink == nullptr)
		{
			currentNode->lLink = new BinaryTreeNode<T>(arr[i]);

			queue->Enqueue(currentNode->lLink);
		}

		else if (currentNode->rLink == nullptr)
		{
			currentNode->rLink = new BinaryTreeNode<T>(arr[i]);

			queue->Enqueue(currentNode->rLink);

			queue->Dequeue();

		}


	}
}

template<class T>
void BinaryTree<T>::Add(T element)
{
	if (root == nullptr)
	{
		root = new BinaryTreeNode<T>(element);
		queue->Enqueue(root);
	}

	else
	{
		BinaryTreeNode<T>* currentNode;

		currentNode = queue->Peek();

		if (currentNode->lLink == nullptr)
		{
			currentNode->lLink = new BinaryTreeNode<T>(element);

			queue->Enqueue(currentNode->lLink);
		}

		else if (currentNode->rLink == nullptr)
		{
			currentNode->rLink = new BinaryTreeNode<T>(element);

			queue->Enqueue(currentNode->rLink);

			queue->Dequeue();

		}
	}
}

template<class T>
void BinaryTree<T>::PreorderTraversal(BinaryTreeNode<T>* node)
{
	if (node != nullptr)
	{
		printf("%d ", node->data);
		PreorderTraversal(node->lLink);
		PreorderTraversal(node->rLink);
	}
}

template<class T>
void BinaryTree<T>::PostorderTraversal(BinaryTreeNode<T>* node)
{
	if (node != nullptr)
	{
		PostorderTraversal(node->lLink);
		PostorderTraversal(node->rLink);
		printf("%d ", node->data);
	}

}

template<class T>
void BinaryTree<T>::InorderTraversal(BinaryTreeNode<T>* node)
{
	if (node != nullptr)
	{
		InorderTraversal(node->lLink);
		printf("%d ", node->data);
		InorderTraversal(node->rLink);
	}
}

template<class T>
void BinaryTree<T>::LevelorderTraversal()
{
	Queue<BinaryTreeNode<T>*>* newQueue = new Queue<BinaryTreeNode<T>*>();

	newQueue->Enqueue(root);

	BinaryTreeNode<int>* currentNode;

	while (!newQueue->IsEmpty())
	{
		currentNode = newQueue->Dequeue();

		printf("%d ", currentNode->data);

		if (currentNode->lLink != nullptr)
		{
			newQueue->Enqueue(currentNode->lLink);
		}

		if (currentNode->rLink != nullptr)
		{
			newQueue->Enqueue(currentNode->rLink);
		}
	}

	delete(newQueue);
}

template<class T>
int BinaryTree<T>::Count(BinaryTreeNode<T>* node)
{
	int x;
	int y;

	if (node != nullptr)
	{
		x = Count(node->lLink);
		y = Count(node->rLink);
		return(x + y + 1);
	}

	return 0;
}

template<class T>
int BinaryTree<T>::CalcHeight(BinaryTreeNode<T>* node)
{
	int x;
	int y;

	if (node != nullptr)
	{
		x = CalcHeight(node->lLink);
		y = CalcHeight(node->rLink);

		if (x > y)
			return x + 1;
		else
			return y + 1;
	}

	return 0;
	return 0;
}

template<class T>
inline int BinaryTree<T>::CalcNumOfLeafNodes(BinaryTreeNode<T>* node)
{
	int x;
	int y;

	if (node == nullptr) return 0;

	else if (node->lLink == nullptr && node->rLink == nullptr)
	{
		return 1;
	}

	else
	{
		x = CalcNumOfLeafNodes(node->lLink);
		y = CalcNumOfLeafNodes(node->rLink);
		return x + y;
	}

}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::RecursiveBinarySearch(BinaryTreeNode<T>* node, T key)
{
	if (node == nullptr) return nullptr;

	if (node->data == key)
	{
		return node;
	}

	else if (key > node->data)
	{
		RecursiveBinarySearch(node->rLink, key);
	}

	else
	{
		RecursiveBinarySearch(node->lLink, key);
	}
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::IterativeBinarySearch(T key)
{
	BinaryTreeNode <T>* currentNode = root;

	while (currentNode != nullptr)
	{
		if (currentNode->data == key)
		{
			return currentNode;
		}

		else if (key > currentNode->data)
		{
			currentNode = currentNode->rLink;
		}

		else
		{
			currentNode = currentNode->lLink;
		}
	}

	return nullptr;
}

template<class T>
bool BinaryTree<T>::InsertElementInBinaryTree(T key)
{
	if (root == nullptr)
	{
		root = new BinaryTreeNode<T>(key);
		return true;
	}

	BinaryTreeNode <T>* currentNode = root;
	BinaryTreeNode<T>* tailNode = root;

	bool onRightSide = false;

	while (currentNode != nullptr)
	{
		if (currentNode->data == key)
		{
			return false;
		}

		else if (key > currentNode->data)
		{
			onRightSide = true;
			tailNode = currentNode;
			currentNode = currentNode->rLink;
		}

		else
		{
			onRightSide = false;
			tailNode = currentNode;
			currentNode = currentNode->lLink;
		}
	}

	if (onRightSide)
	{
		tailNode->rLink = new BinaryTreeNode<T>(key);
	}

	else
	{
		tailNode->lLink = new BinaryTreeNode<T>(key);
	}

	return true;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::LLRotation(BinaryTreeNode<T>* node)
{
	BinaryTreeNode<T>* A = node;
	BinaryTreeNode<T>* B = A->lLink;
	A->lLink = B->rLink;

	B->rLink = A;

	if (A == root)
	{
		root = B;
	}


	return B;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::LRRotation(BinaryTreeNode<T>* node)
{
	BinaryTreeNode<T>* A = node;
	BinaryTreeNode<T>* B = A->lLink;
	BinaryTreeNode<T>* C = B->rLink;

	A->lLink = C->rLink;
	B->rLink = C->lLink;
	C->lLink = B;
	C->rLink = A;

	if (A == root)
	{
		root = C;
	}
	return C;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::RRRotation(BinaryTreeNode<T>* node)
{
	BinaryTreeNode<T>* A = node;
	BinaryTreeNode<T>* B = node->rLink;
	A->rLink = B->lLink;
	B->lLink = A;

	if (A == root)
	{
		root = B;
	}


	return B;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::RLRotation(BinaryTreeNode<T>* node)
{
	BinaryTreeNode<T>* A = node;
	BinaryTreeNode<T>* B = A->rLink;
	BinaryTreeNode<T>* C = B->lLink;

	A->rLink = C->lLink;
	B->lLink = C->rLink;
	C->rLink = B;
	C->lLink = A;

	if (A == root)
	{
		root = C;
	}


	return C;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::RecursiveInsertElementInBinaryTree(BinaryTreeNode<T>*& node, T key)
{
	if (node == nullptr)
	{
		node = new BinaryTreeNode<T>(key);
	}

	else if (key > node->data)
	{
		node->rLink = RecursiveInsertElementInBinaryTree(node->rLink, key);
	}

	else if (key < node->data)
	{
		node->lLink = RecursiveInsertElementInBinaryTree(node->lLink, key);
	}



	if (node->FindBalanceFactor(node) == 2 && node->FindBalanceFactor(node->lLink) == 1)
	{
		return LLRotation(node);
	}

	else if (node->FindBalanceFactor(node) == 2 && node->FindBalanceFactor(node->lLink) == -1)
	{
		return LRRotation(node);
	}

	else if (node->FindBalanceFactor(node) == -2 && node->FindBalanceFactor(node->rLink) == -1)
	{
		return RRRotation(node);
	}

	else if (node->FindBalanceFactor(node) == -2 && node->FindBalanceFactor(node->rLink) == 1)
	{
		return RLRotation(node);
	}

	return node;

}

template<class T>
inline BinaryTreeNode<T>* BinaryTree<T>::FindPrecessor(BinaryTreeNode<T>* node)
{
	if (node->rLink == nullptr)
		return node;
	else
		return FindPrecessor(node->rLink);
}

template<class T>
inline BinaryTreeNode<T>* BinaryTree<T>::FindSuccessor(BinaryTreeNode<T>* node)
{
	if (node->lLink == nullptr)
		return node;
	else
		return FindSuccessor(node->lLink);
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::DeleteElement(T key, BinaryTreeNode<T>* node)
{
	if (node == nullptr) return nullptr;

	if (key > node->data)
	{
		node->rLink = DeleteElement(key, node->rLink);
	}
	else if (key < node->data)
	{
		node->lLink = DeleteElement(key, node->lLink);
	}
	else
	{
		if (node->lLink == nullptr && node->rLink == nullptr)
		{
			delete(node);
			return nullptr;
		}

		if (node->lLink != nullptr)
		{
			BinaryTreeNode<T>* p = FindPrecessor(node->lLink);
			node->data = p->data;
			node->lLink = DeleteElement(p->data, p);
		}
		else
		{
			BinaryTreeNode<T>* p = FindSuccessor(node->rLink);
			node->data = p->data;
			node->rLink = DeleteElement(p->data, p);
		}

	}

	return node;

}

template<class T>
void BinaryTree<T>::CreateBinarySearchTreeUsingPreorder(T arr[], int size)
{
	Stack<BinaryTreeNode<T>*> stack;
	root = new BinaryTreeNode<T>(arr[0]);
	BinaryTreeNode<T>* p = root;
	int i = 1;

	while (i < size)
	{
		if (arr[i] < p->data)
		{
			stack.Push(p);
			p->lLink = new BinaryTreeNode<T>(arr[i]);
			p = p->lLink;
			i++;
		}

		else if (arr[i] > p->data)
		{
			T dataAtHighLevel;

			if (stack.top == nullptr)
			{
				dataAtHighLevel = 9999;
			}

			else
			{
				BinaryTreeNode<T>* topNode = stack.top->data;

				if (topNode != nullptr)
				{
					dataAtHighLevel = topNode->data;
				}

				else
				{
					dataAtHighLevel = 9999;
				}

			}
			if (dataAtHighLevel > arr[i])
			{
				p->rLink = new BinaryTreeNode<T>(arr[i]);
				p = p->rLink;
				i++;
			}

			else if (dataAtHighLevel < arr[i])
			{
				p = stack.Pop();
			}

			else
			{
				i++;
			}

		}

		else
		{
			i++;
		}
	}

}

template<class T>
void BinaryTree<T>::CreateBinarySearchTreeUsingPostorder(T arr[], int size)
{
	int i = size - 1;

	root = new BinaryTreeNode<T>(arr[i]);

	i--;

	BinaryTreeNode<T>* p = root;

	Stack<BinaryTreeNode<T>*> stack;

	stack.Push(root);

	while (i >= 0)
	{
		if (arr[i] > p->data)
		{
			stack.Push(p);
			p->rLink = new BinaryTreeNode<T>(arr[i]);
			p = p->rLink;
			i--;
		}

		else
		{
			if (stack.IsEmpty())
			{
				p->lLink = new BinaryTreeNode<T>(arr[i]);
				p = p->lLink;
				i--;
			}

			else
			{
				BinaryTreeNode <T>* tempNode = stack.top->data;

				if (tempNode->data < arr[i])
				{
					p->lLink = new BinaryTreeNode<T>(arr[i]);
					p = p->lLink;
					i--;
				}

				else
				{
					p = stack.Pop();
				}
			}
		}
	}

}

template<class T>
void BinaryTree<T>::CheckAVLTree()
{
	this->CheckAVLNode(root);
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::CheckAVLNode(BinaryTreeNode<T>* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	node->rLink = CheckAVLNode(node->rLink);

	node->lLink = CheckAVLNode(node->lLink);

	if (node->FindBalanceFactor(node) == 2 && (node->FindBalanceFactor(node->lLink) == 1 ))
	{
		return LLRotation(node);
	}

	else if (node->FindBalanceFactor(node) == 2 && (node->FindBalanceFactor(node->lLink) == -1 || node->FindBalanceFactor(node->lLink) == 0))
	{
		return LRRotation(node);
	}

	else if (node->FindBalanceFactor(node) == -2 && node->FindBalanceFactor(node->rLink) == -1)
	{
		return RRRotation(node);
	}

	else if (node->FindBalanceFactor(node) == -2 && (node->FindBalanceFactor(node->rLink) == 1 || node->FindBalanceFactor(node->rLink) == 0))
	{
		return RLRotation(node);
	}

	return node;
}


