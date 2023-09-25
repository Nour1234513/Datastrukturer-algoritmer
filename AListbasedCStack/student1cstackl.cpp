#include "student1cstackl.h"
#include <cassert>
#include <iostream>

using namespace std;

const char* nameOfStudent1(){
    return "Nour alnajar";
}

CStackL  CStackLConstruct(){
   // Jag lämnar kvar denna implementering
    CStackL theStack;
    theStack.m_pTop = nullptr;
    theStack.m_size = 0;
    return theStack;
}




CStackL  CStackLConstruct(const CStackL &other){
    CStackL NewStack;
    NewStack.m_pTop=nullptr;
    NewStack.m_size=other.m_size;
    Link *pPreviousLink = nullptr;
    for(const Link *pOthLnk=other.m_pTop;pOthLnk!=nullptr;pOthLnk=(*pOthLnk).m_pNext){
        Link *pCopy=new Link;
        (*pCopy).m_data=(*pOthLnk).m_data;
        (*pCopy).m_pNext=(*pOthLnk).m_pNext;
       if (pPreviousLink==nullptr)
            NewStack.m_pTop = pCopy;
       else (*pPreviousLink).m_pNext = pCopy;
        pPreviousLink = pCopy;

    }

// TODO
    /*static CStackL NewStack;
    NewStack.m_pTop=nullptr;
    NewStack.m_size=other.m_size;
    const Link *Orginal=other.m_pTop;
    const CStackL *andra=other.m_pTop;

    Link *pCopy=new Link;

    (*pCopy).m_pNext=Orginal->m_pNext;
    (*pCopy).m_data=Orginal->m_data;
    if(NewStack.m_pTop==nullptr)
        NewStack.m_pTop=pCopy;
    if(Orginal->m_pNext!=nullptr)
        CStackLConstruct();*/




    return NewStack; // (fel,ändra)

}



void   CStackLDestruct(CStackL *pDettaObjekt){
// TODO
    for(;(*pDettaObjekt).m_pTop!=nullptr;)
        CStackLPop(pDettaObjekt);
}

void   CStackLPush(CStackL *pDettaObjekt, float data){
// TODO
    Link *newTop= new Link;
    (*newTop).m_data=data;
    (*newTop).m_pNext=(*pDettaObjekt).m_pTop;
    (*pDettaObjekt).m_pTop=newTop;
    (*pDettaObjekt).m_size+=1;
}


float  CStackLTop(CStackL *pDettaObjekt){
// TODO
    assert((*pDettaObjekt).m_size>0);
    float data=(*(*pDettaObjekt).m_pTop).m_data;
    return data; // (fel, ändra)
}


void CStackLPop(CStackL *pDettaObjekt){
// TODOm
    assert((*pDettaObjekt).m_size>0);

    Link *postion=(*pDettaObjekt).m_pTop;
    pDettaObjekt->m_pTop=pDettaObjekt->m_pTop->m_pNext;
    delete postion;
    (*pDettaObjekt).m_size-=1;
}

int  CStackLSize(CStackL *pDettaObjekt){
// TODO
    return (*pDettaObjekt).m_size; // (fel, ändra)
}

// ----- Din testkod

void studentTest1(){

     cout << endl << endl << "studentTest1..." << endl ;
    // Skriv din egen testkod här
}

