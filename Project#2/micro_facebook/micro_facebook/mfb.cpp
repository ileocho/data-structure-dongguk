//
//  mfb.cpp
//  micro_facebook
//
//  Created by Leo  Innocenzi on 11/05/2021.
//

#include "mfb.h"

void print_help()
{
    std::cout << std::endl << "Commands:" << std::endl;
    std::cout << " P <name> : Create a person record of the specified name" << std::endl;
    std::cout << " F <name1> <name2> : Record that the two specified people are friends" << std::endl;
    std::cout << " U <name1> <name2> : Record that the two specified people are no longer friends" << std::endl;
    std::cout << " L <name> : Print out the friends of the specified person." << std::endl;
    std::cout << " Q <name1> <name2> : Check whether the two people are friends" << std::endl;
    std::cout << "  X   : Quit the program" << std::endl;
    std::cout << std::endl;
}

void keyboard_input() {
    
    Hashtable ht;
    Hashtable ht_friends;
    
    char cmd;
    
    std::string name;
    std::string name1;
    std::string name2;
    
    do {
        std::cout << "   ---   " << std::endl;
        std::cout << "Command : ";
        std::cin >> cmd;
        
        if (cmd == 'P' || cmd == 'p'){
            std::cin >> name;
            Person *newPerson = new Person(name);
            ht.put(name, newPerson);
        }
        
        else if (cmd == 'F' || cmd == 'f') {
            std::cin >> name1 >> name2;
            
            Person *f1 = ht.get(name1);
            Person *f2 = ht.get(name2);
            
            if (f1 == nullptr || f2 == nullptr)
            {
                std::cout << "One or both people don't exist." << std::endl;
            }
            else {
                f1->add(f2);
                f2->add(f1);
                
                ht_friends.put(name1, f2);
                ht_friends.put(name2, f1);
            }
        }
        
        else if (cmd == 'U' || cmd == 'u') {
            std::cin >> name1 >> name2;
            
            Person *oldF1 = ht.get(name1);
            Person *oldF2 = ht.get(name2);
            
            oldF1->remove(oldF2);
            oldF2->remove(oldF1);
            
            ht_friends.deleteh(name1);
            ht_friends.deleteh(name2);
            
        }
            
        else if (cmd == 'L' || cmd == 'l') {
            std::cin >> name;
            
            Person *person = ht.get(name);
            person->showList();
        }
        
        else if (cmd == 'Q' || cmd == 'q') {
            std::cin >> name1 >> name2;
            
            if (ht_friends.check(name1, name2))
                std::cout << "Yes, " << name1 << " and " << name2 << " are friends." << std::endl;
            else
                std::cout << "No, " << name1 << " and " << name2 << " are not friends."  << std::endl;
            
        }
        
    }while(cmd != 'X' || cmd != 'x');
    
    std::cout << "End of program" << std::endl;
}

void text_input(std::string file) {
    
    Hashtable ht;
    Hashtable ht_friends;
    
    char cmd;
    std::string name;
    std::string name1;
    std::string name2;
    
    std::ifstream dataFile(file);
    std::string line;
    
    if(!dataFile.is_open()) {
          std::cerr << "Error: file could not be opened" << std::endl;
       }
   while (cmd != 'X' && cmd != 'x') {
       
       std::cout << "   ---   " << std::endl;
       dataFile >> cmd;
        if (cmd == 'P' || cmd == 'p'){
            dataFile >> name;
            Person *newPerson = new Person(name);
            ht.put(name, newPerson);
        }
        
        else if (cmd == 'F' || cmd == 'f') {
            dataFile >> name1 >> name2;
            
            Person *f1 = ht.get(name1);
            Person *f2 = ht.get(name2);
            
            if (f1 == nullptr || f2 == nullptr)
            {
                std::cout << "One or both person doesn't exist." << std::endl;
            }
            else {
                f1->add(f2);
                f2->add(f1);
                
                ht_friends.put(name1, f2);
                ht_friends.put(name2, f1);
            }
        }
        
        else if (cmd == 'U' || cmd == 'u') {
            dataFile >> name1 >> name2;
            
            std::cout << name1 << " and " << name2 << " are not friends anymore." << std::endl;
            
            Person *oldF1 = ht.get(name1);
            Person *oldF2 = ht.get(name2);
            
            oldF1->remove(oldF2);
            oldF2->remove(oldF1);
            
            ht_friends.deleteh(name1);
            ht_friends.deleteh(name2);
            
        }
            
        else if (cmd == 'L' || cmd == 'l') {
            dataFile >> name;
            
            Person *person = ht.get(name);
            person->showList();
        }
        
        else if (cmd == 'Q' || cmd == 'q') {
            dataFile >> name1 >> name2;
            
            if (ht_friends.check(name1, name2))
                std::cout << "Yes, " << name1 << " and " << name2 << " are friends." << std::endl;
            else
                std::cout << "No, " << name1 << " and " << name2 << " are not friends."  << std::endl;
        }
   }
    std::cout << "End of program" << std::endl;
}


int main(){
    
    print_help();

    char choice;
    std::string file = "test2.txt";
    
    std::cout << "Please choose if you want to enter informations on Terminal or if you want to set a text file input : " << std::endl;
    std::cout << "K : Keyboard input" << std::endl;
    std::cout << "T : Text file input" << std::endl;
    std::cout << "Choice : ";
    std::cin >> choice;
    
    if (choice == 'K' || choice == 'k') {
        keyboard_input();
    }
    else if (choice == 'T' || choice == 't') {
        std::cout << "Enter text file name : ";
        
        text_input(file);
    }
    
    return 0;
}
