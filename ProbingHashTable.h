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
///i=0 linearProbing, i=1 quadraticProbing, i=2 doubleHash
class ProbingHashTable
{
private:
	int size;
	int capacity;
	bool isLinearProbingHashTable;
	bool isQuadraticProbingHashTable;
	bool isDoubleHash;
	Node* hashTable;

private:
	int CalcHashKey(int element, int i);
	int CalcFOfI(int i,int element);

public:
	ProbingHashTable();
	ProbingHashTable(int i);
	void AddElement(int element);
	bool DeleteElement(int element);
	void ResizeTable();
	bool FindElement(int element);
	void Display();
};

