#include "LinkedList.h"
#include <cstdio>

LinkedList::LinkedList()
	: root(nullptr), size(0), lastNode(nullptr)
{

}

LinkedList::~LinkedList()
{
	while (root != nullptr)
	{
		ListNode* nodeToDelete = root;
		root = root->nextNode;
		delete(nodeToDelete);
	}
}

void LinkedList::AddElement(int element)
{
	if (root == nullptr)
	{
		root = new ListNode(element);
		size++;
		lastNode = root;
	}

	else
	{
		ListNode* lastNode = root;

		while (lastNode->nextNode != nullptr)
		{
			lastNode = lastNode->nextNode;
		}

		ListNode* newNode = new ListNode(element);

		lastNode->nextNode = newNode;
		newNode->prevNode = lastNode;

		this->lastNode = newNode;

		size++;
	}

	UseInsertionSort();
}

bool LinkedList::DeleteElement(int element)
{
	if (root == nullptr)
		return false;

	ListNode* ptr = root;

	while (ptr != nullptr && ptr->data <= element)
	{
		if (ptr->data == element )
		{
			if (ptr->prevNode != nullptr)
			{
				ptr->prevNode->nextNode = ptr->nextNode;
			}

			else
			{
				root = ptr->nextNode;
			}
			
			if (ptr->nextNode != nullptr)
			{
				ptr->nextNode->prevNode = ptr->prevNode;
			}

			delete(ptr);

			return true;
		}

		ptr = ptr->nextNode;
	}

	return false;
}

bool LinkedList::FindElement(int element)
{
	if (root == nullptr)
		return false;

	ListNode* ptr = root;

	while (ptr != nullptr && ptr->data <= element)
	{
		if (ptr->data == element)
		{
			return true;
		}

		ptr = ptr->nextNode;
	}

	return false;
}

void LinkedList::Display()
{
	ListNode* currentNode = root;

	if (currentNode == nullptr)
	{
		printf("List is empty \n");
	}

	while (currentNode != nullptr)
	{
		printf("%d ", currentNode->data);
		currentNode = currentNode->nextNode;
	}
}

void LinkedList::UseInsertionSort()
{
	if (size <= 1)
	{
		return;
	}

	ListNode* nodeToInsert = nullptr;
	ListNode* nextNode = root->nextNode;
	ListNode* tailP = nullptr;
	ListNode* headP = nullptr;

	for (int i = 0; i < size - 1; i++)
	{
		nodeToInsert = nextNode;
		tailP = nodeToInsert;
		headP = nodeToInsert->prevNode;
		nextNode = nextNode->nextNode;

		while (headP != nullptr && headP->data > nodeToInsert->data)
		{
			tailP = headP;
			headP = headP->prevNode;
		}

		if (tailP != nodeToInsert)
		{
			if(nodeToInsert->prevNode!=nullptr)
			nodeToInsert->prevNode->nextNode = nodeToInsert->nextNode;
			
			if(nodeToInsert->nextNode!=nullptr)
			nodeToInsert->nextNode->prevNode = nodeToInsert->prevNode;
			
			nodeToInsert->nextNode = tailP;
			if (nodeToInsert->nextNode != nullptr)
			{
				nodeToInsert->nextNode->prevNode = nodeToInsert;
			}

			nodeToInsert->prevNode = headP;

			if (nodeToInsert->prevNode != nullptr)
			{
				nodeToInsert->prevNode->nextNode = nodeToInsert;
			}

			if (tailP == root)
			{
				root = nodeToInsert;
			}
		}
	}
	return;

}
