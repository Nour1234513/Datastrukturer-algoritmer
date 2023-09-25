#include "student3_listque.h"
#include "assert.h"


const char* nameOfStudentLQue(){
    return "Nour alnajar";
}



LQue::LQue()
{
// TODO
    m_pFront=nullptr;
    m_pBack=nullptr;
    m_size=0;

}

LQue::~LQue()
{
    while(m_size>0){
        (*this).popFront();
    }
}

void LQue::pushBack(float value)
{
    Link *newlink=new Link;
    (*newlink).m_value=value;
    (*newlink).m_pNext=nullptr;
    if((*this).m_pBack==nullptr){
        m_pBack=newlink;
        m_pFront=newlink;
    }
    else {
        (*this).m_pBack->m_pNext=newlink;
        m_pBack=newlink;
    }
    m_size+=1;
}

float &LQue::back()
{
  return (*m_pBack).m_value; // felaktig rad tag bort!

}

void LQue::popFront()
{
  assert( m_size>0 );

  Link *oldlink=(*this).m_pFront;
  m_pFront=m_pFront->m_pNext;
  delete oldlink;
  m_size-=1;
  if(m_size==0)
        m_pBack=nullptr;
}

float &LQue::front()
{
    assert( m_size> 0);
    return (*m_pFront).m_value; //felaktig rad tag bort!
}

int LQue::size() const
{
    return m_size; // felaktig rad tag bort!
}
