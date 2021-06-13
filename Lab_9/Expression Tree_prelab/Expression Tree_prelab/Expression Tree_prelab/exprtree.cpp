//--------------------------------------------------------------------
//		Lab 12									exprtree.cpp
//Leo Innocenzi 2020130265
//--------------------------------------------------------------------

#include "exprtree.h"
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
    p = new ExprTreeNode(character, 0, 0);
    assert(p != c0);
    
    if (!isdigit(character)){
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
        if(!isdigit(p->element))
            std::cout << '(';
        exprSub(p->left);
        std::cout << p->element;
        exprSub(p->right);
        if(!isdigit(p->element))
            std::cout << ')';
    }
}

//--------------------------------------------------------------------

float ExprTree::evaluate() const
{
    return (evaluateSub(root));
}

float ExprTree::evaluateSub(ExprTreeNode* p) const
{
    float left, right, result;
    
    if(isdigit(p->element))
        result = std::atof(&p->element);
    else{
        left = evaluateSub(p->left);
        right = evaluateSub(p->right);
        switch (p->element){
            case '+':
                result = left + right;
                break;
            case '-':
                result = left - right;
                break;
            case '*':
                result = left*right;
                break;
            case '/':
                result = left/right;
                break;
        }
    }
    return(result);
}

//--------------------------------------------------------------------

void ExprTree::clear()
{
    clearSub(root);
    root = 0;
}

void ExprTree::clearSub(ExprTreeNode* p)
{
    if(p != 0){
        clearSub(p->left);
        clearSub(p->right);
        delete p;
    }
}

//--------------------------------------------------------------------

void ExprTree::showStructure() const
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

void ExprTree::showSub(ExprTreeNode* p, int level) const
{
	int j;

	if (p != 0)
	{
		showSub(p->right, level + 1);
		for (j = 0; j < level; j++)
			cout << "\t";
		cout << " " << p->element;
		if ((p->left != 0) &&
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);
	}
}
