#pragma once
#include <cstdio>
#include <climits>

class GraphWithWeightedEdges
{
private:
	int size;
	int** linkArr;
	int** connectionArr;
	int numberOfEdges;

private:
	//Change Array index to matrix indices
	void ConvertOneDimToTwoDim(int index, int* row, int* col);
	bool IsConnectedConnection( int index1,int index2);
	void Connect( int** arr, int nodeA, int nodeB);
	bool CheckIfNodesAreAllConnected();

public:
	GraphWithWeightedEdges(int size);
	void UsePrimSAlgorithm();
	void ShowGraph();
	void UseKruskalSAlgorithm();
};
