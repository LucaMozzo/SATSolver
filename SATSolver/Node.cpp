#include "stdafx.h"
#include "Node.h"

//#pragma region setters
void Node::setParent(Node* n)
{
	parent = n;
}

void Node::setLeftChild(Node* n)
{
	leftChild = n;
}

void Node::setRightChild(Node* n)
{
	rightChild = n;
}

void Node::setContent(Literal* c)
{
	content = c;
}
//#pragma endregion

#pragma region getters

Node* Node::getParent()
{
	return parent;
}

Node* Node::getLeftChild()
{
	return leftChild;
}

Node* Node::getRightChild()
{
	return rightChild;
}

Literal* Node::getContent()
{
	return content;
}
#pragma endregion

bool Node::isRoot() 
{
	return parent == nullptr;
}

NodeIterator Node::iterator()
{
	return NodeIterator(this);
}

Node* NodeIterator::operator++()
{
	if (pointer->getLeftChild() != nullptr)
		pointer = pointer->getLeftChild();
	else if (pointer->getRightChild() != nullptr)
		pointer = pointer->getRightChild();
	else if (pointer->getParent()->getRightChild() != nullptr && pointer->getParent()->getRightChild() != pointer)
		pointer = pointer->getParent()->getRightChild();
	else
	{
		//if the right child of the parent of the parent of the current node is the parent itself, the tree has been completely visited
		Node* index = pointer->getParent();
		while (index->getParent()->getRightChild() == nullptr) 
		{
			//iteration finished, last node visited
			if (index->isRoot())
				return nullptr;
			index = index->getParent()->getRightChild();
		}

		//last node on the right-hand side of the tree
		if (index == pointer->getParent())
			return nullptr;

		pointer = index;
	}

	return pointer;
}

Literal* NodeIterator::getContent()
{
	return pointer->getContent();
}

char Literal::getLetter()
{
	return letter;
}

bool Literal::getValue()
{
	return value;
}