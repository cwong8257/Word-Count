# Word-Count
Reads a text file and delivers report showing unique words in alphabetical order and their corresponding frequencies

## Features

### Implements a binary tree for sorting words in alphabetical order
```C++
template <class T>
BinaryTree<T>::BinaryTree() { root = nullptr; }

template <class T>
BinaryTree<T>::~BinaryTree() { destroySubTree(root); }

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
  if (nodePtr == nullptr)
    nodePtr = newNode;
  else if (newNode->value < nodePtr->value)
    insert(nodePtr->left, newNode);
  else if (newNode->value > nodePtr->value)
    insert(nodePtr->right, newNode);
  else
  {
    nodePtr->frequency++;
    delete newNode;
  }
}

template <class T>
void BinaryTree<T>::insertNode(T item)
{
  TreeNode *newNode = nullptr;

  newNode = new TreeNode;
  newNode->value = item;
  newNode->frequency = 1;
  newNode->left = newNode->right = nullptr;

  insert(root, newNode);
}
```

### Traverses binary tree to find corresponding word and update frequency count
```C++
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
```

### Display words and frequency via inorder, preorder, or postorder traversal

```C++
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
```
