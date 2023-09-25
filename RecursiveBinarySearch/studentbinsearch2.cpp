#include "studentbinsearch2.h"

#include <cassert>
#include <iostream>

using namespace std;


const char* nameOfStudent2(){
    return "Nour alnajar";
}


// Returnerar pekare till det första tal som är >= x, eller
// pEnd om inget sådant tal finns.
const float* pointerToFirstElementGreaterOrEqualToX(float x, const float* pBegin, const float* pEnd){

    // TODO denna implementering är felaktig

    /*if(*pBegin>=x)
        return pBegin;

    if(x>*(pEnd-1))
        return pEnd;

    return pointerToFirstElementGreaterOrEqualToX(x,pBegin+1,pEnd);*/

    if(*(pEnd-1)<x)
        return pEnd;
    else if(*pBegin>=x)
        return pBegin;
    const float *pMid=pBegin+((pEnd-pBegin)/2);
    if((*pMid>=x)&&(*(pMid-1)<x))
        return pMid;
    if (*pMid>=x&&*(pMid-1)>=x)
        return pointerToFirstElementGreaterOrEqualToX(x,pBegin,pMid);
    return pointerToFirstElementGreaterOrEqualToX(x,pMid,pEnd);
// 11222222
}






void studentsTest2(){

   cout << "Har borde studentens testresultat synas\n\n";
    float arr[6]{0,1,2,3,4,5};
   assert(pointerToFirstElementGreaterOrEqualToX(0.1,&arr[0],&arr[6])==&arr[1]);
   // TODO din egen testkod som anropar contains här
}
