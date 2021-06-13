//
//  stackdwn.h
//
//  Created by Leo  Innocenzi on 27/03/2021.
//
#include <iostream>

const int defMaxStackSize = 100;

template < class DT >
class Stack
{
public:

    //constructor
    Stack(int maxNumber = defMaxStackSize) throw ( std::bad_alloc );

    //destructor
    ~Stack();

    void push(const DT& newElement) throw (std::bad_alloc);
    DT pop() throw (std::logic_error);
    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

private:


    int maxSize,
        top;
    DT* dataItem;
};

