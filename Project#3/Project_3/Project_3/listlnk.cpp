// Léo Innocenzi - 2020130265
//For Data Structure Class, lab04, 2021

#include "listlnk.h"

#include <iostream>


template<class DT>
ListNode<DT>::ListNode(const DT& nodeData, ListNode* nextPtr)
:dataItem(nodeData), next(nextPtr)
{
}


template<class DT>
List<DT>::List(int ignored)
:head(0), cursor(0)

{
}

//------------------------------------------------

template<class DT>
List<DT>::~List()
{
    //clear();
}

//------------------------------------------------


template<class DT>
void List<DT>::insert(const DT& newData)
{
    if (head == 0){
        head = new ListNode<DT>(newData, 0);
        cursor = head;
    }
    
    else {
        cursor->next = new ListNode<DT>(newData, cursor->next);
        assert(cursor->next != 0);
        cursor = cursor->next;
    }
    
}

//------------------------------------------------


template<class DT>
void List<DT>::remove()
{
    ListNode<DT> *remove_node, *previous_node;
    
    assert(head != 0);
    
    if (cursor == head) { //first node to remove
        remove_node = head;
        head = head->next;
        cursor = head;
    }
    
    else if (cursor->next != 0) { //node to remove in the middle
        remove_node = cursor->next;
        cursor->dataItem = remove_node->dataItem;
        cursor->next = remove_node->next;
    }
    
    else { //last node to remove
        remove_node = cursor;
        for (previous_node = head; previous_node->next != cursor; previous_node = previous_node->next);
        previous_node->next = 0;
        cursor = head;
    }
    
}


//------------------------------------------------


template<class DT>
void List<DT>::replace(const DT& newData)
{
    assert(head != 0);
    cursor->dataItem = newData;
}

//------------------------------------------------


template<class DT>
void List<DT>::clear()
{
    ListNode<DT> *node, *nextNode;
    
    node = head;
    while (node != 0) {
        nextNode = node->next;
        delete(node);
        node = nextNode;
    }
    
    head = 0;
    cursor = 0;
}

//------------------------------------------------


template<class DT>
bool List<DT>::isEmpty() const
{
    return(head == 0);
}

//------------------------------------------------


template<class DT>
bool List<DT>::isFull() const
{
    return(1);
}

//------------------------------------------------


template<class DT>
void List<DT>::gotoBeginning()
{
    assert (head != 0);
    cursor = head;
}

//------------------------------------------------


template<class DT>
void List<DT>::gotoEnd()
{
    assert (head != 0);
    for(; cursor->next !=0; cursor = cursor->next);
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoNext()
{
    if(cursor->next != 0)
    {
        cursor = cursor->next;
        return(1);
    }
    else {
        return(0);
    }
        
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoPrior()
{
    ListNode<DT> *previous;
    
    if (cursor != head) {
        for(previous = head; previous->next != cursor; previous = previous->next);
        cursor = previous;
        return(1);
    }
    else {
        return(0);
    }
}


//------------------------------------------------


template<class DT>
DT List<DT>::getCursor() const
{
    assert (head != 0);
    return(cursor->dataItem);
}

template<class DT>
void List<DT>::showStructure() const
{
    ListNode<DT> *node;

    if (head == 0)
       std::cout << "Empty list" << std::endl;
    else
    {
       for (node = head ; node != 0 ; node = node->next)
           if (node == cursor)
              std::cout << "[" << node->dataItem << "] ";
           else
              std::cout << node->dataItem << " ";
       std::cout << std::endl;
    }
}

//------------------------------------------------

//in-lab
template<class DT>
void List<DT>::moveToBeginning()
{
    assert(head != 0);
    
    ListNode<DT> *previous_node, *node, *temp_node, *end;
    
    temp_node = cursor;

    previous_node = NULL;
    node = head;
    end = cursor->next;
    
    while (node->next != temp_node->next)
    {
        previous_node = node;
        node = node->next;
    }
  
    previous_node->next = end;
    node->next = head;
    head = node;
    cursor = head;

}


template<class DT>
void List<DT>::insertBefore(const DT& newElement)
{
    ListNode<DT> *temp, *previous, *node, *new_node;
    
    temp = cursor;
    node = head;
    
    new_node = new ListNode<DT>(newElement, cursor);
    for(previous = head; previous->next != cursor; previous = previous->next);
    cursor = previous;
    
    cursor->next = new_node;
    new_node->next = temp;
    cursor = new_node;
    head = node;

}
