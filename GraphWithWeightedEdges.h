#pragma once
class GraphWithWeightedEdges
{
private:
	int size;
	int** linkArr;
	int numberOfEdges;
public:
	GraphWithWeightedEdges(int size);
	void UsePrimSAlgorithm();
	void ShowGraph();
};

