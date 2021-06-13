//
//  OrganisationTree.hpp
//  Project_3
//
//  Created by Leo  Innocenzi on 07/06/2021.
//

#include <iostream>
#include "listlnk.cpp"

class EmployeeNode;
using EmployeeNodePtr = EmployeeNode*;

class EmployeeNode {
public:
    EmployeeNode(std::string name, EmployeeNode* parent);
    
    auto getEmployee() {return(this);}
    
    void setChild(EmployeeNodePtr &newEmployee) {children.insert(newEmployee);}
    bool hasChild() {return (!children.isEmpty());}
    
    auto getChild() {return(children.getCursor());}
    
    auto findChildByName(std::string queryname) -> EmployeeNode*
        {
            children.gotoBeginning();
            
        for(children; children.getCursor()->getName() == queryname ;children.gotoNext())
            return children.getCursor();

        for (EmployeeNodePtr child = children.getCursor(); children.getCursor()->hasChild(); children.gotoNext())
        {
            EmployeeNode* n = child->findChildByName(queryname);
            if (n != nullptr)
                return n;
        }
        return nullptr;
    }
    
    std::string getName() {return name;}
    
private:
    std::string name;
    EmployeeNode *parent;
    List<EmployeeNodePtr> children;
};

EmployeeNode::EmployeeNode(std::string employeeName, EmployeeNode* employeeParent)
:name(employeeName), parent(employeeParent)
{
}

class EmployeeTree {
public:
    EmployeeTree();
    ~EmployeeTree();
    
    void hireCEO(EmployeeNode *newEmployee);
    void hireEmployee(EmployeeNode *boss, std::string newEmployee);
    
    auto find(std::string employee) -> EmployeeNode*;
    
    void print(EmployeeTree Tree);
    
private:
    int level, age;
    EmployeeNodePtr root;
};

EmployeeTree::EmployeeTree()
:root(0)
{}

EmployeeTree::~EmployeeTree()
{}

void EmployeeTree::hireCEO(EmployeeNode *newEmployee)
{
    root = newEmployee;
}

void EmployeeTree::hireEmployee(EmployeeNode* boss, std::string newEmployee)
{
    EmployeeNodePtr newChild = new EmployeeNode(newEmployee, boss);
    boss->setChild(newChild);
}

auto EmployeeTree::find(std::string employee) -> EmployeeNode*
{
    if (root->getName() == employee)
        return root->getEmployee();
    return root->findChildByName(employee);
}


void print(EmployeeTree Tree) {
    
}



