//--------------------------------------------------------------------
//		Lab 12									logitree.cpp
//Leo Innocenzi 2020130265
//--------------------------------------------------------------------

#include "logitree.h"
#include <iostream>

using namespace std;
//--------------------------------------------------------------------

ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode* leftPtr, ExprTreeNode* rightPtr)
:element(elem), left(leftPtr), right(rightPtr)
{

}

//--------------------------------------------------------------------

ExprTree::ExprTree()
:root(0)
{}

ExprTree::~ExprTree()
{
    clear();
}

//--------------------------------------------------------------------

void ExprTree::build()
{
    buildSub(root);
}

void ExprTree::buildSub(ExprTreeNode*& p)
{
    char character;
    
    std::cin >> character;
    p = new ExprTreeNode(character, 0 ,0);
    assert(p != 0);
    if (character == '-'){
        buildSub(p->right);
    }
        
    
    else if (!isdigit(character)){
        buildSub(p->left);
        buildSub(p->right);
    }
}

//--------------------------------------------------------------------

void ExprTree::expression() const
{
    exprSub(root);
}

void ExprTree::exprSub(ExprTreeNode* p) const
{
    if (p != 0){
        if (!isdigit(p->element) && (p->element != '-'))
            std::cout << '(';
        exprSub(p->left);
        std::cout << p->element;
        exprSub(p->right);
        if (!isdigit(p->element) && (p->element != '-'))
            std::cout << ')';
    }
}

//--------------------------------------------------------------------

int ExprTree::evaluate() const
{
    return(evaluateSub(root));
}

int ExprTree::evaluateSub(ExprTreeNode* p) const
{
    int left, right, result;
    
    if (isdigit(p->element))
        result = std::atoi(&p->element);
    else{
        switch (p->element){
            case '+':
                left = evaluateSub(p->left);
                right = evaluateSub(p->right);
                result = left or right;
                break;
            case '-':
                right = evaluateSub(p->right);
                result = not(right);
                break;
            case '*':
                left = evaluateSub(p->left);
                right = evaluateSub(p->right);
                result = left and right;
                break;
        }
    }
    return result;
}

//--------------------------------------------------------------------

void ExprTree::clear()
{
    clearSub(root);
    root = 0;
}

void ExprTree::clearSub(ExprTreeNode* p)
{
    if (p != 0){
        clearSub(p->left);
        clearSub(p->right);
        delete p;
    }
}

//--------------------------------------------------------------------

void ExprTree::showStructure() const

// Outputs an expression tree. The tree is output rotated counter-
// clockwise 90 degrees from its conventional orientation using a
// "reverse" inorder traversal. This operation is intended for testing
// and debugging purposes only.

{
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showSub(root, 1);
		cout << endl;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void ExprTree::showSub(ExprTreeNode* p, int level) const

// Recursive partner of the showStructure() function. Outputs the
// subtree whose root node is pointed to by p. Parameter level is the
// level of this node within the expression tree.

{
	int j;   // Loop counter

	if (p != 0)
	{
		showSub(p->right, level + 1);        // Output right subtree
		for (j = 0; j < level; j++)   // Tab over to level
			cout << "\t";
		cout << " " << p->element;       // Output data item
		if ((p->left != 0) &&          // Output "connector"
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);         // Output left subtree
	}
}
