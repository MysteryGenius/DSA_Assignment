#pragma once
typedef int ItemType;
#include<string>

struct BinaryNode
{
	ItemType key;		// data key
	string item;		// data item
	BinaryNode *left;	// pointer pointing to left subtree
	BinaryNode *right;  // pointer pointing to right subtree
};
