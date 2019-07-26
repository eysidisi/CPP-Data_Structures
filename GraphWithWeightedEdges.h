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
	bool AreNodesConnected(int* connectionArr, int index1,int index2);
	void Connect( int* arr, int nodeA, int nodeB);
	bool CheckIfNodesAreAllConnected();
	int FindUnusedMinLink(int** arr,int size);

public:
	GraphWithWeightedEdges(int size);
	void UsePrimSAlgorithm();
	void ShowGraph();
	void UseKruskalSAlgorithm();
};

