#include "student2heapsort.h"
#include <algorithm>  // får ej anvädas

#include <assert.h>
#include <iostream>


const char* nameOfStudentHeapsort(){
    return "Nour alnajar";
}

// definiera gärna egna funktioner här.

float max(float *pBegin)
{
    // TODO
    return pBegin[1];
}
void percolateDown(int ix,float *pBegin,const int m_size){
    // TODO

    float value=pBegin[ix];
    while(ix*2<=m_size){
        int kid=ix*2;
        if(kid!=m_size&&pBegin[kid]<pBegin[kid+1]){
            kid+=1;
        }
        if(value>pBegin[kid])
            break;
        pBegin[ix]=pBegin[kid];
        ix=kid;
    }
    pBegin[ix]=value;
}

void deleteMax(float *pBegin,int &m_size){
    assert(m_size>1);
    pBegin[1]=pBegin[m_size];
    m_size-=1;
    percolateDown(1,pBegin,m_size);
}



void heapsort(float* pBegin, float* pEnd){
    // TODO
    pBegin=pBegin-1;
    int size=pEnd-pBegin-1;
    for(int x=size/2;x>0;x-=1){
        percolateDown(x,pBegin,size);
    }
    while(size>1){
        float swap=max(pBegin);
        deleteMax(pBegin,size);
        pBegin[size+1]=swap;
    }
}

/******************************************
Release mode!!
time to sort 8388608 floats with std::sort...
The time was 596 ms

time to sort 8388608 floats with heapsort...
The time was 1546 ms
*******************************************/
