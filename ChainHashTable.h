#pragma once
#include "LinkedList.h"

class ChainHashTable
{
private:
	LinkedList** hashTable;
	int hashSize = 10;

public:
	ChainHashTable();
	~ChainHashTable();
	void AddElement(int element);
	bool FindElement(int element);
	bool DeleteElement(int element);
	void Display();

};

