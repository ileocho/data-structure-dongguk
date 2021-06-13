//
//  stacklnk.cpp
//  stackarr
//
//  Created by Leo  Innocenzi on 27/03/2021.
//

#include "stacklnk.h"
#include <assert.h>
#include <iostream>

template <class DT>
StackNode<DT>::StackNode(const DT &nodeData, StackNode *nextPtr) : dataItem(nodeData), next(nextPtr) {}

template <class DT>
Stack<DT>::Stack(int ignored, int maxStackSize) : top(0), maxSize(maxStackSize) {}

template <class DT>
Stack<DT>::~Stack(){
    clear();
}

template <class DT>
void Stack<DT>::push(const DT &newDataItem) //add one element at top of a stack
{
    top = new StackNode<DT>(newDataItem, top); //creates a new node at top position
    assert(top != 0);
}

template <class DT>
DT Stack<DT>::pop() //remove top element from a stack
{
    StackNode<DT> *item_node;
    DT temp_item;
    
    assert(top != 0);
    
    temp_item = top->dataItem; //stores the top dataItem into temp location
    item_node = top; //assign top node position to p StackNode ptr
    top = top->next; //top takes value of next element in the linked list
    delete item_node; //delete memory use of the top position node
    
    return(temp_item); //return the deleted dataItem
}


template <class DT>
void Stack<DT>::clear() //remove all elements from a stack
{
    StackNode<DT> *item_node, *next_node; //instanciate nodes to loop through
    item_node = top; //set first node to the top node
    
    while(item_node != 0) //iterate trough nodes
    {
        next_node = item_node->next; //set next ndoe
        delete item_node; //delete current node
        item_node = next_node; //move to next node
    }
    
    top = 0; //set top to 0
}


template <class DT>
bool Stack<DT>::isEmpty() const
{
    if(top == 0)
        return true;
    else
        return false;
}


template <class DT>
bool Stack<DT>::isFull() const
{
    if(top == maxSize)
        return true;
    else
        return false;
}

template <class DT>
void Stack<DT>::showStructure() const
{
    StackNode<DT> *item_node;
    
    if (top == 0)
        std::cout << "Empty stack" << std::endl;
    
    else {
        std::cout << "top";
        
        for (item_node = top; item_node != 0; item_node->next)
            std::cout << item_node->dataItem << "\t";
        
        std::cout << "bottom" << std::endl;
    }
    
    
}

