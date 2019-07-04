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
	void Display(); 
	void UseInsertionSort();
};

