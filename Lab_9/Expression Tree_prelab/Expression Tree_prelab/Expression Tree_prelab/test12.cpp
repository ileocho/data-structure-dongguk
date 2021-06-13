//--------------------------------------------------------------------
//		Lab 12									test.cpp
//
//  Test program for the operations in the Expression Tree ADT
//Leo Innocenzi 2020130265
//--------------------------------------------------------------------
#include <iostream>
#include "exprtree.h"    //pre-lab

using namespace std;

int main()
{
	ExprTree testExpression;  // Test expression

	cout << endl << "Enter an expression in prefix form : ";

	testExpression.build();
	testExpression.showStructure();
	testExpression.expression();
	cout << " = " << testExpression.evaluate() << endl;
	
    cout << endl << "Clear the tree" << endl;
    testExpression.clear();
    
    return 0;
}
