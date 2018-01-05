#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
using namespace std;

// BinaryTree template
template <class T>
class BinaryTree
{
private:
	struct TreeNode
	{
		T value;						// The value in the node
		int frequency;					// Frequncy of occurence
		TreeNode *left;					// Pointer to the left child node
		TreeNode *right;				// Pointer to the right child node
	};

	TreeNode *root;				// Pointer to the root node

	// Private member functions
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(T, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;

public:
	// Constructor
	BinaryTree();

	// Destructor
	~BinaryTree();

	// Binary tree operations
	void insertNode(T);
	bool searchNode(T);
	void remove(T);

	void displayInOrder() const { displayInOrder(root); }
	void displayPreOrder() const { displayPreOrder(root); }
	void displayPostOrder() const { displayPostOrder(root); }
};
#endif