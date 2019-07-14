#pragma once
#include <cstdio>

struct Node
{
	int data;
	bool isClean;
	bool canWrite;

	Node()
	{
		data = 0;
		isClean= true;
		canWrite = true;
	}
};

class LinearProbingHashTable
{
private:
	int size;
	int capacity;
	Node* hashTable;

public:
	LinearProbingHashTable();
	void AddElement(int element);
	bool DeleteElement(int element);
	void ResizeTable();
	bool FindElement(int element);
	void Display();
};

