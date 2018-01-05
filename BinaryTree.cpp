#include "BinaryTree.h"

template <class T>
BinaryTree<T>::BinaryTree() { root = nullptr; }

template <class T>
BinaryTree<T>::~BinaryTree() { destroySubTree(root); }

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode;								// Insert the node
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);					// Search the left branch
	else if (newNode->value > nodePtr->value)
		insert(nodePtr->right, newNode);				// Search the right branch
	else
	{
		nodePtr->frequency++;
		delete newNode;
	}
}

template <class T>
void BinaryTree<T>::insertNode(T item)
{
	TreeNode *newNode = nullptr;				// Pointer to a new node

	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = item;
	newNode->frequency = 1;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

template <class T>
bool BinaryTree<T>::searchNode(T item)
{
	TreeNode *nodePtr = root;
	while (nodePtr)
	{
		if (nodePtr->value == item)
			nodePtr = nodePtr->left;
		else if (item < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

// Calls deleteNode to delete the node whose value member is the same as num
template <class T>
void BinaryTree<T>::remove(T item)
{
	deleteNode(item, root);
}

// Deletes the node whose value member is the same as num
template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
	if (item < nodePtr->value)
		deleteNode(item, nodePtr->left);
	else if (item > nodePtr->value)
		deleteNode(item, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

/**
* Takes a reference to a pointer to the node that is to be deleted. The node
* is removed and the branches of the tree below the node are reattached.
*/
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
	// Define a temporary pointer to use in reattaching the left subtree.
	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;		// Reattach the left child
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;		// Reattach the left child
		delete tempNodePtr;
	}
	// If the node has two children.
	else
	{
		// Move on node to the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

/**
* Displays the values in the subtree pointed to by nodePtr,
* via inorder traversal.
*/
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << " -> " << nodePtr->frequency << endl;
		displayInOrder(nodePtr->right);
	}
}

/**
* Displays the values in the subtree pointed to by nodePtr,
* via preorder traversal.
*/
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << " -> " << nodePtr->frequency << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

/**
* Displays the values in the subtree pointed to by nodePtr,
* via postorder traversal.
*/
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << " -> " << nodePtr->frequency << endl;
	}
}

template class BinaryTree<string>;