#include "student4_arrayque.h"
#include "assert.h"
#include <iostream>
using namespace std;


const char* nameOfStudentAQue(){
    return "Nour alnajar";
}



AQue::AQue()
{
    // TODO

    m_indexOfFront=0;
    m_capacity=10;
    m_size=0;
    m_pArr= new float[m_capacity];
}

AQue::~AQue()
{
    // TODO

    delete [] m_pArr;

}


void AQue::pushBack(float value)
{
    // TODO

    m_pArr[(m_indexOfFront+m_size) % m_capacity]=value;
    m_size+=1;
    if(m_size==m_capacity){
        float *newarr=new float[m_capacity*2];
        for(int xi=0;xi<m_capacity;xi+=1){
            newarr[xi]=m_pArr[(m_indexOfFront+xi)%m_capacity];
        }
        m_indexOfFront=0;
        m_capacity=m_capacity*2;
        float *oldarr=m_pArr;
        m_pArr=newarr;
        delete [] oldarr;
    }

}

float &AQue::back()
{

    return m_pArr[(m_indexOfFront+m_size-1) % m_capacity];


}

void AQue::popFront()
{

    m_indexOfFront=(m_indexOfFront+1)%m_capacity;
    m_size-=1;
}

float &AQue::front()
{

    return m_pArr[m_indexOfFront];


}


int AQue::size() const
{
    // TODO
    return m_size; // felaktig kodrad, tag bort
}

