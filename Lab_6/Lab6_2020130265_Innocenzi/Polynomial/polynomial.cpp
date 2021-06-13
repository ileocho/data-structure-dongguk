//
//  polynomial.cpp
//  polynomial
//
//  Created by Leo  Innocenzi on 15/04/2021.
//  2020139265

#include "polynomial.h"
#include <iostream>

template<class DT>
ListNodePoly<DT>::ListNodePoly(int value, int exponent, ListNodePoly<DT> *priorPtr, ListNodePoly<DT> *nextPtr)
:dataItem(value), exponent(exponent), next(nextPtr), prior(priorPtr)
{
    
}

template <class DT>
ListPoly<DT>::ListPoly()
:head(0), cursor(0)
{
    
}


template <class DT>
ListPoly<DT>::~ListPoly()
{
    clear();
}

template<class DT>
bool ListPoly<DT>::isMember(int v_exponent){
    
    ListNodePoly<DT> *currentTerm;
    int n = 0;
    currentTerm = head;
    while((currentTerm != head) || n<1){
        
        if(v_exponent == currentTerm->exponent)
            return(true);
        else{
            currentTerm = currentTerm->next;
        }
        n++;
    }
    return(false);
}


template <class DT>
void ListPoly<DT>::addValue(int value, int exponent)
{
    ListNodePoly<DT> *term;
    int v_exponent = exponent;
    
    if(head == 0)
    {
        term = new ListNodePoly<DT>(value, exponent, 0, 0);
        term->next = term;
        term->prior = term;
        head = term;
    }

    else if (isMember(v_exponent) == false)
    {
        term = new ListNodePoly<DT>(value, exponent, cursor, cursor->next);
        cursor->next->prior = term;
        cursor->next = term;
    }
    
    else{
        term = head;
        while(term->exponent != v_exponent)
        {
            term = term->next;
        }
        if(term->exponent == v_exponent)
            term->dataItem += value;
    }
    
    cursor = term;
}

template<class DT>
void ListPoly<DT>::polySort()
{
    if((head == NULL) || (head->next == head))
        std::cout << "No need to sort" << std::endl;
    
    else
    {
        int swapped;
        ListNodePoly<DT> *term, *nextTerm;
        
        do{
            swapped = 0;
            term = head;
            
            
            while(term->next != head){
                nextTerm = term->next;
                if(term->exponent < nextTerm->exponent){
                    std::swap(term->dataItem, nextTerm->dataItem);
                    std::swap(term->exponent, nextTerm->exponent);
                    swapped = 1;
                }
                term = term->next;
            }
        }while(swapped);
    }
}

template <class DT>
void ListPoly<DT>::clear()
{
    ListNodePoly<DT> *term, *nextTerm;
    
    term = cursor;
    
    if(head != 0){
        term = head;
        
        do{
            nextTerm = term->next;
            delete term;
            term = nextTerm;
        }while(term != head);
        head = 0;
        cursor = 0;
    }
}

template <class DT>
void ListPoly<DT>::show()
{
    ListNodePoly<DT> *term;
    
    if(head == 0)
        std::cout << "Empty polynomial." << std::endl;
    else{
        term = head;
        
        do{
            if(term == head)
                std::cout << term->dataItem << "x^" << term->exponent;
            else if(term->exponent == 0)
            {
                if(term->dataItem > 0)
                    std::cout << " + "<< term->dataItem;
                else if(term->dataItem > 0)
                    std::cout << " + "<< term->dataItem;
            }
            else if(term->dataItem >= 0)
                std::cout << " + " << term->dataItem << "x^" << term->exponent ;
            else if(term->dataItem < 0)
                std::cout << " - " << std::abs(term->dataItem) << "x^" << term->exponent ;
            term = term->next;

        }while(term != head);
        std::cout << std::endl;
    }
}


void print_help()
{
    std::cout << std::endl << "Commands:" << std::endl;
    std::cout << "  H   : Help (displays this message)" << std::endl;
    std::cout << "  +x y : Add x to the power of y" << std::endl;
    std::cout << "  -x y : Substract x to the power of y" << std::endl;
    std::cout << "  C   : Clear the polynome" << std::endl;
    std::cout << "  Q   : Quit the test program" << std::endl;
    std::cout << std::endl;
}

int main(){
    
    ListPoly<int> polyTest;
    int value;
    int exponent;
    char choice;
    
    print_help();
    
    do{
        polyTest.show();
        
        std::cout << std::endl << "Command: ";
        std::cin >> choice;
        
        switch(choice){
            case 'H': case 'h':
                print_help();
                break;
                
            case '+':
                std::cin >> exponent >> value;
                polyTest.addValue(value, exponent);
                polyTest.polySort();
                break;
            
            case '-':
                std::cin >> exponent >> value;
                polyTest.addValue((-1)*value, exponent);
                polyTest.polySort();
                break;
                
            case 'C': case 'c':
                polyTest.clear();
                break;
                
            case 'Q': case 'q':
                break;

        }
    }while (choice != 'Q' && choice != 'q');
    
    return(0);
}
