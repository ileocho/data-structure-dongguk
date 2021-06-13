//
//  palindrome.cpp
//  stackarr
//
//  Created by Leo  Innocenzi on 29/03/2021.
//
#include <iostream>
#include "stackarr.cpp"

bool isPalindrome(std::string word) {

    int wordSize = word.size();

    //load the stack
    Stack<char> s;
    int sizeofStack = 0;
    char last_char = word[round(wordSize/2)];
    
    for (int i = 0; i < wordSize / 2; i++) {
        s.push(word[0]);
        word.erase(0, 1);
        sizeofStack++;
    }
    
    //make sure word size is same as stack size (handle odd-character palindromes)
    if (word.size() > sizeofStack) {
        word.erase(0, 1);
    }

    //if our stack is empty, then return true
    if (sizeofStack == 0) {
        return true;
    }
    
    //check if our word is a palindrom
    while (sizeofStack > 0) {

        if (last_char == word[0]) {
            s.pop();
            word.erase(0, 1);

            if (sizeofStack == 0 || word.size() == 0) {
                return true;
            }
        }
        else {
            return false;
        }
    }
    return (0);
}


