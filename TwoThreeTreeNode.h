#pragma once
class TwoThreeTreeNode
{
private:
	bool isHighKeyTaken;
	bool isLowKeyTaken;

public:
	int highKey;
	int lowKey;


	TwoThreeTreeNode* leftChild;
	TwoThreeTreeNode* middleChild;
	TwoThreeTreeNode* rightChild;
	TwoThreeTreeNode* parentNode;


	
	

public:
	TwoThreeTreeNode();
	~TwoThreeTreeNode();

	bool IsLeafNode();
	
	void SetIsHighKeyOccupied(bool isOccupied);
	bool GetIsHighKeyOccupied();
	void SetIsLowKeyOccupied(bool isOccupied);
	bool GetIsLowKeyOccupied();
};

