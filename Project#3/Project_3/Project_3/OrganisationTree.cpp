//
//  OrganisationTree.cpp
//  Project_3
//
//  Created by Leo  Innocenzi on 07/06/2021.
//

#include "OrganisationTree.h"

int main() {

    EmployeeTree company;
    EmployeeNode *CEO;
    //EmployeeNode *Boss;

    CEO = new EmployeeNode("GreatCEO", nullptr);
    company.hireCEO(CEO);
    
    EmployeeNode* boss = company.find("GreatCEO");
    company.hireEmployee(boss, "RightHand");
    company.hireEmployee(boss, "LeftHand");
    company.hireEmployee(boss, "RightFoot");
    company.hireEmployee(boss, "LeftFoot");

    EmployeeNode* hand = company.find("RightHand");
    company.hireEmployee(hand, "Finger1");

    EmployeeNode* feet = company.find("LeftFoot");
    company.hireEmployee(feet, "Toe");
    
    
    
    /*
     std::cout << "Add CEO : " << std::endl;
     std::cout << "Name : ";
     std::cin >> ceoName;
     int cond = 1;
     
     do {
        
        std::cout << "Command :";
        std::cin >> boss >> cmd >> employee;
        
        if(cmd == "hires") {
            *Boss = Tree.find(boss);
            Tree.hireEmployee(Boss, employee);
            std::cout << "Continue ? :";
            std::cin >> cond;
        }
    
    }while(cond == 1);
     */ 
    return 0;
}
