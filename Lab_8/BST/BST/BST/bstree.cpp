#include <iostream>
#include <queue>
#include "bstree.h"

template < class TE, class KF >
BSTreeNode<TE, KF>::BSTreeNode(const TE& elem, BSTreeNode* leftPtr, BSTreeNode* rightPtr)
:element(elem), left(leftPtr), right(rightPtr)
{

}

template < class TE, class KF >
BSTree<TE, KF>::BSTree()
:root(0)
{
	
}

template < class TE, class KF >
BSTree<TE, KF>::~BSTree()
{
    clear();
}

// Insert

template < class TE, class KF >
void BSTree<TE, KF>::insert(const TE& newElement)
{
    insertSub(root, newElement);
}

template < class TE, class KF >
void BSTree<TE, KF>::insertSub(BSTreeNode<TE, KF>*& p, const TE& newElement)
{
    if(p == 0){
        p = new BSTreeNode<TE, KF>(newElement, 0, 0);
    }
    else if (newElement.key() < p->element.key()){
        insertSub(p->left, newElement);
    }
    else if (newElement.key() > p->element.key()){
        insertSub(p->right, newElement);
    }
    else{
        p->element = newElement;
    }
}

//--------------------------------------------------------------------

// Retrieve 

template < class TE, class KF >
bool BSTree<TE, KF>::retrieve(KF searchKey, TE& searchElement) const
{
    return retrieveSub(root, searchKey, searchElement);
}

template < class TE, class KF >
bool BSTree<TE, KF>::retrieveSub(BSTreeNode<TE, KF>* p, KF searchKey, TE& searchElement) const
{
    bool result;
    if (p == 0){
        result = 0;
    }
    else if (searchKey < p->element.key()){
        result = retrieveSub(p->left, searchKey, searchElement);
    }
    else if (searchKey > p->element.key()){
        result = retrieveSub(p->right, searchKey, searchElement);
    }
    else{
        searchElement = p->element;
        result = 1;
    }
    return result;
}

//--------------------------------------------------------------------

// Remove

template < class TE, class KF >
bool BSTree<TE, KF>::remove(KF deleteKey)
{
    return removeSub(root, deleteKey);
}

template < class TE, class KF >
bool BSTree<TE, KF>::removeSub(BSTreeNode<TE, KF>*& p, KF deleteKey)
{
    BSTreeNode<TE, KF> *delPtr;
    bool result;
    if (p == 0) {
        result = 0;
    }
    else if (deleteKey < p->element.key()) {
        result = removeSub(p->left, deleteKey);
    }
    else if (deleteKey > p->element.key()) {
        result = removeSub(p->right, deleteKey);
    }
    else {
        delPtr = p;
        if (p->left == 0) {
            p = p->right;
        }
        else if (p->right == 0) {
            p = p->left;
        }
        else {
            cutRightmost(p->left, delPtr);
        }
        delete delPtr;
        result = 1;
    }
    return result;
    
}

template < class TE, class KF >
void BSTree<TE, KF>::cutRightmost(BSTreeNode<TE, KF>*& r, BSTreeNode<TE, KF>*& delPtr)
// Recursive partner of the removeSub() function. Traces down a
// sequence of right children. Copies the data from the last node in
// the sequence into the node pointed to delPtr, sets delPtr to point
// to the last node in the sequence, and links around this node.

{
    if (r->right != 0) {
        cutRightmost(r->right, delPtr);
    }
    else {
        delPtr->element = r->element;
        delPtr = r;
        r = r->left;
    }
}

//--------------------------------------------------------------------

// Write Keys

template < class TE, class KF >
void BSTree<TE, KF>::writeKeys() const
{
    writeKeysSub(root);
}

template < class TE, class KF >
void BSTree<TE, KF>::writeKeysSub(BSTreeNode<TE, KF>* p) const
{
    if (p != 0) {
        writeKeysSub(p->left);
        std::cout << p->element.key() << std::endl;
        writeKeysSub(p->right);
    }
}

//--------------------------------------------------------------------

// Clear

template < class TE, class KF >
void BSTree<TE, KF>::clear()
{
    clearSub(root);
    root = 0;
}

template < class TE, class KF >
void BSTree<TE, KF>::clearSub(BSTreeNode<TE, KF>* p)
{
    if (p != 0) {
        clearSub(p->left);
        clearSub(p->right);
        delete p;
    }
}

//--------------------------------------------------------------------

// Empty / Full

template < class TE, class KF >
bool BSTree<TE, KF>::isEmpty() const
{
    return (root == 0);
}

template < class TE, class KF >
bool BSTree<TE, KF>::isFull() const
{
    return(0);
}

//--------------------------------------------------------------------

// Show Structure

template < class TE, class KF >
void BSTree<TE, KF>::showStructure() const

{
	if (root == 0)
		std::cout << "Empty tree" << std::endl;
	else
	{
		std::cout << std::endl;
		showSub(root, 1);
		std::cout << std::endl;
	}
}

template < class TE, class KF >
void BSTree<TE, KF>::showSub(BSTreeNode<TE, KF>* p,
	int level) const

{
	int j;   // Loop counter

	if (p != 0)
	{
		showSub(p->right, level + 1);         // Output right subtree
		for (j = 0; j < level; j++)    // Tab over to level
			std::cout << "\t";
		std::cout << " " << p->element.key();   // Output key
		if ((p->left != 0) &&           // Output "connector"
			(p->right != 0))
			std::cout << "<";
		else if (p->right != 0)
			std::cout << "/";
		else if (p->left != 0)
			std::cout << "\\";
		std::cout << std::endl;
		showSub(p->left, level + 1);          // Output left subtree
	}
}

// In-lab operations
template <class TE, class KF>
int BSTree<TE, KF>::height() const
{
    int height = heightSub(root);
    return height;
}

template <class TE, class KF>
int BSTree<TE, KF>::heightSub(BSTreeNode<TE, KF>* p) const
{
    
    if (root == 0)
        return 0;
    
    int height = 0;
    queue<BSTreeNode<TE, KF>*> q;
    q.push(root);
    while(!q.empty()){
        ++height;
        for(int i = 0, n = q.size(); i < n; ++i)
        {
            BSTreeNode<TE, KF> *p = q.front();
            q.pop();
            
            if(p -> left != NULL)
                q.push(p -> left);
            if(p -> right != NULL)
                q.push(p -> right);
        }
    }
    return(height);
}
