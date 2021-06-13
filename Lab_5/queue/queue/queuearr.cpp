//
//  queuearr.cpp
//  queue
//
//  Created by Leo  Innocenzi on 06/04/2021.
//

#import <assert.h>
#import <iostream>
#import "queuearr.h"

template<class DT>
Queue<DT>::Queue(int maxNumber)
:maxSize(maxNumber), front(-1), rear(-1)
{
    dataItem = new DT [maxSize];
    assert(dataItem != 0);
}

template<class DT>
Queue<DT>::~Queue()
{
    delete [] dataItem;
}


template<class DT>
void Queue<DT>::enqueue(const DT &newElement)
{
    if((rear+1)%maxSize == front)
        std::cout << "Full queue." << std::endl;
    else {
        rear = ++rear % maxSize;
        dataItem[rear] = newElement;
        
        if (front == -1)
            front = 0;
    }

}

template<class DT>
DT Queue<DT>::dequeue()
{
    DT temp_element;
    
    assert(front != -1);
    temp_element = dataItem[front];
    if (front == rear){
        front = -1;
        rear = -1;
    }
    else
        front = (++front) %maxSize;
    
    return(temp_element);
}

template<class DT>
void Queue<DT>::clear()
{
    front = -1;
    rear = -1;
}


template<class DT>
bool Queue<DT>::isEmpty() const
{
    return(front == -1);
}

template<class DT>
bool Queue<DT>::isFull() const
{
    return((rear+1)%maxSize == front);
}

template <class DT>
void Queue<DT>::showStructure() const
{
    int i;
    
    if (front == -1) {
        std::cout << "Empty Queue" << std::endl;
    }
    
    else{
        std::cout << "front = " << front << "\t rear = " << rear << std::endl;
        for (i = 0; i < maxSize; i++)
            std::cout << i << "\t";
        std::cout << std::endl;
        
        
        if (rear >= front){
            for(i = 0; i < maxSize; i++)
            {
                if ((i <= rear) && (i>= front))
                    std::cout << dataItem[i] << "\t";
            
                else
                    std::cout << "\t";
            }
        }
        
        else{
            for(i = 0; i < maxSize; i++)
            {
                if (( i <= rear ) || (i >= front ))
                    std::cout << dataItem[i] << "\t";
                
                else
                    std::cout << "\t";
            }
        }
    }
}

template <class DT>
void Queue<DT>::putFront(const DT &newDataItem)
{
    assert((rear+1)%maxSize != front);
    
    if (front == 0 || front == -1) {
        front = maxSize-1;
        dataItem[front] = newDataItem;
    }
    else {
        --front;
        dataItem[front] = newDataItem;;
    }
}

template <class DT>
DT Queue<DT>::getRear(){
    
    DT temp_element;
    
    temp_element = dataItem[rear];
    rear = (--rear) %maxSize;;
    return temp_element;
}

template <class DT>
int Queue<DT>::getLength(){
    
    int size;
    
    if (front == 0){
        size = rear - front;
        size = size*((2*size+1)%2) + 1;
    }
    
    else if ((front != 0) && (rear != 0)){
        size = rear - front;
        size = size*((2*size+1)%2);
    }
    
    else if ((front != 0) && (rear == 0)){
        size = rear - front;
        size = size*((2*size+1)%2) + 1;
    }

    
    return size;
}









