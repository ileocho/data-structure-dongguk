//--------------------------------------------------------------------
//
//  Laboratory 10                                         test10.cpp
//
//  Test program for a set of recursive linked list functions
//
//--------------------------------------------------------------------

// Reads a list of characters and calls the specified recursive
// routine.

#include <iostream>
#include "listrec.cpp"

int main()
{
    List<char> testList;   // Test list
    char testData;         // List data element

    std::cout << std::endl << "Enter a list of characters : ";
    std::cin.get(testData);
    while ( testData != '\n' )
    {
        testList.insert(testData);
        std::cin.get(testData);
    }
    testList.showStructure();

    // Call a recursive routine by uncommenting the call you wish to
    // execute.
    
    testList.write();
    testList.insertEnd('!');
    testList.writeMirror();
    testList.reverse();
    testList.deleteEnd();
    std::cout << "length = " <<  testList.getLength() << std::endl;

    testList.cRemove();

    testList.showStructure();


    system("pause");
    
    return(0);
}
