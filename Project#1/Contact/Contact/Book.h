//
//  Book.hpp
//  Contact
//
//  Created by Leo  Innocenzi on 12/04/2021.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


class Contact { //Contact class handeling contact data
public:
    
    std::string firstName;
    std::string lastName;
    std::string coutryCode;
    std::string endNumber;
    std::string fullDate;
    
    int day;
    int month;
    int year;
    int ID;

    
    Contact();
    ~Contact();
};

Contact::Contact(){}
Contact::~Contact(){}

class Book{
    
public:
    Book();
    Book(std::string Infile);
    ~Book();
    
    void readFromFile();
    void writeToFile(std::string outFile);
    
    void addEntry();
    void deleteEntry();
    
    void selectMonth();
    
    void countBirthday();

    
private:
    Contact dataContact;
    std::string file;
    std::vector<Contact> contactBook;

    friend class Contact;
};

Book::Book() {}
Book::Book(std::string inFile) :file(inFile) {}
Book::~Book(){}


void Book::readFromFile(){
    
    std::ifstream dataFile(file);
    Contact dataContact;
    
    std::string first_name = dataContact.firstName; //creating local variables to show information and connect to class
    std::string last_name = dataContact.lastName;
    std::string code = dataContact.coutryCode;
    std::string end = dataContact.endNumber;
    std::string date = dataContact.fullDate;

    int n = 0;
    while(dataFile >> first_name >>  last_name >>  code >>  end >>  date) //while data exists
    {
        n++;
        dataContact.ID = n;
        std::cout << "Contact number : " << dataContact.ID << std::endl;
        std::cout << first_name << ' ' << last_name << '\n' << code << ' ' << end << '\n' << date << "\n\n"; //showing info
        
        std::stringstream ss(date); //stringstream to handle birthdate
        std::string token;
        int i = 0;
        while(std::getline(ss, token, '/')) //seperate day, month, year to handle birthdays
        {
            if(i == 0)
                dataContact.month = std::stoi(token);
            if(i == 1)
                dataContact.day = std::stoi(token);
            if(i == 2)
                dataContact.year = std::stoi(token);
            i++;
        }
        
        dataContact.firstName = first_name; //assigning local variables to class variables
        dataContact.lastName = last_name;
        dataContact.coutryCode = code;
        dataContact.endNumber = end;
        dataContact.fullDate = date;
        
        contactBook.push_back(dataContact);

    }
    
    
    
    dataFile.close();
    std::cout << n << " contacts in " << file << std::endl;;
    std::cout<< "Number of birthdays :" << std::endl;
    countBirthday();
    
}

void Book::addEntry(){
    
    Contact newContact;
    
    std::string first_name = newContact.firstName; //creating local variables to show information and connect to class for new contact
    std::string last_name = newContact.lastName;
    std::string code = newContact.coutryCode;
    std::string end = newContact.endNumber;
    std::string date = newContact.fullDate;
    
    std::cout << "Create new contact : " << std::endl;
    
    std::cout << "First name : ";
    std::cin >> first_name;
    newContact.firstName = first_name;
    
    std::cout << "Last name : ";
    std::cin >> last_name;
    newContact.lastName = last_name;
    
    std::string country_code;
    std::string number;
    std::cout << "Phone number : ";
    std::cin >> country_code >> number;
   
    newContact.coutryCode = country_code;
    newContact.endNumber = number;
    
    std::string full_date;
    std::cout << "Birthdate (MM/DD/YYYY) : ";
    std::cin >> full_date;
    newContact.fullDate = full_date;
    
    std::stringstream ss_birthdate(full_date); //stringstream to handle birthdate
    std::string token_bd;
    int j = 0;
    while(std::getline(ss_birthdate, token_bd, '/')) //seperate day, month, year to handle birthdays
    {
        if(j == 0)
            newContact.month = std::stoi(token_bd);
        if(j == 1)
            newContact.day = std::stoi(token_bd);
        if(j == 2)
            newContact.year = std::stoi(token_bd);
        j++;
    }
    
    dataContact.ID = dataContact.ID + 1;
    std::cout << "\nNew contact created.\n " << std::endl;
    std::cout << newContact.firstName << ' ' << newContact.lastName << std::endl;
    std::cout << '('<< newContact.coutryCode << ')' << ' ' << newContact.endNumber << std::endl;
    std::cout << newContact.fullDate << std::endl;
    
    contactBook.push_back(newContact);
    std::cout << std::end(contactBook)->ID << " contacts in the list." << std::endl;;
    std::cout<< "Number of birthdays :" << std::endl;
    countBirthday();
    
    
}

void Book::deleteEntry()
{
    std::string fn, ln;
    std::cout << "Write a contact name to delete entry: " << std::endl;
    std::cin >> fn >> ln;
    Contact dummy;
    dummy.firstName = fn;
    dummy.lastName = ln;
    
    std::vector<Contact>::iterator contact, end;
    for(contact = contactBook.begin(), end = contactBook.end(); contact != end; ++contact)
    {
        if (dummy.firstName == contact->firstName && dummy.lastName == contact->lastName)
        {
            int contactID = contact->ID;
            contactBook.erase(contactBook.begin() + contactID - 1);
            std::cout << "Succesfully deleted " << contactBook[contactID- 1].firstName << std::endl;
        }
    }
    countBirthday();
}

void Book::countBirthday()
{
    int intMonths[12] = { 0 };
    std::string textMonth[12] = {"January", "Fabuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    std::vector<Contact>::iterator contact, end;
    for(contact = contactBook.begin(), end = contactBook.end(); contact != end; ++contact) {
        for(int i = 1; i <= 12; i++) {
            if (contact->month == i)
                intMonths[i - 1]++;
        }
    }
    
    for(int j = 0; j <= 11; j++) {
        if(intMonths[j] > 0) {
            std::cout << textMonth[j] << " : " << intMonths[j] << std::endl;;
        }
    }
    
}

void Book::writeToFile(std::string outFile)
{
    std::ofstream outfile;
    outfile.open(outFile);
    std::vector<Contact>::iterator contact, end;
    for(contact = contactBook.begin(), end = contactBook.end(); contact != end; ++contact)
    {
        outfile << contact->firstName << " " << contact->lastName << std::endl;
        outfile << contact->coutryCode << " " << contact->endNumber << std::endl;
        outfile << contact->fullDate << std::endl;
        outfile << std::endl;
        std::cout << "Wrote " << contact->firstName << " " << contact->lastName << " to " << outFile << std::endl;
    }
    outfile.close();
}

void Book::selectMonth() {
    
    std::string textMonth[12] = {"January", "Fabuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    std::string month;
    int i;
    int bdNumber = 0;
    std::cout << "Enter a month : ";
    std::cin >> month;
    
    std::vector<Contact>::iterator contact, end;
    for(contact = contactBook.begin(), end = contactBook.end(); contact != end; ++contact) {
        for(i = 1; i <= 12; i++){
            if((month == textMonth[i - 1]) && (i == contact->month)) {
                bdNumber++;
            }
        }
    }
    std::cout << month << " : " << bdNumber;
}
