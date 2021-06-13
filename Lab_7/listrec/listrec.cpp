//--------------------------------------------------------------------
//
//  Laboratory 10                                         listrec.cs
//
//  (Shell) Partial linked list implementation of the List ADT with
//  additional recursive linked list functions
//
//--------------------------------------------------------------------

#include <iostream>
#include "listrec.h"


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
    clear();
}

//------------------------------------------------


template<class DT>
void List<DT>::insert(const DT& newData)
{
    if (head == 0){
        head = new ListNode<DT>(newData, 0);
        cursor = head;
    }
    
    else{
        cursor->next = new ListNode<DT>(newData, cursor->next);
        assert(cursor->next != 0);
        cursor = cursor->next;
    }
    
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


//--------------------------------------------------------------------
//
// Recursively implemented linked list functions used in the Prelab
// Exercise
//
//--------------------------------------------------------------------

template < class DT >
void List<DT>:: write () const

// Outputs the data in a list from beginning to end. Assumes that
// objects of type DT can be output to the cout stream.

{
    std::cout << "List : ";
    writeSub(head);
    std::cout << std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: writeSub ( ListNode<DT> *p ) const

// Recursive partner of the write() function. Processes the sublist
// that begins with the node pointed to by p.

{
    if ( p != 0 )
    {
       std::cout << p->dataItem;      // Output data
       writeSub(p->next);    // Continue with next node
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: insertEnd ( const DT &newDataItem )

// Inserts newDataItem at the end of a list. Moves the cursor to
// newDataItem.

{
    insertEndSub(head,newDataItem);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: insertEndSub ( ListNode<DT> *&p,
                               const DT &newDataItem )

// Recursive partner of the insertEnd() function. Processes the
// sublist that begins with the node pointed to by p.

{
    if ( p != 0 )
       insertEndSub(p->next,newDataItem);    // Continue searching for
    else                                     // end of list
    {
       p = new ListNode<DT>(newDataItem,0);  // Insert new node
       cursor = p;                           // Move cursor
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: writeMirror () const

// Outputs the data in a list from beginning to end and back
// again. Assumes that objects of type DT can be output to the cout
// stream.

{
    std::cout << "Mirror : ";
    writeMirrorSub(head);
    std::cout << std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: writeMirrorSub ( ListNode<DT> *p ) const

// Recursive partner of the writeMirror() function. Processes the
// sublist that begins with the node pointed to by p.

{
    if ( p != 0 )
    {
       std::cout << p->dataItem;           // Output data (forward)
       writeMirrorSub(p->next);   // Continue with next node
       std::cout << p->dataItem;           // Output data (backward)
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: reverse ()

// Reverses the order of the data items in a list.

{
    reverseSub(0,head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: reverseSub ( ListNode<DT> *p, ListNode<DT> *nextP )

// Recursive partner of the reverse() function. Processes the sublist
// that begins with the node pointed to by nextP.

{
    if ( nextP != 0 )
    {
       reverseSub(nextP,nextP->next);   // Continue with next node
       nextP->next = p;                 // Reverse link
    }
    else
       head = p;                        // Move head to end of list
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>:: deleteEnd ()

// Deletes the data at the end of a list. Moves the cursor to the
// beginning of the list.

{
    deleteEndSub(head);
    cursor = head;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>:: deleteEndSub ( ListNode<DT> *&p )

// Recursive partner of the deleteEnd() function. Processes the
// sublist that begins with the node pointed to by p.

{
    if ( p->next != 0 )
       deleteEndSub(p->next);   // Continue looking for the last node
    else
    {
       delete p;                // Delete node
       p = 0;                   // Set p (link or head) to null
    }
}

//--------------------------------------------------------------------

template < class DT >
int List<DT>:: getLength () const

// Returns the number of data items in a list.

{
    return getLengthSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
int List<DT>:: getLengthSub ( ListNode<DT> *p ) const

// Recursive partner of the length() function. Processes the sublist
// that begins with the node pointed to by p.

{
    int result;   // Result returned

    if ( p == 0 )
       result = 0;                            // End of list reached
    else
       result = (getLengthSub(p->next) + 1 );   // Number of nodes after
                                              // this one + 1
    return result;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template < class DT >
void List<DT>::cRemove()
{
    cRemoveSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template < class DT >
void List<DT>::cRemoveSub(ListNode<DT> *&p)
{
    char value = 'c';
    
    if (p == NULL){
        std::cout<< "List without all 'c' chars : " << std::endl;
    }
    else if (p->dataItem == value){
        p = p->next;
        cRemoveSub(p);
    }
    else{
        cRemoveSub(p->next);
    }
}
