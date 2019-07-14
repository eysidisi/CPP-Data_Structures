#include "ChainHashTable.h"
#include <cstdio>

ChainHashTable::ChainHashTable()
{
	hashTable = new LinkedList*[hashSize];

	for (size_t i = 0; i < hashSize; i++)
	{
		hashTable[i] = nullptr;
	}
}

ChainHashTable::~ChainHashTable()
{
	for (size_t i = 0; i < hashSize; i++)
	{
		if (hashTable[i] != nullptr)
		{
			hashTable[i]->~LinkedList();
		}
	}
}

void ChainHashTable::AddElement(int element)
{
	int indexToInsert = element % hashSize;

	if (hashTable[indexToInsert] != nullptr)
	{
		hashTable[indexToInsert]->AddElement(element);
	}

	else
	{
		hashTable[indexToInsert] = new LinkedList();
		hashTable[indexToInsert]->AddElement(element);
	}
}

bool ChainHashTable::FindElement(int element)
{
	int indexToSearch = element % hashSize;

	if (hashTable[indexToSearch] == nullptr)
		return false;

	return (hashTable[indexToSearch]->FindElement(element));

}

bool ChainHashTable::DeleteElement(int element)
{

	int indexToSearch = element % hashSize;

	if (hashTable[indexToSearch] == nullptr)
		return false;

	return(hashTable[indexToSearch]->DeleteElement(element));

}

void ChainHashTable::Display()
{
	for (size_t tableIndex = 0; tableIndex < hashSize; tableIndex++)
	{
		if (hashTable[tableIndex] != nullptr)
		{
			hashTable[tableIndex]->Display();
			printf("\n");
		}

	}
}
