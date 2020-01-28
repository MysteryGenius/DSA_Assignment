#include "pch.h"
#include "BST.h"

#define max(x,y) ((x > y)? x : y)

// constructor
BST::BST()
{
	root = NULL;
}

// search an item in the binary search tree
BinaryNode* BST::search(ItemType target)
{
	return search(root, target);
}

BinaryNode* BST::search(BinaryNode* t, ItemType target)
{
	if (t == NULL)	// item not found
		return NULL;
	else
	{
		if (t->key == target)	// item found
			return t;
		else
			if (target < t->key)	// search in left subtree
				return search(t->left, target);
			else // search in right subtree
				return search(t->right, target);
	}
}

// insert an item to the binary search tree
void BST::insert(ItemType key, string item)
{
	insert(root, key, item);
}

void BST::insert(BinaryNode* &t, ItemType key, string item)
{
	if (t == NULL)
	{
		BinaryNode *newNode = new BinaryNode;
		newNode->key = key;
		newNode->item = item;
		newNode->left = NULL;
		newNode->right = NULL;
		t = newNode;
	}
	else
		if (key < t->key)
			insert(t->left, key, item);  // insert in left subtree
		else
			insert(t->right, key, item); // insert in right subtree
}

// traverse the binary search tree in inorder
void BST::inorder()
{
	if (isEmpty())
		cout << "No item found" << endl;
	else
		inorder(root);
}

void BST::inorder(BinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);
		cout << t->key << endl;
		inorder(t->right);

	}
}
// traverse the binary search tree in preorder
void BST::preorder()
{
	if (isEmpty())
		cout << "No item found" << endl;
	else
		preorder(root);
}

void BST::preorder(BinaryNode* t)
{
	if (t != NULL)
	{
		cout << t->key << endl;
		preorder(t->left);
		preorder(t->right);
	}
}

// traverse the binary search tree in postorder
void BST::postorder()
{
	if (isEmpty())
		cout << "No item found" << endl;
	else
		postorder(root);
}

void BST::postorder(BinaryNode* t)
{
	if (t != NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout << t->key << endl;
	}
}

// check if the binary search tree is empty
bool BST::isEmpty()
{
	return (root == NULL);
}

int BST::countNodes()
{
	return countNodes(root);
}

int BST::countNodes(BinaryNode * t)
{
	int count = 1;
	if (t->left == NULL && t->right == NULL) {
		count = 1;
	}
	else {
		if (t->left != NULL) {
			count += countNodes(t->left);
		}
		if (t->right != NULL) {
			count += countNodes(t->right);
		}
	}
	return count;
}

int BST::getHeight()
{
	return getHeight(root);
}

int BST::getHeight(BinaryNode * t)
{
	if (t == NULL)
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int leftDepth = getHeight(t->left);
		int rightDepth = getHeight(t->right);

		/* use the larger one */
		return max(leftDepth, rightDepth) + 1;
	}
}

bool BST::isBalanced()
{
	return isBalanced(root);
}

bool BST::isBalanced(BinaryNode * t)
{

	/* If tree is empty then return true */
	if (t == NULL)
		return true;

	/* Get the height of left and right sub trees */
	int leftDepth = getHeight(t->left);
	int rightDepth = getHeight(t->right);

	if (abs(leftDepth - rightDepth) <= 1 && isBalanced(t->left) && isBalanced(t->right))
		return true;

	/* If we reach here then
	tree is not height-balanced */
	return false;
}

// delete an item from the binary search tree
void BST::remove(ItemType target)
{
	remove(root, target);
}

// delete an item from the binary search tree
void BST::remove(BinaryNode* &t, ItemType key)
{
	if (t != NULL)
	{
		if (key < t->key)			// search in left subtree
			remove(t->left, key);
		else if (key > t->key)	// search in right subtree
			remove(t->right, key);
		else						// item == t->item (found) - base case
		{
			if (t->left == NULL && t->right == NULL) // case 1 : node has 0 child
			{
				BinaryNode* temp = t;	// to be deleted
				t = NULL;
				delete temp;			// delete the node
			}
			else if (t->left == NULL)	// case 2 : node has 1 child
			{
				BinaryNode* temp = t;	// node to be deleted

				if (t == root)			// current node is root
					root = t->right;
				else
					t = t->right;

				delete temp;			// delete the node
			}
			else if (t->right == NULL)	// case 2 : node has 1 child
			{
				BinaryNode* temp = t;	// node to be deleted

				if (t == root)			// current node is root
					root = t->left;
				else
					t = t->left;

				delete temp;			// delete the node
			}
			else // case 3 : node has 2 children
			{
				BinaryNode* successor = t->left;
				while (successor->right != NULL)	// search for right most node in left sub-tree
					successor = successor->right;

				ItemType key = successor->key;
				remove(t->left, key);				// delete the successor (either case 1 or case 2)
				t->key = key;						// replace the node’s item with that of the successor
			}
		}
	}
}
