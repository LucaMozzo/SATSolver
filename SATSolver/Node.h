class Literal
{
private:
	char letter;
	bool value;
public:
	Literal(char l, bool v) : letter(l), value(v) { }
	char getLetter();
	bool getValue();
};

class NodeIterator;

class Node
{
private:
	Literal* content = nullptr;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
	Node* parent = nullptr;
public:

	Node() { }
	Node(Node* parent_) : parent(parent_) { }

	void setParent(Node* n);
	void setLeftChild(Node* n);
	void setRightChild(Node* n);
	void setContent(Literal* c);

	Node* getParent();
	Node* getLeftChild();
	Node* getRightChild();
	Literal* getContent();

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

	Literal* getContent();
};