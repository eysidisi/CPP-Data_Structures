#pragma once
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

template<class T>
class BinaryTree
{
	Queue<Node<T>*>* queue;
public:
	BinaryTree();

	~BinaryTree();

	void Add(T* arr, int size);

	void Add(T element);

	void PreorderTraversal(Node<T>* node);

	Node<T>* root;

	void PostorderTraversal(Node<T>* node);

	void InorderTraversal(Node<T>* node);

	void LevelorderTraversal();

	int Count(Node<T>* node);

	int CalcHeight(Node<T>* node);

	int CalcNumOfLeafNodes(Node<T>* node);

	Node<T>* RecursiveBinarySearch(Node<T>* node, T key);

	Node<T>* IterativeBinarySearch(T key);

	bool InsertElementInBinaryTree(T key);

	Node<T>* LLRotation(Node<T>* node);

	Node<T>* LRRotation(Node<T>* node);

	Node<T>* RRRotation(Node<T>* node);

	Node<T>* RLRotation(Node<T>* node);

	Node<T>* RecursiveInsertElementInBinaryTree(Node<T>*& node, T key);

	Node<T>* FindPrecessor(Node<T>* node);

	Node<T>* FindSuccessor(Node<T>* node);

	Node<T>* DeleteElement(T key, Node<T>* node);

	void CreateBinarySearchTreeUsingPreorder(T arr[], int size);

	void CreateBinarySearchTreeUsingPostorder(T arr[], int size);
};

template<class T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
	queue = new Queue<Node<T>*>();
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
	Queue<Node<T>*>* newQueue = new Queue<Node<T>*>();

	if (root != nullptr)
		newQueue->Enqueue(root);

	Node<int>* currentNode;

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
		root = new Node<T>(arr[0]);
		queue->Enqueue(root);
	}


	Node<T>* currentNode;

	for (size_t i = 1; i < size; i++)
	{
		currentNode = queue->Peek();

		if (currentNode->lLink == nullptr)
		{
			currentNode->lLink = new Node<T>(arr[i]);

			queue->Enqueue(currentNode->lLink);
		}

		else if (currentNode->rLink == nullptr)
		{
			currentNode->rLink = new Node<T>(arr[i]);

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
		root = new Node<T>(element);
		queue->Enqueue(root);
	}

	else
	{
		Node<T>* currentNode;

		currentNode = queue->Peek();

		if (currentNode->lLink == nullptr)
		{
			currentNode->lLink = new Node<T>(element);

			queue->Enqueue(currentNode->lLink);
		}

		else if (currentNode->rLink == nullptr)
		{
			currentNode->rLink = new Node<T>(element);

			queue->Enqueue(currentNode->rLink);

			queue->Dequeue();

		}
	}
}

template<class T>
void BinaryTree<T>::PreorderTraversal(Node<T>* node)
{
	if (node != nullptr)
	{
		printf("%d ", node->data);
		PreorderTraversal(node->lLink);
		PreorderTraversal(node->rLink);
	}
}

template<class T>
void BinaryTree<T>::PostorderTraversal(Node<T>* node)
{
	if (node != nullptr)
	{
		PostorderTraversal(node->lLink);
		PostorderTraversal(node->rLink);
		printf("%d ", node->data);
	}

}

template<class T>
void BinaryTree<T>::InorderTraversal(Node<T>* node)
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
	Queue<Node<T>*>* newQueue = new Queue<Node<T>*>();

	newQueue->Enqueue(root);

	Node<int>* currentNode;

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
int BinaryTree<T>::Count(Node<T>* node)
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
int BinaryTree<T>::CalcHeight(Node<T>* node)
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
inline int BinaryTree<T>::CalcNumOfLeafNodes(Node<T>* node)
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
Node<T>* BinaryTree<T>::RecursiveBinarySearch(Node<T>* node, T key)
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
 Node<T>* BinaryTree<T>::IterativeBinarySearch(T key)
{
	Node <T>* currentNode = root;

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
		root = new Node<T>(key);
		return true;
	}

	Node <T>* currentNode = root;
	Node<T>* tailNode = root;

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
		tailNode->rLink = new Node<T>(key);
	}

	else
	{
		tailNode->lLink = new Node<T>(key);
	}

	return true;
}

template<class T>
Node<T>* BinaryTree<T>::LLRotation(Node<T>* node)
{
	Node<T>* A = node;
	Node<T>* B = A->lLink;
	A->lLink = B->rLink;
	
	B->rLink = A;

	if (A == root)
	{
		root = B;
	}


	return B;
}

template<class T>
Node<T>* BinaryTree<T>::LRRotation(Node<T>* node)
{
	Node<T>* A = node;
	Node<T>* B = A->lLink;
	Node<T>* C = B->rLink;

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
Node<T>* BinaryTree<T>::RRRotation(Node<T>* node)
{
	Node<T>* A = node;
	Node<T>* B = node->rLink;
	A->rLink = B->lLink;
	B->lLink = A;

	if (A == root)
	{
		root = B;
	}


	return B;
}

template<class T>
Node<T>* BinaryTree<T>::RLRotation(Node<T>* node)
{
	Node<T>* A = node;
	Node<T>* B = A->rLink;
	Node<T>* C = B->lLink;

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
Node<T>* BinaryTree<T>::RecursiveInsertElementInBinaryTree(Node<T>*& node, T key)
{
	if (node == nullptr)
	{
		node = new Node<T>(key);
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
inline Node<T>* BinaryTree<T>::FindPrecessor(Node<T>* node)
{
	if (node->rLink == nullptr)
		return node;
	else
		return FindPrecessor(node->rLink);
}

template<class T>
inline Node<T>* BinaryTree<T>::FindSuccessor(Node<T>* node)
{
	if (node->lLink == nullptr)
		return node;
	else
		return FindSuccessor(node->lLink);
}

template<class T>
Node<T>* BinaryTree<T>::DeleteElement(T key, Node<T>* node)
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
			Node<T>* p = FindPrecessor(node->lLink);
			node->data = p->data;
			node->lLink = DeleteElement(p->data, p);
		}
		else
		{
			Node<T>* p = FindSuccessor(node->rLink);
			node->data = p->data;
			node->rLink = DeleteElement(p->data, p);
		}

	}

	return node;

}

template<class T>
void BinaryTree<T>::CreateBinarySearchTreeUsingPreorder(T arr[], int size)
{
	Stack<Node<T>*> stack;
	root = new Node<T>(arr[0]);
	Node<T>* p = root;
	int i = 1;

	while (i < size)
	{
		if (arr[i] < p->data)
		{
			stack.Push(p);
			p->lLink = new Node<T>(arr[i]);
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
				Node<T>* topNode = stack.top->data;

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
				p->rLink = new Node<T>(arr[i]);
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

	root = new Node<T>(arr[i]);

	i--;

	Node<T>* p = root;

	Stack<Node<T>*> stack;

	stack.Push(root);

	while (i >= 0)
	{
		if (arr[i] > p->data)
		{
			stack.Push(p);
			p->rLink = new Node<T>(arr[i]);
			p = p->rLink;
			i--;
		}

		else
		{
			if (stack.IsEmpty())
			{
				p->lLink = new Node<T>(arr[i]);
				p = p->lLink;
				i--;
			}

			else
			{
				Node <T>* tempNode = stack.top->data;

				if (tempNode->data < arr[i])
				{
					p->lLink = new Node<T>(arr[i]);
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


