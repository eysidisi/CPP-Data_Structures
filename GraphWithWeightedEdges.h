#pragma once
#include <cstdio>
#include <climits>

class GraphWithWeightedEdges
{
private:
	int size;
	int** linkArr;
	int numberOfEdges;

private:
	//Change Array index to matrix indices
	void ConvertOneDimToTwoDim(int index, int* row, int* col);
	bool IsConnectedConnection(int* arr, int index);

public:
	GraphWithWeightedEdges(int size);
	void UsePrimSAlgorithm();
	void ShowGraph();
	void UseKruskalSAlgorithm();
};

