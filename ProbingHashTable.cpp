#include "ProbingHashTable.h"

int FindLargestPrime(int i)
{
	if (i == 1 || i == 2 || i == 3)
		return i;

	while (i >= 3)
	{
		bool isPrime = true;

		for (int j = 2; j < i ; j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime == true)
		{
			return i;
		}

		i--;
	}

	return i;
}

ProbingHashTable::ProbingHashTable()
	: ProbingHashTable(0)
{

}

ProbingHashTable::ProbingHashTable(int i)
	: size(0), capacity(10), hashTable(new Node[10]),
	isLinearProbingHashTable(false), isQuadraticProbingHashTable(false), isDoubleHash(false)
{
	if (i == 0)
	{
		isLinearProbingHashTable = true;
	}

	else if (i == 1)
	{
		isQuadraticProbingHashTable = true;
	}

	else if (i == 2)
	{
		isDoubleHash = true;
	}
}

int ProbingHashTable::CalcHashKey(int element, int i)
{
	int hX = element % capacity;
	int hPrimeX = (hX + CalcFOfI(i, element)) % capacity;
	return hPrimeX;

}

int ProbingHashTable::CalcFOfI(int i, int element)
{
	if (isLinearProbingHashTable)
	{
		return i;
	}

	else if (isQuadraticProbingHashTable)
	{
		return (i * i);
	}

	else if (isDoubleHash)
	{
		int largestPrime = FindLargestPrime(capacity);
		return(i * (largestPrime - (element % largestPrime)));
	}
}

void ProbingHashTable::AddElement(int element)
{
	if (size + 1 > capacity / 2)
	{
		ResizeTable();
	}

	int i = 0;

	int hashIndex;

	do
	{
		hashIndex = CalcHashKey(element, i);
		i++;
	} while (hashTable[hashIndex].canWrite == false);

	hashTable[hashIndex].data = element;

	hashTable[hashIndex].isClean = false;

	hashTable[hashIndex].canWrite = false;

	size++;
}

bool ProbingHashTable::DeleteElement(int element)
{
	int i = 0;

	int searchIndex = CalcHashKey(element, i);

	while (hashTable[searchIndex].isClean != true)
	{
		if (hashTable[searchIndex].data == element)
		{
			hashTable[searchIndex].canWrite = true;
			size--;
			return(true);
		}
		i++;
		searchIndex = CalcHashKey(element, i);
	}

	return false;
}

void ProbingHashTable::ResizeTable()
{
	capacity = capacity * 2;

	Node* newTable = new Node[capacity];



	for (size_t j = 0; j < size; j++)
	{
		int i = 0;

		if (hashTable[j].canWrite == false)
		{
			int element = hashTable[j].data;

			int hashIndex = CalcHashKey(element, i);

			while (newTable[hashIndex].canWrite == false)
			{
				i++;
				hashIndex = CalcHashKey(element, i);
			}

			newTable[hashIndex].data = element;

			newTable[hashIndex].isClean = false;

			newTable[hashIndex].canWrite = false;
		}
	}

	delete[] hashTable;

	hashTable = newTable;
}

bool ProbingHashTable::FindElement(int element)
{
	int i = 0;

	int searchIndex = CalcHashKey(element, i);

	while (hashTable[searchIndex].isClean != true)
	{
		if (hashTable[searchIndex].data == element)
		{
			return true;
		}
		i++;
		searchIndex = CalcHashKey(element, i);
	}

	return false;
}

void ProbingHashTable::Display()
{
	if (size == 0)
	{
		printf("Table is empty\n");
		return;
	}

	for (int i = 0; i < capacity; i++)
	{
		if (hashTable[i].canWrite == false)
		{
			printf("at key: %d  data: %d, \n", i, hashTable[i].data);
		}
	}

	printf("Size: %d  Capacity: %d \n", size, capacity);
}
