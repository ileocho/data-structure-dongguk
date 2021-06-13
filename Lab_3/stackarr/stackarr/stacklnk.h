//
//  stacklnk.hpp
//  stackarr
//
//  Created by Leo  Innocenzi on 27/03/2021.
//

const int defMaxStackSize = 10;

template <class DT>
class Stack; //forward declaration of stack


template <class DT>
class StackNode {
  private:

    // Constructor
    StackNode (const DT &nodeData, StackNode *nextPtr);

    // Data members
    DT dataItem; //stack element
    StackNode *next; //next element pointer

  friend class Stack<DT>;
};


template <class DT>
class Stack {
public:
    //constructor
    Stack (int ignored = 0, int maxNumber = defMaxStackSize);
    
    //destructor
    ~Stack();
    
    //stack manipulation operations
    void push(const DT &newDataItem);
    DT pop();
    void clear();
    
    //Stack status operations
    bool isEmpty() const;
    bool isFull() const;
    
    void showStructure() const;
    
private:
    //Data member
    StackNode<DT> *top;
    int maxSize;
    
};
