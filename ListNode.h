#pragma once
struct ListNode
{
	int data;
	ListNode* nextNode;
	ListNode* prevNode;
	
	ListNode(int _data)
	{
		data = _data;
		nextNode = nullptr;
		prevNode = nullptr;
	};
};

