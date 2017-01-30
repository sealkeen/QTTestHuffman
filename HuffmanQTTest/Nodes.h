#ifndef NODES_H
#define NODES_H

#include "vector"

enum class NodeType { Internal, Leaf } node_type;

class TreeNode
{
public:
	//const
	int f;
	NodeType nodeType;
	std::vector<bool> path;
	virtual TreeNode* GetChild(bool b) { return nullptr ; }
	virtual const char* GetSymbol() { return nullptr; }

	virtual ~TreeNode() {}
//protected:
	TreeNode(int f, NodeType nT) : f(f), nodeType(nT) {}
};

class InternalNode : public TreeNode
{
public:
	TreeNode * left {nullptr};
	TreeNode * right {nullptr};

	TreeNode* GetChild(bool b)
	{
		if (b == true){
			if(right != nullptr) 
				return right;
		} 
		else if (left != nullptr) 
			return left;
	}

	InternalNode(TreeNode* c0, TreeNode* c1) : TreeNode(c0->f + c1->f, NodeType::Internal), left(c0), right(c1) {}
	~InternalNode()
	{
		delete left;
		delete right;
	}
};

class LeafNode : public TreeNode
{
public:
	char symbol;
	const char* GetSymbol() { return &symbol; }
	LeafNode(int f, char c) : TreeNode(f, NodeType::Leaf), symbol(c) {}
};

struct NodeCmp
{
	bool operator ()(const TreeNode* lhs, const TreeNode* rhs) const { return lhs->f > rhs->f; }
};

struct LeafCmp
{
	bool operator ()(const LeafNode* lhs, const LeafNode* rhs) const { return lhs->symbol > rhs->symbol; }
};

#endif //NODES_H