#include "student2stackl.h"
#include <cassert>
#include <iostream>

using namespace std;

const char* nameOfStudent2(){
    return "Nour alnajar";
}

StackL::StackL(){
// TODO

    (*this).m_pTop=nullptr;
    (*this).m_size=0;

}


StackL::StackL(const StackL& theOther){
// TODO
   // StackL Newlink;
    m_size=theOther.m_size;
    m_pTop=nullptr;
    Link *ForreLink=nullptr;
    for(const Link *OtherLnk=theOther.m_pTop;OtherLnk!=nullptr;OtherLnk=OtherLnk->m_pNext){
        Link *pCopy=new Link;

        (*pCopy).m_pNext=nullptr;
        (*pCopy).m_data=(*OtherLnk).m_data;

        if(ForreLink==nullptr)
            (*this).m_pTop=pCopy;
        else (*ForreLink).m_pNext=pCopy;
        ForreLink=pCopy;

    }
}

StackL::~StackL(){
// TODO
    while((*this).m_size>0)
        (*this).pop();

}

void StackL::push(float value){
// TODO
    Link *newLink = new Link;
    (*newLink).m_pNext=(*this).m_pTop;
    (*newLink).m_data=value;
    m_pTop=newLink;
    m_size +=1;
}

void StackL::pop(){
// TODO
    if((*this).m_size>0){
    Link *postion=(*this).m_pTop;
   // (*this).m_pTop=(*(*this).m_pTop).m_pNext;
    m_pTop= m_pTop->m_pNext;
    (*this).m_size -=1;
    delete postion;
}}


float StackL::top() const {
// TODO
    assert((*this).m_size>0);
    return (*(*this).m_pTop).m_data; // (fel, ändra)

}

int StackL::size() const {
// TODO
    return (*this).m_size; // (fel, ändra)

}


void studentTest2(){

     cout << endl << endl <<  "studentTest2..." << endl;

    // Skriv din egen testkod här
}

