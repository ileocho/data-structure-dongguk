//
//  main.cpp
//  Contact
//
//  Created by Leo  Innocenzi on 12/04/2021.
//

#include "Book.h"

void help(){
    std::cout << std::endl;
    std::cout << "R : Read data from .txt file" << std::endl;
    std::cout << "+ : Add data entry to list" << std::endl;
    std::cout << "- : Delete entry from list" << std::endl;
    std::cout << "M : Select a month" << std::endl;
    std::cout << "W : Write list to new .txt file" << std::endl;
    std::cout << "Q : Quit app" << std::endl;
    
}

int main() {
    
    Book dataBook("book.txt"); //enter name of textfile to read contacts from in dataBook() constructor
    std::string outFile;
    char choice;
    help();
    
    do{

        // Read command
        std::cout << "\nCommand: ";
        std::cin >> choice;
        
        switch(choice)
        {
            case 'R': case 'r':
                dataBook.readFromFile();
                break;
                
            case '+':
                dataBook.addEntry();
                break;
            case '-':
                dataBook.deleteEntry();
                break;
            case 'M': case 'm':
                dataBook.selectMonth();
                break;
            case 'W': case 'w':
                
                std::cout << "Enter new file name : ";
                std::cin >> outFile;
                dataBook.writeToFile(outFile);
                break;
                
            case 'Q': case 'q':
                break;
        }
    } while(choice != 'Q' && choice != 'q');

    return 0;
}
