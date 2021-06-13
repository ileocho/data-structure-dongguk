//--------------------------------------------------------------------
//
//  Laboratory 5                                          stackarr.h
//
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include <iostream>

const int defMaxStackSize = 100;   // Default maximum stack size

template < class DT >
class Stack
{
public:

    // Constructor
    Stack(int maxNumber = defMaxStackSize) throw ( std::bad_alloc );

    // Destructor
    ~Stack();

    // Stack manipulation operations
    void push(const DT& newElement) throw (std::bad_alloc);    // Push element
    DT pop() throw (std::logic_error);                             // Pop element
    void clear();                         // Clear stack

    // Stack status operations
    bool isEmpty() const;                    // Stack is empty
    bool isFull() const;                     // Stack is full

    // Output the stack structure -- used in testing/debugging
    void showStructure() const;

private:

    // Data members
    int maxSize,   // Maximum number of elements in the stack
        top;       // Index of the top element
    DT* dataItem;   // Array containing the stack elements
};

