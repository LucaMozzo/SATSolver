#include "stdafx.h"
#include "Node.h"

int main()
{
	Node* n = new Node();
	n->setContent(new Literal('A', true));
    return 0;
}

