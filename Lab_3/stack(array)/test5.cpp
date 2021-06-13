//--------------------------------------------------------------------
//
//  Laboratory 5                                           test5.cpp
//
//  Test program for the operations in the Stack ADT
//
//--------------------------------------------------------------------
#include <iostream>
//#include "stackarr.cpp"
//#include "stackdwn.cpp"
#include "palindrome.cpp"

//-------------------------------------------------------------------

int main()
{
	Stack<char> testStack(8);     // Test stack
    char testElement = '\0';             // Stack element
	char cmd;                     // Input command

	std::cout << std::endl << "Commands:" << std::endl;
	std::cout << "  +x : Push x" << std::endl;
	std::cout << "  -  : Pop" << std::endl;
	std::cout << "  C  : Clear" << std::endl;
    std::cout << "  E  : Empty stack?" << std::endl;
    std::cout << "  F  : Full stack?" << std::endl;
	std::cout << "  Q  : Quit the test program" << std::endl;
	std::cout << std::endl;

	do
	{
		testStack.showStructure();                    // Output stack

		std::cout << std::endl << "Command: ";                  // Read command
		std::cin >> cmd;
		if (cmd == '+')
			std::cin >> testElement;

		switch (cmd)
		{
		case '+':                                  // push
			std::cout << "Push " << testElement << std::endl;
			testStack.push(testElement);
			break;

		case '-':                                  // pop
			std::cout << "Popped " << testStack.pop() << std::endl;
			break;

		case 'C': case 'c':                       // clear
			std::cout << "Clear the stack" << std::endl;
			testStack.clear();
			break;

		case 'E': case 'e':                       // empty
			if (testStack.isEmpty())
				std::cout << "Stack is empty" << std::endl;
			else
				std::cout << "Stack is NOT empty" << std::endl;
			break;

		case 'F': case 'f':                       // full
			if (testStack.isFull())
				std::cout << "Stack is full" << std::endl;
			else
				std::cout << "Stack is NOT full" << std::endl;
			break;

		case 'Q': case 'q':                   // Quit test program
			break;

		default:                               // Invalid command
			std::cout << "Inactive or invalid command" << std::endl;
		}
	} while (cmd != 'Q'  &&  cmd != 'q');
    
    std::string str = "abcdefgfedcba";
    isPalindrome(str);
    
    return(0);
}
