#pragma once
#include <math.h>
#include <stdio.h>

class Heap
{
private:
	int size;
	int capacity;
	int *arr;

public:
	Heap(int _capacity=10);
	~Heap();
	void AddElement(int element);
	void DisplayLevelorder();
};

