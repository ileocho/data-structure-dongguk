//--------------------------------------------------------------------
//
//  Laboratory 14                                          wtgraph.cpp
//
//  Implementation of the Weighted Graph ADT
//
//--------------------------------------------------------------------
#include "wtgraph.h"

//--------------------------------------------------------------------

WtGraph::WtGraph(int maxNumber)
:size(0), maxSize(maxNumber)
{
    vertexList = new Vertex[maxNumber];
    adjMatrix = new int[infiniteEdgeWt];
    pathMatrix = new int[infiniteEdgeWt];
}

WtGraph::~WtGraph()
{
    delete [] vertexList;
    delete [] adjMatrix;
    delete [] pathMatrix;
}

//--------------------------------------------------------------------

int WtGraph::getIndex(char* v)
{
    for(int i = 0; i < vertexLabelLength; i++){
        if (vertexList[i].label[0] == *v)
            return i;
    }
    return(12);
}

int WtGraph::getEdge(int row, int col)
{
    return(adjMatrix[size*row + col]);
}

void WtGraph::setEdge(int row, int col, int wt) 
{
    adjMatrix[size*row + col] = wt;
}

int WtGraph::getPath(int row, int col){
    return pathMatrix[size*row + col];
}

void WtGraph::setPath(int row, int col, int wt){
    pathMatrix[size*row + col] = wt;
}
//--------------------------------------------------------------------

void WtGraph::insertVertex(Vertex newVertex)
{
	if (size == defMaxGraphSize)
        std::cout << "Graph size is full." <<std::endl;
    else if (retrieveVertex(newVertex.label, newVertex) == 1)
        std:cout << "This vertex already exists." << std::endl;
    else {
        vertexList[size] = newVertex;
        size++;
        
        for(int i = 0; i < size; i++){
            setEdge(size, i, infiniteEdgeWt);
            setPath(size, i, infiniteEdgeWt);
            
            setPath(i, size, infiniteEdgeWt);
            setEdge(i, size, infiniteEdgeWt);
        }
    }
}

void WtGraph::insertEdge(char* v1, char* v2, int wt)
{
	if(getIndex(v1) == 12 || getIndex(v2) == 12)
        std::cout << "Please enter a valid input." << std::endl;
    else{
        setEdge(getIndex(v1), getIndex(v2), wt);
        setEdge(getIndex(v2), getIndex(v1), wt);
    }
}

//--------------------------------------------------------------------

bool WtGraph::retrieveVertex(char* v, Vertex& vData)
{
    for(int i = 0; i < size; i++) {
        if(vertexList[i].label[0] == *v)
            return (1);
    }
    return(0);
}

bool WtGraph::getEdgeWeight(char* v1, char* v2, int& wt)
{
    int row = getIndex(v1);
    int col = getIndex(v2);
    
    if(row == 12 || col == 12)
        return(0);
    else {
        wt = adjMatrix[size*row + col];
        return(1);
    }
}

//--------------------------------------------------------------------

void WtGraph::removeVertex(char* v)
{
    int n = 0;
    for(int i = 0; i < size; i++){
        if(vertexList[i].label[0] == *v) {
            n = i;
        }
    }
    size--;
     
    for(int i = n; i < size; i++){
        vertexList[i] = vertexList[i+1];
    }
}

void WtGraph::removeEdge(char* v1, char* v2)
{
    int row = getIndex(v1);
    int col = getIndex(v2);
    
    if(row == 12 || col == 12)
        std:cout << "Please enter a valid input." << std::endl;
    else {
        setEdge(row, col, 0);
        setEdge(col, row, 0);
    }
}

//--------------------------------------------------------------------

void WtGraph::clear()
{
    size = 0;
}

bool WtGraph::isEmpty() const
{
    if(size == 0)
        return(1);
    else
        return(0);
}

bool WtGraph::isFull() const
{
    if(size == defMaxGraphSize)
        return(1);
    else
        return(0);
}

//--------------------------------------------------------------------

void WtGraph:: showStructure ()

// Outputs a graph's vertex list, adjacency matrix, and path matrix.
// This operation is intended for testing/debugging purposes only.

{
    int wt,         // Edge weight
        row, col;   // Loop counters

    if ( size == 0 )
       cout << "Empty graph" << endl;
    else
    {
       cout << endl << "Vertex list : " << endl;
       for ( row = 0 ; row < size ; row++ )
           cout << row << '\t' << vertexList[row].label << endl;

       cout << endl << "Edge matrix : " << endl << '\t';
       for ( col = 0 ; col < size ; col++ )
           cout << col << '\t';
       cout << endl;
       for ( row = 0 ; row < size ; row++ )
       {
           cout << row << '\t';
           for ( col = 0 ; col < size ; col++ )
           {
               wt = getEdge(row,col);
               if ( wt == infiniteEdgeWt )
                  cout << "- \t";
               else
                  cout << wt << '\t';
           }
           cout << endl;
       }

       cout << endl << "Path matrix : " << endl << '\t';
       for ( col = 0 ; col < size ; col++ )
           cout << col << '\t';
       cout << endl;
       for ( row = 0 ; row < size ; row++ )
       {
           cout << row << '\t';
           for ( col = 0 ; col < size ; col++ )
           {
               wt = getPath(row,col);
               if ( wt == infiniteEdgeWt )
                  cout << "- \t";
               else
                  cout << wt << '\t';
           }
           cout << endl;
       }
    }
}

//--------------------------------------------------------------------

void WtGraph::computePaths()
{
for(int i = 0; i < size; i ++)
    for(int j = 0; j < size; j ++)
        setPath(i, j, getEdge(i, j));

for (int m = 0 ; m < size ; m++ )
    for (int j = 0 ; j < size ; j++ )
        for (int k = 0 ; k < size ; k++ )
            if (getEdge(j,m) != 0 && getEdge(m, k) != 0)
            {
                if (getPath(j, k) == 0 || getPath(j, k) > getEdge(j, m) + getEdge(m, k))
                {
                    if (j != k)
                    {
                        setPath(j, k, getEdge(j, m) + getEdge(m, k));
                        setPath(k, j, getEdge(j, m) + getEdge(m, k));
                    }
                }
            }
}
