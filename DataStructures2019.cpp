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
	const int size1 = 10;
	const int size2 = 3;

	int arr1[size1] = { 2,4,5,7,8,9,12,45,60,111 };
	int* arr2 = new int[3]{ 10,7,2 };


	arr2 = Sort::MergeSort(arr2, 0, 2);

	for (size_t i = 0; i < size2; i++)
	{
		printf("%d ", arr2[i]);
	}

	return 0;
}
