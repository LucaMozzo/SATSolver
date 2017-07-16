#include "stdafx.h"
#include "CppUnitTest.h"
#include "Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSAT
{		
	TEST_CLASS(TestNodes)
	{
	public:
		
		TEST_METHOD(IterationTest1)
		{
			/*         O
					  /  \
					 a    e
					/ \   /
				   b   c f
				  /
				 d
			*/
			Node* root = new Node();
			Node* a = new Node(root);
			root->setContent(new Literal('A', true));
			/*root->setLeftChild(a);
			Node* b = new Node(a);
			a->setLeftChild(b);
			Node* c = new Node(a);
			a->setRightChild(b);
			Node* d = new Node(b);
			b->setLeftChild(d);
			Node* e = new Node(root);
			root->setRightChild(e);
			Node* f = new Node(e);
			e->setLeftChild(f);*/

			Assert::AreEqual(1, 1);
		}

	};
}