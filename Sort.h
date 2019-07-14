#pragma once
#include <cstdio>
#include <math.h>
#include "Queue.h"

namespace Sort
{
	int FindMin(int* arr, int size)
	{
		int minVal = INT32_MAX;

		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] < minVal)
			{
				minVal = arr[i];
			}
		}

		return minVal;
	}

	int FindMax(int* arr, int size)
	{
		int maxVal = INT32_MIN;

		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] > maxVal)
			{
				maxVal = arr[i];
			}
		}

		return maxVal;
	}

	/// startPoint is inclusive
	void ShiftElementsToLeft(int arr[], int startPoint)
	{
		int i = 0;

		while (i < startPoint)
		{
			arr[i] = arr[i + 1];
			i++;
		}
	}

	void InsertionSort(int arr[], int size)
	{
		if (size <= 1)
			return;

		for (int i = 0; i < size; i++)
		{
			int elementToSort = arr[i];

			int sortingIndex = i - 1;

			while (sortingIndex >= 0 && arr[sortingIndex] > elementToSort)
			{
				arr[sortingIndex + 1] = arr[sortingIndex];
				sortingIndex--;
			}

			arr[sortingIndex + 1] = elementToSort;
		}
	}

	template<class T>
	void BubbleSort(T arr[], int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			bool anySwapIsDone = false;

			for (size_t j = 0; j < size - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					T temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					anySwapIsDone = true;
				}
			}

			if (!anySwapIsDone)
				break;
		}
	}

	void SelectionSort(int arr[], int size)
	{
		for (size_t sortingElementIndex = 0; sortingElementIndex < size; sortingElementIndex++)
		{
			int i, k;
			i = k = sortingElementIndex;

			while (k < size)
			{
				if (arr[k] < arr[i])
				{
					i = k;
				}

				k++;
			}

			int temp = arr[sortingElementIndex];
			arr[sortingElementIndex] = arr[i];
			arr[i] = temp;
		}
	}

	void QuickSort(int arr[], int size)
	{
		if (size == 1) return;

		int startIndex = 1;
		int endIndex = size - 1;
		int elementToSort = arr[0];

		while (startIndex != endIndex)
		{
			if (arr[startIndex] < elementToSort)
			{
				startIndex++;
			}

			if (startIndex == endIndex)
				break;

			if (arr[endIndex] > elementToSort)
			{
				endIndex--;
			}

			if (startIndex == endIndex)
				break;

			if (arr[startIndex] >= elementToSort && arr[endIndex] <= elementToSort)
			{
				int temp = arr[startIndex];
				arr[startIndex] = arr[endIndex];
				arr[endIndex] = temp;
			}
		}

		if (startIndex == endIndex)
		{
			if (arr[startIndex] > elementToSort)
			{
				ShiftElementsToLeft(arr, startIndex - 1);
				arr[startIndex - 1] = elementToSort;
				QuickSort(&arr[startIndex], size - startIndex);
				QuickSort(&arr[0], startIndex);
			}

			else
			{
				ShiftElementsToLeft(arr, startIndex);
				arr[startIndex] = elementToSort;
				QuickSort(&arr[startIndex + 1], size - startIndex - 1);
				QuickSort(&arr[0], startIndex);
			}
		}
	}

	void Swap(int* p, int* q)
	{
		int temp = *p;
		*p = *q;
		*q = temp;
	}

	int Partition(int arr[], int p, int q)
	{
		int i = p;
		int j = p + 1;
		while (j < q)
		{
			if (arr[j] <= arr[p])
			{
				i++;
				Swap(&arr[i], &arr[j]);
			}
			j++;
		}

		Swap(&arr[i], &arr[p]);
		return i;
	}

	void QuickSortDifferentImplementation(int arr[], int p, int q)
	{
		if (q > p)
		{
			int r = Partition(arr, p, q);
			QuickSortDifferentImplementation(arr, p, r - 1);
			QuickSortDifferentImplementation(arr, r + 1, q);
		}
	}

	int* MergeTwoSortedArrays(int arr1[], int arr2[], int size1, int size2)
	{
		int* newArr = new int[(size_t)size1 + (size_t)size2];
		int i = 0;
		int j = 0;
		int k = 0;

		while (i < size1 && j < size2)
		{
			if (arr1[i] <= arr2[j])
			{
				newArr[k] = arr1[i];
				i++;
				k++;
			}

			else
			{
				newArr[k] = arr2[j];
				j++;
				k++;
			}
		}

		if (i < size1)
		{
			while (i < size1)
			{
				newArr[k] = arr1[i];
				k++;
				i++;
			}
		}

		else
		{
			while (j < size2)
			{
				newArr[k] = arr2[j];
				k++;
				j++;
			}
		}

		return newArr;
	}

	int* RecursiveMergeSort(int arr[], int startIndex, int endingIndex)
	{
		static int initialSize = endingIndex - startIndex + 1;

		int midP = (endingIndex - startIndex) / 2 + startIndex;

		if (startIndex == endingIndex)
		{
			int* newArr = new int{ arr[startIndex] };
			return newArr;
		}

		int* arr1 = RecursiveMergeSort(arr, startIndex, midP);
		int* arr2 = RecursiveMergeSort(arr, midP + 1, endingIndex);

		int size1 = midP - startIndex + 1;
		int size2 = endingIndex - (midP + 1) + 1;

		int* newArr = MergeTwoSortedArrays(arr1, arr2, size1, size2);

		delete(arr1);
		delete(arr2);

		if (endingIndex - startIndex + 1 == initialSize)
		{
			delete(arr);
		}

		return newArr;
	}

	void Merge(int* arr, int lowIndex, int midP, int highIndex)
	{
		int l = lowIndex;
		int mid = midP + 1;
		int k = 0;

		int* newArr = new int[highIndex - l + 1];

		while (l <= midP && mid <= highIndex)
		{
			if (arr[l] > arr[mid])
			{
				newArr[k++] = arr[mid++];
			}

			else
			{
				newArr[k++] = arr[l++];
			}
		}

		while (l <= midP)
		{
			newArr[k++] = arr[l++];
		}

		while (mid <= highIndex)
		{
			newArr[k++] = arr[mid++];
		}

		k = 0;

		for (size_t i = lowIndex; i <= highIndex; i++)
		{
			arr[i] = newArr[k++];
		}

		delete[] newArr;
	}

	void IterativeMergeSort(int* arr, int size)
	{
		int p = 2;

		for (; p <= size; p = p * 2)
		{
			for (size_t i = 0; i + p - 1 < size; i = i + p)
			{
				int l = i;
				int h = i + p - 1;
				int mid = l + (h - l) / 2;
				Merge(arr, l, mid, h);
			}
		}

		if (size > p / 2)
		{
			Merge(arr, 0, p / 2 - 1, size - 1);
		}
	}

	void CountSort(int* arr, int size)
	{
		int min = FindMin(arr, size);
		int max = FindMax(arr, size);
		int countArrSize = max - min + 1;
		int* countArr = new int[countArrSize];

		for (size_t i = 0; i < countArrSize; i++)
		{
			countArr[i] = 0;
		}

		for (size_t i = 0; i < size; i++)
		{
			countArr[arr[i] - min]++;
		}

		int countArrIndex = 0;
		int sourceArrIndex = 0;

		while (sourceArrIndex < size)
		{
			if (countArr[countArrIndex] > 0)
			{
				arr[sourceArrIndex] = countArrIndex + min;
				sourceArrIndex++;
				countArr[countArrIndex]--;
			}

			else
			{
				countArrIndex++;
			}
		}

		delete[]countArr;
	}

	void BinSort(int* arr, int size)
	{
		int min = FindMin(arr, size);
		int max = FindMax(arr, size);
		int countQueueSize = max - min + 1;

		Queue<int>** queueArr;

		queueArr = new Queue<int> * [countQueueSize];



		for (size_t i = 0; i < countQueueSize; i++)
		{
			queueArr[i] = nullptr;
		}

		for (size_t i = 0; i < size; i++)
		{
			if (queueArr[arr[i] - min] == nullptr)
				queueArr[arr[i] - min] = new Queue<int>();
			queueArr[arr[i] - min]->Enqueue(1);
		}

		int countArrIndex = 0;
		int sourceArrIndex = 0;

		while (sourceArrIndex < size)
		{
			if (queueArr[countArrIndex] != nullptr && !queueArr[countArrIndex]->IsEmpty())
			{
				arr[sourceArrIndex] = countArrIndex + min;
				sourceArrIndex++;
				queueArr[countArrIndex]->Dequeue();
			}

			else
			{
				countArrIndex++;
			}
		}

		for (size_t i = 0; i < countQueueSize; i++)
		{
			delete queueArr[i];
		}

	}

	void RadixSort(int* arr, int size)
	{
		int maxElement = FindMax(arr, size);
		int minElement = FindMin(arr, size);

		bool negativeFlag = false;

		if (minElement < 0)
		{
			negativeFlag = true;

			for (size_t i = 0; i < size; i++)
			{
				arr[i] = arr[i] - minElement;
			}
		}

		int numberOfDecimals = 0;
		while (maxElement != 0)
		{
			maxElement = maxElement / 10;
			numberOfDecimals++;
		}

		int queuArrSize = 10;

		Queue<int>** queuArr = new  Queue<int> * [queuArrSize];

		for (size_t i = 0; i < queuArrSize; i++)
		{
			queuArr[i] = new Queue<int>();
		}

		int divisionNumber = 1;

		for (size_t i = 0; i < numberOfDecimals; i++, divisionNumber *= 10)
		{
			for (size_t j = 0; j < size; j++)
			{
				int indexToInsert = (arr[j] / divisionNumber) % 10;

				queuArr[indexToInsert]->Enqueue(arr[j]);
			}

			int queuArrIndex = 0;
			int arrIndex = 0;

			while (arrIndex < size)
			{
				if (!queuArr[queuArrIndex]->IsEmpty())
				{
					arr[arrIndex] = queuArr[queuArrIndex]->Dequeue();
					arrIndex++;
				}

				else
				{
					queuArrIndex++;
				}
			}

		}

		if (negativeFlag)
		{
			for (size_t i = 0; i < size; i++)
			{
				arr[i] = arr[i] + minElement;
			}
		}

	}

	void ShellSort(int* arr, int size)
	{
		for (size_t gap = size / 2; gap >= 1; gap /= 2)
		{
			for (size_t arrStartIndex = 0; arrStartIndex + gap < size; arrStartIndex += gap)
			{
				size_t searchIndex = arrStartIndex;

				while (arr[searchIndex] > arr[searchIndex + gap] && searchIndex >= 0)
				{
					Swap(&arr[searchIndex], &arr[searchIndex + gap]);
					searchIndex -= gap;
				}

			}
		}
	}
}

