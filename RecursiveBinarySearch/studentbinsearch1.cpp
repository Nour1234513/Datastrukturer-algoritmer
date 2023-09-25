#include "studentbinsearch1.h"

#include "ragnarstest.h"
#include <cassert>

#include <iostream>
using namespace std;


const char* nameOfStudent1(){
    return "Nour alnajar";
}


/****************************************************************
ANROP:    bool exist = containedInSortedarray(x, pBegin, pEnd);
VERSION:  ...
UPPGIFT:  Returnerar true omm *p==x för något p i
          intervallet [pBegin, pEnd), dvs pBegin <= p < pEnd
          (observera att pEnd skall peka på första elementet efter arrayen)
OBS:      Alla tal mellan pBegin och pEnd måste vara sorterade i
          stigande ordning
*****************************************************************/
bool containedInSortedarray(int x, const int* pBegin, const int* pEnd)
{
  // TODO
    if(pEnd-pBegin==0)
        return false;
    if ((pEnd-pBegin)==1){
            if(x==*pBegin)
                return true;
            else return false;
    }
    const int* pMid=(pBegin+((pEnd-pBegin) /2));
    if (x<*pMid)
        return containedInSortedarray(x,pBegin,pMid);
    return containedInSortedarray(x,pMid,pEnd);



    /*int size=pEnd-pBegin;
    if (size==0)
        return false;
    if(size==1&&x==*pBegin)
        return true;
    if(size>1){
       int mid=size/2;
        if(x<*(pBegin+mid))
            return containedInSortedarray(x,pBegin,(pBegin+mid));
        else
            return containedInSortedarray(x,pBegin+mid,pEnd);
}
    return false;*/
}// contains




void studentsTest1(){

    cout << "Har borde studentens testresultat synas" << endl << endl;
    int arr[]{0,1,2,3,4,5};
    assert(containedInSortedarray(5,&arr[0],&arr[6])==true);
    assert(containedInSortedarray(-1,&arr[0],&arr[6])==false);
    assert(containedInSortedarray(2,&arr[0],&arr[6])==true);
   // TODO din egen testkod som anropar contains här
}
