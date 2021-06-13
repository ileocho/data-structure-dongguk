//--------------------------------------------------------------------
//
//  Laboratory C, In-lab Exercise 2                        sort.cpp
//
//  Implementation of a set of sorting routines
//
//--------------------------------------------------------------------
#include <iostream>

template < class DT >
void selectionSort(DT keyList[], int numKeys)

// Selection sort routine. Sorts the first numKeys keys in keyList
// into ascending order.

{
    int i, j, index_min;
    for (i = 0; i < numKeys-1; i++) {
        index_min = i;
        for (j = i+1; j < numKeys; j++)
        if (keyList[j] < keyList[index_min])
            index_min = j;
        std::swap(keyList[index_min], keyList[i]);
       }
}

//--------------------------------------------------------------------

template < class DT >
void quickPartition(DT keyList[], int numKeys, int left, int right);

template < class DT >
void quickSort(DT keyList[], int numKeys)

// Quicksort routine. Sorts the first numKeys keys in keyList into
// ascending order.

{
    quickPartition(keyList, numKeys, 0, numKeys - 1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void quickPartition(DT keyList[], int numKeys,
    int left, int right)

    // Recursive partner of the quickSort routine. Partitions the array
    // entries between left and right into two subarrays. One subarray
    // contains the keys that are less than or equal to splitValue, and
    // the other contains the keys that are greater than splitValue.
    // Recursively sorts each of these subarrays.

{
    int splitValue = keyList[right]; // pivot
        int i = (left - 1); // Index of smaller element and indicates the right position of pivot found so far
     
        for (int j = left; j <= right - 1; j++)
        {
            // If current element is smaller than the pivot
            if (keyList[j] < splitValue)
            {
                i++; // increment index of smaller element
                std::swap(keyList[i], keyList[j]);
            }
        }
        std::swap(keyList[i + 1], keyList[right]);
}

//--------------------------------------------------------------------

template < class DT >
void bubbleSort(DT keyList[], int numKeys)

{
    int i, j;
    for (i = 0; i < numKeys-1; i++)
     
    // Last i elements are already in place
    for (j = 0; j < numKeys-i-1; j++)
        if (keyList[j] > keyList[j+1])
            std::swap(keyList[j], keyList[j+1]);
}
