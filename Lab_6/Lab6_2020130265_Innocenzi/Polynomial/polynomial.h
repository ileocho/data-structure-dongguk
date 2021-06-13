//
//  polynomial.hpp
//  polynomial
//
//  Created by Leo  Innocenzi on 15/04/2021.
//  2020130265

template<class DT>
class ListPoly;

template <class DT>
class ListNodePoly
{
private:

    // Constructor
    ListNodePoly(int value, int exponent, ListNodePoly* priorPtr, ListNodePoly* nextPtr);

    // Data members
    int dataItem;        // List data item
    int exponent;
    ListNodePoly *prior,
                 *next;

    friend class ListPoly<DT>;
};


template<class DT>
class ListPoly{
    
public:
    ListPoly();
    ~ListPoly();
    
    void addValue(int dataItem, int exponent); //add value
    bool isMember(int value); //function to check if exponent term already exists in ListNodePoly
    
    void polySort(); //sort polynomial terms by exponent value to ease display
    
    void clear(); //clears the polynomial node list
    void show(); //shows the polynom
    
    
    ListNodePoly<DT> *head,
                     *cursor;
};
