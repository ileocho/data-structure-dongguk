//
//  mfb.h
//  micro_facebook
//
//  Created by Leo  Innocenzi on 11/05/2021.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>
#include <unordered_map> //learned about unordered hashmap from https://stackoverflow.com/questions/3578083/what-is-the-best-way-to-use-a-hashmap-in-c


//---------classes and their declarations----------//
class Person; //forward declaration for friendList and Hashtable

class Hashtable {
    std::unordered_map<std::string, Person*> ht_map;

public:
    void put(const std::string key, Person *personPtr);
    Person* get(const std::string key);
    const bool check(const std::string key1, const std::string key2);
    void deleteh(const std::string key);
    
    friend class Person;
};

void Hashtable::put(const std::string key, Person *personPtr) {
    ht_map[key] = personPtr;
}

Person* Hashtable::get(const std::string key) {
    return ht_map[key];
}

const bool Hashtable::check(const std::string key1, const std::string key2) {
    bool f1 = ht_map.count(key1);
    bool f2 = ht_map.count(key2);
    
    return(f1 and f2);
}

void Hashtable::deleteh(const std::string key) {
    ht_map[key] = NULL;
    ht_map.erase(key);
}

//-------------------//

class friendList {
public:
    friendList();
    friendList(Person *p, friendList *prevPtr, friendList *next);
    ~friendList();

private:
    Person *p;
    friendList *prev, *next;
    
    friend class Person;
};

friendList::friendList()
:p(nullptr), next(0)
{}

friendList::friendList(Person *person, friendList *prevPtr, friendList *nextPtr)
:p(person), prev(prevPtr), next(nextPtr)
{
}

friendList::~friendList(){
    
}


//-------------------//

class Person {
public:
    Person(std::string personName);
    ~Person();
    
    void add(Person *newfriend);
    void remove(Person *oldfriend);
    void showList();
    
private:
    std::string personName;
    friendList *head, *cursor;
    
};

Person::Person(std::string name)
:personName(name), head(0), cursor(0)
{
    std::cout << "Created " << name << std::endl;
}

Person::~Person(){}

void Person::add(Person *newfriend)
//adds a person to a person's friendlist
{
    
    if (newfriend->personName == this->personName);
    
    else{
        std::cout << newfriend->personName << " became friend with " << this->personName << std::endl;
        friendList *newFriendNode;
        
        if(head == 0){
            newFriendNode = new friendList(newfriend, 0, 0);
            newFriendNode->next = newFriendNode;
            newFriendNode->prev = newFriendNode;
            head = newFriendNode;
        }

        else{
            cursor = head;
            newFriendNode = new friendList(newfriend, cursor, cursor->next);
            cursor->next->prev = newFriendNode;
            cursor->next = newFriendNode;
            head = newFriendNode;
        }
    }
}

void Person::remove(Person *oldfriend) {
    cursor = head;
    friendList *removedFriend;
    
    while(cursor->p != oldfriend){
        cursor = cursor->next;
    }
    removedFriend = cursor;
    
    if(cursor->next == cursor){
        head = 0;
        cursor = 0;
    }
    else {
        cursor->prev->next = cursor->next;
        cursor->next->prev = cursor->prev;
        if (head == cursor) {
            head = cursor->next;
        }
        cursor = cursor->next;
    }
    delete removedFriend;
}

void Person::showList()
{
    cursor = head;
    std::cout<< "Friends list of " << personName << std::endl;
    if (head == 0) {
        std::cout << personName << " has no friends." << std::endl;
    }
    else if (head != 0) {
        do{
            std::cout << cursor->p->personName << ", ";
            cursor = cursor->next;
        }while(cursor != head);
        std::cout << std::endl;
    }
}

//-------------------//
