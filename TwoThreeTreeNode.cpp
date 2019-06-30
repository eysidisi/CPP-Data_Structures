#include "TwoThreeTreeNode.h"

TwoThreeTreeNode::TwoThreeTreeNode()
	:isHighKeyTaken(false), isLowKeyTaken(false), leftChild(nullptr),
	rightChild(nullptr), middleChild(nullptr), parentNode(nullptr),
	highKey(-1),lowKey(-1)
{

}

TwoThreeTreeNode::~TwoThreeTreeNode()
{
}

bool TwoThreeTreeNode::IsLeafNode()
{
	return(leftChild == nullptr && middleChild == nullptr && rightChild == nullptr);

}

void TwoThreeTreeNode::SetIsHighKeyOccupied(bool isOccupied)
{
	isHighKeyTaken = isOccupied;
	
	if (!isOccupied)
	{
		highKey = -1;
	}
}

bool TwoThreeTreeNode::GetIsHighKeyOccupied()
{
	return isHighKeyTaken;
}

void TwoThreeTreeNode::SetIsLowKeyOccupied(bool isOccupied)
{
	isLowKeyTaken = isOccupied;

	if (!isOccupied)
	{
		lowKey = -1;
	}
}

bool TwoThreeTreeNode::GetIsLowKeyOccupied()
{
	return isLowKeyTaken;
}

