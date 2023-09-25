#include "student2_arrstack.h"
#include <assert.h>

const char* nameOfStudentAStack(){
    return "Nour alnajar";
}



AStack::AStack()
{
    // TODO


    m_size=0;
    m_capacity=10;
    m_pArr=new float[m_capacity];
}


AStack::~AStack()
{
    // TODO
    delete [] m_pArr;
}

void AStack::pushBack(float value)
{
    // TODO
    m_pArr [m_size]=value;
    m_size+=1;
    if(m_size==m_capacity){
        float *newarr=new float[m_capacity*2];
        for(int xi=0;xi<m_capacity;xi+=1){
            newarr[xi]=m_pArr[xi];
        }
        m_capacity=m_capacity*2;
        float *oldarr=m_pArr;
        m_pArr=newarr;
        delete [] oldarr;
    }

}


float &AStack::back()
{
    // TODO
    return m_pArr[m_size-1]; // felaktig kodrad, tag bort

}

void AStack::popBack()
{
    // TODO
    m_size-=1;

}

int AStack::size() const
{
    // TODO
    return m_size; // felaktig kodrad
}




void studentTest2(){

}

/******** kommentar som efterfrågades i "öka istället linjärt"

  blev det någon skillnad när du ökade arraystorleken med 10 istället för med dubbleing?
    det klart !!


 ***********************************************************************/
