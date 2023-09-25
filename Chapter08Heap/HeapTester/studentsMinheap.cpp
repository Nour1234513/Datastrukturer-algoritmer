#include "studentsMinheap.h"
#include "assert.h"



const char* nameOfStudent(){
    return "Nour alnajar";
}

MinHeap::MinHeap(int sizeOfArray)
    :m_sizeOfArray(sizeOfArray)
{    
    n_theArray = new int[m_sizeOfArray];
    m_size = 0;
}

MinHeap::~MinHeap(){
   // TODO
    delete [] n_theArray;
}

void MinHeap::insert(int data){
    // TODO
    assert(!(m_size==m_sizeOfArray));
    m_size+=1;
    int hole=m_size;
    while(data<n_theArray[hole/2]&&hole>1){
        n_theArray[hole]=n_theArray[hole/2];
        hole=hole/2;
    }
    n_theArray[hole]=data;

}


int MinHeap::min()
{
    // TODO
    return n_theArray[1];// BUG
}


void MinHeap::deleteMin(){
    assert( !isEmpty() );
    // TODO
    n_theArray[1]=n_theArray[m_size];
     m_size-=1;
    percolateDown(1);

}




void MinHeap::percolateDown(int ix){
    // TODO

   int value=n_theArray[ix];
    while(ix*2<=m_size){
        int kid=ix*2;
        if(kid!=m_size&&n_theArray[kid]>n_theArray[kid+1]){
            kid+=1;
        }
        if(value<n_theArray[kid])
            break;
        n_theArray[ix]=n_theArray[kid];
        ix=kid;
    }
    n_theArray[ix]=value;
}

int MinHeap::size()
{
    return m_size;
}


// Fyller heapens array med data utan att organisera det i en heap-struktur.
// (detta gör man istället interaktiv)
void MinHeap::fillArrayWithData(int *newData, int size)
{
    assert( size<m_sizeOfArray);

    for (int i=1; i<=size ; i+=1)
        n_theArray[i] = newData[i];
    m_size = size;
}
