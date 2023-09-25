#include <iostream>
#include <random>
#include "stuff.h"
#include <assert.h>
#include "studentIdentiskaAnrop.h"

using namespace ragstuff; // dalgoRandom  och slout
using namespace std;



float minimum(const float *pBegin, const float *pEnd){
    // Min kod skall ändras i uppdraget!

    assert( pEnd-pBegin > 0 );
    if (pEnd - pBegin == 1)
        return *pBegin;
   // const float minstAvResten = minimum(pBegin+1, pEnd);
    if (*pBegin <  minimum(pBegin+1, pEnd) )
        return *pBegin;
    else return  minimum(pBegin+1, pEnd);
}

float minimumtest(const float *pBegin, const float *pEnd){
    // Min kod skall ändras i uppdraget!

    assert( pEnd-pBegin > 0 );
    if (pEnd - pBegin == 1)
        return *pBegin;
    const float minstAvResten = minimum(pBegin+1, pEnd);
    if (*pBegin <  minstAvResten )
        return *pBegin;
    else return  minstAvResten;
}

void studentsTest(){
    // om du vill kan du skriva testkod här
}



void timingExperiment(){
    slout << "timingExperiment." << endl
          << "funktionen \"minimum\" kommer att anropas efter att du tryckt på return."<< endl
          << "(Kor programmet i terminalfonstret sa att du kan trycka pa return!)" << endl << endl;


    const int size = 40;
    float arr[size];
    for (int i=0; i<size; ++i)
        arr[i] = dalgoRandom();

    slout << "Tryck return nu:";
    cin.ignore(INT_MAX, '\n');
    cout << "(beraknar minimum)" << endl;

    float m = minimumtest(arr, arr+size);

    cout << "Färdig, och minsta talet var " << m << endl;
}



