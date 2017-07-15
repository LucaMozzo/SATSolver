#include "stdafx.h"

class Node
{
private:
	char content = NULL;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
	Node* parent = nullptr;
public:

	Node() { }
	Node(Node* parent_) : parent(parent_) { }

	void setParent(Node* n);
	void setLeftChild(Node* n);
	void setRightChild(Node* n);
	void setContent(char c);

	Node* getParent();
	Node* getLeftChild();
	Node* getRightChild();
	char getContent();

	bool isRoot();

	NodeIterator iterator();
};

//implementation of preorder traversal
class NodeIterator
{
private:
	Node* pointer = nullptr;
public:
	NodeIterator(Node* startingPos) : pointer(startingPos) { }
	Node* operator++();
	Node* operator--();
	
	char getContent();
};
