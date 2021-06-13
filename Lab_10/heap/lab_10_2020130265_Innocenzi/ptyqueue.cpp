//2020130265
#include "ptyqueue.h"

template <class DT>
PtyQueue<DT>::PtyQueue(int maxNumber)
:Heap<DT>(maxNumber)
{
}

template<class DT>
void PtyQueue<DT>::enqueue(const DT& newDataItem)
{
    Heap<DT>::insert(newDataItem);
}

template<class DT>
DT PtyQueue<DT>::dequeue()
{
    DT frontElement;   // Stores the front element

    frontElement = Heap<DT>::removeMax();
    return frontElement;
}
