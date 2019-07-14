#include "LinearProbingHashTable.h"

LinearProbingHashTable::LinearProbingHashTable()
	: size(0), capacity(10), hashTable(new Node[10])
{

}

void LinearProbingHashTable::AddElement(int element)
{
	if (size + 1 > capacity / 2)
	{
		ResizeTable();
	}

	int hashIndex = element % capacity;

	while (hashTable[hashIndex].canWrite == false)
	{
		hashIndex = (hashIndex + 1) % capacity;
	}

	hashTable[hashIndex].data = element;

	hashTable[hashIndex].isClean = false;

	hashTable[hashIndex].canWrite = false;

	size++;
}

bool LinearProbingHashTable::DeleteElement(int element)
{
	int searchIndex = element % capacity;

	while (hashTable[searchIndex].isClean != true)
	{
		if (hashTable[searchIndex].data == element)
		{
			hashTable[searchIndex].canWrite = true;
			size--;
			return(true);
		}

		searchIndex = (searchIndex + 1) % capacity;
	}

	return false;
}

void LinearProbingHashTable::ResizeTable()
{
	capacity = capacity * 2;

	Node* newTable = new Node[capacity];

	for (size_t i = 0; i < size; i++)
	{
		if (hashTable[i].isClean == false)
		{
			int element = hashTable[i].data;

			int hashIndex = element % capacity;

			while (newTable[hashIndex].canWrite == false)
			{
				hashIndex = (hashIndex + 1) % capacity;
			}

			newTable[hashIndex].data = element;

			newTable[hashIndex].isClean = false;

			newTable[hashIndex].canWrite = false;
		}
	}

	delete[] hashTable;

	hashTable = newTable;
}

bool LinearProbingHashTable::FindElement(int element)
{
	int searchIndex = element % capacity;

	while (hashTable[searchIndex].isClean != true)
	{
		if (hashTable[searchIndex].data == element)
		{
			return true;
		}

		searchIndex = (searchIndex + 1) % capacity;
	}

	return false;
}

void LinearProbingHashTable::Display()
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
