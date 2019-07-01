#include "TwoThreeTree.h"


TwoThreeTree::TwoThreeTree()
	: root(nullptr)
{
}

TwoThreeTree::~TwoThreeTree()
{
}

void TwoThreeTree::AddElement(int key)
{
	InsertWithRecursion(root,  key);
}

TwoThreeTreeNode* TwoThreeTree::InsertWithRecursion(TwoThreeTreeNode* node, int key)
{
	// Case 0
	if (node == nullptr)
	{
		node = new TwoThreeTreeNode();
		node->lowKey = key;
		node->SetIsLowKeyOccupied(true);
		root = node;
		return node;
	}

	else
	{
		// Case 1
		if (key < node->lowKey)
		{
			//Case 1.1
			if (node->IsLeafNode())
			{
				// Case 1.1.1
				if (node->GetIsHighKeyOccupied() == false)
				{
					node->highKey = node->lowKey;
					node->lowKey = key;
					node->SetIsHighKeyOccupied(true);
					return node;
				}

				// Case 1.1.2
				else if (node->GetIsHighKeyOccupied() == true)
				{
					int nodeLowKey = node->lowKey;
					int nodeHighKey = node->highKey;
					node->lowKey = key;
					node->SetIsHighKeyOccupied(false);
					
					TwoThreeTreeNode* newNode = new TwoThreeTreeNode();

					newNode->lowKey = nodeHighKey;
					newNode->SetIsLowKeyOccupied(true);
					
					TwoThreeTreeNode* newParentNode = InsertParentNode(node,nodeLowKey);

					newParentNode->leftChild = node;
					newParentNode->middleChild = newNode;
					node->parentNode = newParentNode;
					newNode->parentNode = newParentNode;

					return node;
				}
			}

			// Case 1.1.3
			else
			{
				node->leftChild = InsertWithRecursion(node->leftChild, key);
			}

		}

		// Case 2
		else if (key > node->lowKey && ((!node->GetIsHighKeyOccupied())|| key<node->highKey))
		{
			//Case 2.1
			if (node->IsLeafNode())
			{
				// Case 2.1.1
				if (node->GetIsHighKeyOccupied() == false)
				{
					node->highKey = key;
					node->SetIsHighKeyOccupied(true);
					return node;
				}

				// Case 2.1.2
				else if (node->GetIsHighKeyOccupied() == true)
				{
					int nodeLowKey = node->lowKey;
					int nodeHighKey = node->highKey;
					
					node->SetIsHighKeyOccupied(false);

					TwoThreeTreeNode* newNode = new TwoThreeTreeNode();

					newNode->lowKey = nodeHighKey;
					newNode->SetIsLowKeyOccupied(true);

					TwoThreeTreeNode* newParentNode = InsertParentNode(node, key);

					newParentNode->leftChild = node;
					newParentNode->middleChild = newNode;
					node->parentNode = newParentNode;
					newNode->parentNode = newParentNode;

					return node;
				}
			}
			
			// Case 2.2
			else
			{
				node->middleChild = InsertWithRecursion(node->middleChild, key);
			}
		}

		// Case 3
		else if (node->GetIsHighKeyOccupied() && key > node->highKey)
		{
			//Case 3.1
			if (node->IsLeafNode())
			{
					int nodeLowKey = node->lowKey;
					int nodeHighKey = node->highKey;

					node->SetIsHighKeyOccupied(false);

					TwoThreeTreeNode* newNode = new TwoThreeTreeNode();

					newNode->lowKey = key;
					newNode->SetIsLowKeyOccupied(true);

					TwoThreeTreeNode* newParentNode = InsertParentNode(node, nodeHighKey);

					newParentNode->leftChild = node;
					newParentNode->middleChild = newNode;
					node->parentNode = newParentNode;
					newNode->parentNode = newParentNode;

					return node;
			}

			// Case 3.2
			else
			{
				node->rightChild = InsertWithRecursion(node->rightChild, key);
			}
		}
	}
}

TwoThreeTreeNode* TwoThreeTree::InsertParentNode(TwoThreeTreeNode* node,int key)
{
	if (node->parentNode == nullptr)
	{
		node->parentNode = new TwoThreeTreeNode();
		node->parentNode->lowKey = key;
		node->parentNode->SetIsLowKeyOccupied(true);
		root = node->parentNode;
		return node->parentNode;
	}

	// Case 1.1.2.1
	if (node->parentNode->leftChild == node)
	{
		// Case 1.1.2.1.1
		if (node->parentNode->GetIsHighKeyOccupied() == false)
		{
			node->parentNode->highKey = node->parentNode->lowKey;
			node->parentNode->lowKey = key;
			node->parentNode->SetIsHighKeyOccupied(true);
			node->parentNode->rightChild = node->parentNode->middleChild;
			node->parentNode->middleChild = nullptr;
			return node->parentNode;
		}

		// Case 1.1.2.1.2
		else if (node->parentNode->GetIsHighKeyOccupied() == true)
		{
			node->parentNode->parentNode = InsertParentNode(node->parentNode, node->parentNode->lowKey);
			node->parentNode->lowKey = key;

			TwoThreeTreeNode* newNode = new TwoThreeTreeNode();
			newNode->lowKey = node->parentNode->highKey;
			node->parentNode->SetIsHighKeyOccupied(false);

			newNode->parentNode = node->parentNode->parentNode;
			newNode->leftChild = node->parentNode->middleChild;
			newNode->leftChild->parentNode = newNode;
			newNode->middleChild = node->parentNode->rightChild;
			newNode->middleChild->parentNode = newNode;

			node->parentNode->middleChild = nullptr;
			node->parentNode->rightChild = nullptr;

			node->parentNode->parentNode->leftChild = node->parentNode;
			node->parentNode->parentNode->SetIsLowKeyOccupied(true);
			node->parentNode->parentNode->middleChild = newNode;

			return node->parentNode;
		}
	}

	// Case 1.1.2.2
	else if (node->parentNode->middleChild == node)
	{
		// Case 1.1.2.2.1 TODO: Not tried
		if (node->parentNode->GetIsHighKeyOccupied() == false)
		{
			node->parentNode->highKey = key;
			node->parentNode->SetIsHighKeyOccupied(true);
			return node->parentNode;
		}

		// Case 1.1.2.2.2 TODO: Not tried
		else if (node->parentNode->GetIsHighKeyOccupied() == true)
		{
			node->parentNode->parentNode = InsertParentNode(node->parentNode, node->parentNode->lowKey);
			node->parentNode->lowKey = key;

			TwoThreeTreeNode* newNode = new TwoThreeTreeNode();
			newNode->lowKey = node->parentNode->highKey;
			node->parentNode->SetIsHighKeyOccupied(false);

			newNode->parentNode = node->parentNode->parentNode;
			newNode->leftChild = node->parentNode->middleChild;
			newNode->leftChild->parentNode = newNode;
			newNode->middleChild = node->parentNode->rightChild;
			newNode->middleChild->parentNode = newNode;

			node->parentNode->middleChild = nullptr;
			node->parentNode->rightChild = nullptr;

			node->parentNode->parentNode->leftChild = node->parentNode;
			node->parentNode->parentNode->SetIsLowKeyOccupied(true);
			node->parentNode->parentNode->middleChild = newNode;

			return node->parentNode;
		}
	}

	// Case 1.1.2.3
	else if (node->parentNode->rightChild == node)
	{

	}
}
