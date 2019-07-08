// DataStructures2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTreeNode.h"	
#include "Queue.h"
#include "Stack.h"
#include "BinaryTree.h"
#include "Heap.h"
#include "LinkedList.h"
#include "Sort.h"

int main()
{
	const int size = 5;

	int* arr = new int[size] {3, 2, 7, 10,22};

	arr = Sort::MergeSort(arr, 0, size - 1);

	for (size_t i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
