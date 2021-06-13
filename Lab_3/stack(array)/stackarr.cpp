//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stackarr.h"

//--------------------------------------------------------------------
template <class DT>
Stack<DT>::Stack(int maxNumber) throw(std::bad_alloc)
:maxSize(maxNumber),
top(-1)
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
void Stack<DT>::push(const DT& newDataItem) throw(std::bad_alloc)
{
    assert(top < maxSize);
    dataItem[++top] = newDataItem;
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop() throw(std::logic_error)
{
    assert(top != -1);
    return dataItem[top--];
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
    top = -1;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
    return(top == -1);
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
    return(top == maxSize -1);
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::showStructure() const
{

    int i;
    if (top == -1)
        std::cout << "Empty stack" << std::endl;
    else{
        std::cout << "top = " << top << std::endl;
        for (i = 0; i < maxSize; i++)
            std::cout << i << "\t";
        std::cout << std::endl;
        
        for (i = 0; i <= top; i++)
            std::cout << dataItem[i] << "\t";
        std::cout << std::endl;
    }

}
