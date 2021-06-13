//2020130265 Leo Innocenzi

#include <iostream>
#include "listdbl.h"

using namespace std;

template < class DT >
ListNode<DT>::ListNode(const DT& data, ListNode* priorPtr, ListNode* nextPtr)
:dataItem(data), prior(priorPtr), next(nextPtr)
{

}

// Constructor
template < class DT >
List<DT>::List(int ignored)
:head(0), cursor(0)
{
    
}

// Destructor
template < class DT >
List<DT>::~List()
{
    clear();
}


//------------ List manipulation operations ------------------

// Insert after cursor
template < class DT >
void List<DT>::insert(const DT& newDataItem)
{
    ListNode<DT> *newNode;
    
    if(head == 0) {
        newNode = new ListNode<DT>(newDataItem, 0, 0);
        newNode->next = newNode;
        newNode->prior = newNode;
        head = newNode;
    }
    else {
        newNode = new ListNode<DT>(newDataItem, cursor, cursor->next);
        cursor->next->prior = newNode;
        cursor->next = newNode;
    }
    cursor = newNode;
}

// Remove data item
template < class DT >
void List<DT>::remove()
{
    ListNode<DT> *removedNode;
    
    removedNode = cursor;
    
    if(head->next == head) {
        head = 0;
        cursor = 0;
    }
    else {
        cursor->prior->next = cursor->next;
        cursor->next->prior = cursor->prior;
        if (head == cursor){
            head = cursor->next;
        }
        cursor = cursor->next;
    }
    
    delete removedNode;
}

// Replace data item
template < class DT >
void List<DT>::replace(const DT& newElement)
{
    if(cursor != head)
        cursor->dataItem = newElement;
    else
        std::cout << "List is empty." << std::endl;
}

// Clear list
template < class DT >
void List<DT>::clear()
{
    ListNode<DT> *node, *nextNode;
    
    node = cursor;
    
    if(head != 0){
        node = head;
        
        for(node = head; node == head; node->next = nextNode){
            nextNode = node->next;
            delete node;
            node = nextNode;
        }
        head = 0;
        cursor = 0;
    }
}


//------------ List status operations ------------------

// List is empty
template < class DT >
bool List<DT>::isEmpty() const
{
    return(head == 0);
}

// List is full
template < class DT >
bool List<DT>::isFull() const
{
    return 1;
}


//------------ List manipulation operations ------------------

// Go to beginning
template < class DT >
void List<DT>::gotoBeginning()
{
    cursor = head;
}

// Go to end
template < class DT >
void List<DT>::gotoEnd()
{
    cursor = head->prior;
}

// Go to next data item
template < class DT >
bool List<DT>::gotoNext()
{
    int result;
    if(cursor->next != 0) {
        cursor = cursor->next;
        result = 1;
    }
    else
        result = 0;
    
    return result;
}

// Go to prior data item
template < class DT >
bool List<DT>::gotoPrior()
{
    int result;
    if(cursor->next != head){
        cursor = cursor->prior;
        result = 1;
    }
    
    else
        result = 0;
    
    return result;
}


template < class DT >
DT List<DT>::getCursor() const
{
    DT cursorData;
    
    cursorData = cursor->dataItem;
    
    return cursorData;
}


//-----------------------------------------------------------

template < class DT >
void List<DT>::showStructure() const
{
    ListNode<DT> *node;
    
    if (head == 0)
        std::cout << "List is empty" << std::endl;
    
    else {
        node = head;
        do{
            if (node == cursor)
                std::cout << "[" << node->dataItem << "]" << "\t";
            else
                std::cout << node->dataItem << "\t";
            node = node->next;
        }while(node != head);
        std::cout << std::endl;
    }
}
