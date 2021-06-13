//--------------------------------------------------------------------
//
//  Laboratory 11                                         test11.cpp
//
//  Test program for the operations in the Binary Search Tree ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "bstree.cpp"



//--------------------------------------------------------------------
//
// Declaration for the binary search tree data item class
//

class TestData
{
public:

    void setKey(int newKey)
    {
        keyField = newKey;
    }   // Set the key

    int key() const
    {
        return keyField;
    }     // Returns the key

private:

    int keyField;                // Key for the data item
};

//--------------------------------------------------------------------

void print_help()
{
    std::cout << std::endl << "Commands:" << std::endl;
    std::cout << "  P    : Help (displays this message)" << std::endl;
    std::cout << "  +key : Insert (or update) data item" << std::endl;
    std::cout << "  ?key : Retrieve data item" << std::endl;
    std::cout << "  -key : Remove data item" << std::endl;
    std::cout << "  K    : Write keys in ascending order" << std::endl;
    std::cout << "  C    : Clear the tree" << std::endl;
    std::cout << "  E    : Empty tree?" << std::endl;
    std::cout << "  F    : Full tree?" << std::endl;
    std::cout << "  H    : Height of tree" << std::endl;
    std::cout << "  Q    : Quit the test program" << std::endl;
    std::cout << std::endl;
}

int main()
{
    BSTree<TestData, int> testTree;   // Test binary search tree
    TestData testData;               // Binary search tree data item
    int inputKey;                    // User input key
    char cmd;                        // Input command

    print_help();

    do
    {
        testTree.showStructure();                     // Output tree

        std::cout << std::endl << "Command: ";                  // Read command
        cin >> cmd;
        if (cmd == '+' || cmd == '?' ||
            cmd == '-' || cmd == '<')
            cin >> inputKey;

        switch (cmd)
        {
        case 'P': case 'p':
            print_help();
            break;

        case '+':                                  // insert
            testData.setKey(inputKey);
            std::cout << "Insert : key = " << testData.key()
                << std::endl;
            testTree.insert(testData);
            break;

        case '?':                                  // retrieve
            if (testTree.retrieve(inputKey, testData))
                std::cout << "Retrieved : key = "
                << testData.key() << std::endl;
            else
                std::cout << "Not found" << std::endl;
            break;

        case '-':                                  // remove
            if (testTree.remove(inputKey))
                std::cout << "Removed data item" << std::endl;
            else
                std::cout << "Not found" << std::endl;
            break;

        case 'K': case 'k':                       // writeKeys
            std::cout << "Keys:" << std::endl;
            testTree.writeKeys();
            break;

        case 'C': case 'c':                       // clear
            std::cout << "Clear the tree" << std::endl;
            testTree.clear();
            break;

        case 'E': case 'e':                       // empty
            if (testTree.isEmpty())
                std::cout << "Tree is empty" << std::endl;
            else
                std::cout << "Tree is NOT empty" << std::endl;
            break;

        case 'F': case 'f':                       // full
            if (testTree.isFull())
                std::cout << "Tree is full" << std::endl;
            else
                std::cout << "Tree is NOT full" << std::endl;
            break;

        case 'h': case 'H':
            std::cout << "Height of Tree: " << testTree.height() << std::endl;
            break;

        case 'Q': case 'q':                   // Quit test program
            break;

        default:                               // Invalid command
            std::cout << "Inactive or invalid command" << std::endl;
        }
    } while ((cmd != 'Q') && (cmd != 'q'));
    return 0;
}
