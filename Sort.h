#pragma once
#include <cstdio>
#include <math.h>
namespace Sort
{
	/// Startpoint is inclusive
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

	int* MergeSort(int arr[], int startIndex, int endingIndex)
	{
		static int initialSize = endingIndex - startIndex + 1;

		int midP = (endingIndex - startIndex) / 2 + startIndex;

		if (startIndex == endingIndex)
		{
			int* newArr = new int{ arr[startIndex] };
			return newArr;
		}

		int* arr1 = MergeSort(arr, startIndex, midP);
		int* arr2 = MergeSort(arr, midP+1, endingIndex);

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
}

