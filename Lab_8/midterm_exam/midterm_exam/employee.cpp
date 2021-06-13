//
//  main.cpp
//  midterm_exam
//
//  Created by Leo  Innocenzi on 21/04/2021.
//

#include <iostream>

class EmployeeList {
    
public:
    
    EmployeeList();
    EmployeeList(const char *nameList, int size);
    ~EmployeeList();
    
    void showList();
    void deleteEmployee();
    
private:
    int size;
    const char *nameList[];
};

EmployeeList::EmployeeList(){}
EmployeeList::EmployeeList(const char *nameList, int size)
:size(size)
{
    
}

EmployeeList::~EmployeeList(){}
void EmployeeList::showList(){
    std::cout << "There is " << size << " employees in the list" << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << nameList[i] << std::endl;
    }
}



int main(int argc, const char * argv[]) {
    
    const char *name = ("Leo", "Alice" ,"Joude");
    EmployeeList list = *new EmployeeList(name, 3);
    
    list.showList();
}
