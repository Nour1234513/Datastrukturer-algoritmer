#include "student3swaps.h"
#include "dalgorandom.h"
#include "ragnarstest3.h"

#include <cassert>
#include <iostream>
using namespace std;

const char* nameOfTheStudent3(){
    return "Nour alnajar";  // Byt ut denna sträng mot ditt eget namn!
}


// ################ Implementera swap med pekar- och referensanrop #################



// ANROP:   swap(a,b); eller swap( (&a), (&b) );
// UPPGIFT: Byter värden mellan a och b.
void swap(float* pA, float* pB){
    // TODO
    float swap=*pA;
    *pA=*pB;
    *pB=swap;
}

// ANROP:   swap(a,b); eller swap((a), (b));
// UPPGIFT: Byter värden mellan a och b.
void swap(float &a, float &b){
    // TODO
    float swap=a;
    a=b;
    b=swap;
}

// För att öva på referenser ger jag här en
// lite annorluna implementerting av max.
float& max(float &a, float &b){
    if (a>b)
        return a;
    return b;
}



void testaMax(){
    float a = 42;
    float b = 108;

    cout << "maximum is " << max(a,b) << endl;

    max(a,b) = 1;

    cout << "a=" << a << " , b=" << b << endl;

    /* OBS! Förklara vad ovanstående max(a,b) = 1 gör, och varför!
     * max(a,b) returnerar adressen till stöstra tal mellan a och b.
     *  tar reda på vilken av a och b är större och ger den ny värde som är 1.
     *
     */

}


void studentsTest3(){
  // TODO! Skriv din testkod här
  // Testa båda dina swap versioner
    float a=5;
    float b=10;
    float *pa =&a;
    float *pb=&b;
    swap(&a,&b);
    assert(a==10&&b==5);
    swap(*pa,*pb);
    assert(*pa==5&&*pb==10);

}



void mainFunctionInStudent3(){

    cout << "\n\n\n################ testingCode3 #################\n\n";

    studentsTest3();
    testaMax();

    ragnarsTest3();
}
