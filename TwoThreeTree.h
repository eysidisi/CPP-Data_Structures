#pragma once
#include"TwoThreeTreeNode.h"

class TwoThreeTree
{
private:
	TwoThreeTreeNode* root;

private:
	TwoThreeTreeNode* InsertWithRecursion(TwoThreeTreeNode* node,  int key);
	TwoThreeTreeNode* InsertParentNode(TwoThreeTreeNode* node,int key);
public:
	TwoThreeTree();
	~TwoThreeTree();
	void AddElement(int key);

};

