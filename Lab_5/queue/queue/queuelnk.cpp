//
//  queuelnk.cpp
//  queue
//
//  Created by Leo  Innocenzi on 10/04/2021.
//

#include "queueLnk.h"
#include <stdio.h>


template <class DT>
QueueNode<DT>:: QueueNode( const DT &data, QueueNode<DT> *nextPtr )

  : dataItem(data),
    next(nextPtr)
{}


template <class DT>
Queue<DT>:: Queue ( int ignored )


  : front(0),
    rear(0)
{}


template <class DT>
Queue<DT>:: ~Queue ()


{
    clear();
}


template <class DT>
void Queue<DT>:: enqueue (const DT &newData)


{
    QueueNode<DT> *p;

    p = new QueueNode<DT>(newData,0);
    assert ( p != 0 );

    if ( front == 0 )
       front = p;
    else
       rear->next = p;
    rear = p;
}


template <class DT>
DT Queue<DT>:: dequeue ()

{
    QueueNode<DT> *p;
    DT temp;

    assert ( front != 0 );

    temp = front->dataItem;
    p = front;
    front = front->next;
    if ( front == 0 )
       rear = 0;
    delete p;

    return temp;
}


template <class DT>
void Queue<DT>:: clear ()



{
    QueueNode<DT> *p,
                  *nextP;
    p = front;
    while ( p != 0 )
    {
        nextP = p->next;
        delete p;
        p = nextP;
    }

    front = 0;
    rear  = 0;
}


//--------------------------------------------------------------------

template <class DT>
bool Queue<DT>::isEmpty () const

{
    return ( front == 0 );
}

//--------------------------------------------------------------------

template <class DT>
bool Queue<DT>::isFull () const

{
    return(1);
}


//--------------------------------------------------------------------

template <class DT>
void Queue<DT>::showStructure() const

{
    QueueNode<DT> *p;

    if ( front == 0 )
       std::cout << "Empty queue" << std::endl;
    else
    {
       std::cout << "front ";
       for ( p = front ; p != 0 ; p = p->next )
           std::cout << p->dataItem << " ";
       std::cout << "rear" << std::endl;
    }
}

template <class DT>
void Queue<DT>::putFront(const DT &newDataItem)
{
    QueueNode<DT> *temp, *previous, *new_node;
    new_node = new QueueNode<DT>(newDataItem, front);
    
    if (front){
        front = new_node;
    }
    else {
        temp = front;
        
        new_node->next = front;
        front = new_node;
    }
    
    
}

template <class DT>
DT Queue<DT>::getRear(){
    DT temp;
    QueueNode<DT> *sec_node;
    
    if (rear == NULL)
            return NULL;
      
        if (front->next == NULL) {
            delete front;
            return NULL;
        }
      
        // Find the second last node
        sec_node = front;
        while (sec_node->next->next != NULL)
            sec_node = sec_node->next;
      
        // Delete last node
        delete (sec_node->next);
      
        // Change next of second last
        sec_node->next = NULL;
      
        return rear->dataItem;
}

template <class DT>
int Queue<DT>::getLength() const{
    
    int size;
    size = (rear - front) + 1;
    return size;
}
