
#include "studentArrayrekursioner.h"
#include <cassert>
#include <iostream>
#include <random>

using namespace std;


std::string nameOfStudent(){
    return "Nour Alnajar";  // TODO andra till ditt namn!
}



float sum(const float *pBegin, const float *pEnd){
    // TODO
    // Skriv en rekursiv algoritm som returnerar summan!

    int size=pEnd-pBegin;
    if(size==0)
        return 0;
    return *pBegin+sum(pBegin+1,pEnd);
}


void fillValue(float value,  float *pBegin,  float *pEnd){
   // TODO
    int size=pEnd-pBegin;
    if(size>0){
        *pBegin= value;
        fillValue(value,pBegin+1,pEnd);
    }
}

bool hasValueInRange(float min, float max, const float *pBegin, const float *pEnd){
    // TODO
    int size=pEnd-pBegin;
    if(size==0)
        return false;
    if(*pBegin>=min&&*pBegin<max)
        return true;
    return hasValueInRange(min,max,pBegin+1,pEnd);


}

int numberOfValuesInRange(float min, float max, const float *pBegin, const float *pEnd){
   // TODO
    int antal=0;
    int size=pEnd-pBegin;
    if(size==0)
        return 0;
    if(*pBegin<max&&*pBegin>min)
        antal+=1; //numberOfValuesInRange(min,max,pBegin+1,pEnd);
    return antal+numberOfValuesInRange(min,max,pBegin+1,pEnd);
}


void studentTest(){
    float arr[]{0,1,2,3,4};
assert(!hasValueInRange(5,6,&arr[0],&arr[5]));
assert(numberOfValuesInRange(10,12,&arr[0],&arr[5])==0);
assert(sum(&arr[0],&arr[5])==10);

}


// ------------


