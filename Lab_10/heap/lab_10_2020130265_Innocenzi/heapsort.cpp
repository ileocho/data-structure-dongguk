//--------------------------------------------------------------------
//
//  Laboratory B, In-lab Exercise 2                     heapsort.cs
//
//  (Shell) heapSort() function
//2020130265
//--------------------------------------------------------------------
#include <iostream>

template < class DT >
void moveDown ( DT dataItem [], int root, int size )

// Restores the binary tree that is rooted at root to a heap by moving
// dataItem[root] downward until the tree satisfies the heap property.
// Parameter size is the number of data items in the array.

{
    int largest = root;
    int l = 2*root + 1;
    int r = 2*root + 2;
 
    // If left child is larger than root
    if (l < size && dataItem[l].pty() > dataItem[largest].pty())
        largest = l;
 
    // If right child is larger than largest so far
    if (r < size && dataItem[r].pty() > dataItem[largest].pty())
        largest = r;
 
    // If largest is not root
    if (largest != root) {
        std::swap(dataItem[root], dataItem[largest]);
 
        // Recursively heapify the affected sub-tree
        moveDown(dataItem, size, largest);
    }
}

//--------------------------------------------------------------------

template < class DT >
void heapSort ( DT dataItems [], int size )

// Heap sort routine. Sorts the data items in the array in ascending
// order based on priority.

{
    DT temp;   // Temporary storage
    int j;     // Loop counter

    // Build successively larger heaps within the array until the
    // entire array is a heap.

    for ( j = (size-1)/2 ; j >= 0 ; j-- )
        moveDown(dataItems,j,size);

    // Swap the root data item from each successively smaller heap with
    // the last unsorted data item in the array. Restore the heap after
    // each exchange.

    for ( j = size-1 ; j > 0 ; j-- )
    {
        temp = dataItems[j];
        dataItems[j] = dataItems[0];
        dataItems[0] = temp;
        moveDown(dataItems,0,j);
    }
}

