#include "student5_adeque.h"


const char* nameOfStudentADeque(){
    return "Nour alnajar";
}



ADeque::ADeque()
{
   m_capacity=10;
   m_indexfront=0;
   m_size=0;
   m_pArr=new float[m_capacity];
}

ADeque::~ADeque()
{
    delete [] m_pArr;
}

void ADeque::pushBack(float value)
{   // TODO
    if(m_size==m_capacity){
        float *newarr=new float[m_capacity*2];
        for(int xi=0;xi<m_capacity;xi+=1){
            newarr[xi]=m_pArr[(m_indexfront+xi)%m_capacity];
        }
        m_indexfront=0;
        m_capacity=m_capacity*2;
        float *oldarr=m_pArr;
        m_pArr=newarr;
        delete [] oldarr;
    }
    m_pArr[(m_indexfront+m_size)%m_capacity]=value;
    m_size+=1;
}

void ADeque::pushFront(float value)
{   // TODO
    if(m_size==m_capacity){
        float *newArr=new float[m_capacity*2];
        for(int xi=0;xi<m_capacity;xi+=1){
            newArr[xi]=m_pArr[(m_indexfront+xi)%m_capacity];
        }
        float *oldArr=m_pArr;
        m_pArr=newArr;
        delete[] oldArr;
        m_indexfront=0;
        m_capacity=m_capacity*2;
    }    
    m_indexfront=((m_indexfront+m_capacity-1)%m_capacity);
    m_pArr[m_indexfront]=value;
    m_size+=1;
}

void ADeque::popBack()
{    // TODO

    m_size-=1;
}

void ADeque::popFront()
{    // TODO
    m_indexfront=(m_indexfront+1)%m_capacity;
    m_size-=1;
}

float &ADeque::back()
{ // TODO
    assert(m_size>0);
    return m_pArr[(m_indexfront+(m_size-1))%m_capacity]; // felaktig kodrad, tag bort
}

float &ADeque::front()
{   // TODO
    assert(m_size>0);
    return m_pArr[m_indexfront]; // felaktig kodrad, tag bort
}

int ADeque::size() const
{   // TODO
    return m_size;
}

