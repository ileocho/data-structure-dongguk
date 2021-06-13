//
//  stackdwn.cpp
//  stackarr
//
//  Created by Leo  innocenzi on 27/03/2021.
//

#include "stackdwn.h"

template <class DT>
Stack<DT>::Stack(int maxNumber) throw(std::bad_alloc)
:maxSize(maxNumber),
top(maxSize)
{
    dataItem = new DT[maxSize];
    assert(dataItem != 0);
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
    delete [] dataItem;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newDataitem) throw(std::bad_alloc)
{
    assert(top > 0);
    dataItem[--top] = newDataitem;
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop() throw(std::logic_error)
{
    assert(top != maxSize);
    return dataItem[top++];
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
    top = maxSize;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
    return(top == maxSize);
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
    return(top == 0);
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::showStructure() const
{

    int i;   // Loop counter

     if (top == maxSize)
        std::cout << "Empty stack" << std::endl;
    
     else {
        std::cout << "top = " << top << std::endl;
        for ( i = 0 ; i < maxSize ; i++ )
            std::cout << i << "\t";
         
        std::cout << std::endl;
         
        for ( i = 0 ; i < maxSize  ; i++ )
            if ( i < top )
               std::cout << " \t";
            else
               std::cout << dataItem[i] << "\t";
         
        std::cout << std::endl;
    }

}
