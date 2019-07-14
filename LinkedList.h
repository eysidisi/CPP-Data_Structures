#pragma once
#include "ListNode.h"
class LinkedList
{
private:
	ListNode* root;
	ListNode* lastNode;
	int size;

public:
	LinkedList();
	~LinkedList();

public:
	void AddElement(int element);
	bool DeleteElement(int element);
	bool FindElement(int element);
	void Display(); 
 	void UseInsertionSort();
};

