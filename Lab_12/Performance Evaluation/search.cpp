//--------------------------------------------------------------------
//
//  Laboratory C, In-lab Exercise 1                      search.cpp
//
//  Implementation of a set of searching routines
//
//--------------------------------------------------------------------

template < class DT >
int linearSearch(DT keyList[], int numKeys, DT searchKey, int& index)

    // Linear search routine. Searches the first numKeys keys in keyList
    // for searchKey. If searchKey is found, then returns 1 with index
    // returning the array index of the entry containing searchKey.
    // Otherwise, returns 0 with index returning the array index of the
    // entry containing the largest key that is smaller than searchKey
    // (or -1 if there is no such key).

{
    int i;
    for (i = 0; i < numKeys; i++){
        if (keyList[i] == searchKey) {
            index = i;
            return(1);
        }
        else {
            int index = keyList[0];
            for(int i = 0; i < numKeys; i++){
                if(keyList[i] > searchKey){
                    index = i - 1;
                }
            }
            return(0);
        }
    }
    
    return(-1);
}

//--------------------------------------------------------------------

template < class DT >
int binarySearch(DT keyList[], int numKeys, DT searchKey, int& index)

    // Binary search routine. Searches the first numKeys keys in keyList
    // for searchKey. If searchKey is found, then returns 1 with index
    // returning the array index of the entry containing searchKey.
    // Otherwise, returns 0 with index returning the array index of the
    // entry containing the largest key that is smaller than searchKey
    // (or -1 if there is no such key).

{
    if (keyList[numKeys] >= keyList[0]) {
        int midIndex = 1 + (numKeys - 1)/2;
     
            // If the element is present at the middle
            // itself
        if (keyList[midIndex] == searchKey)
            index = midIndex;
            return(1);
     
            // If element is smaller than mid, then
            // it can only be present in left subarray
        if (keyList[midIndex] > searchKey)
            index = midIndex - 1;
            return binarySearch(keyList, numKeys, searchKey, index);
     
            // Else the element can only be present
            // in right subarray
        index = midIndex + 1;
        return binarySearch(keyList, numKeys, searchKey, index);
        }
    else {
        int index = keyList[0];
        for(int i = 0; i < numKeys; i++){
            if(keyList[i] > searchKey){
                index = i - 1;
            }
        }
        return(0);
    }
        // We reach here when element is not
        // present in array
        return -1;
}
