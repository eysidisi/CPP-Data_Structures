#pragma once
#include <math.h>
#include <stdio.h>

class Heap
{
private:
	int capacity;
	int* arr;
	int size;


public:
	Heap(int _capacity = 10);
	~Heap();
	void AddElement(int element);
	void DisplayLevelorder();
	int Delete();
	void SortInIncreasingOrder();
	void SortInDecreasingOrder();
	void DisplayArr();
	void Heapify();

};

