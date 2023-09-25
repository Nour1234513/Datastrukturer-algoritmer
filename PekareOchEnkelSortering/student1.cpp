#include "student1.h"
#include <cassert>
#include "ragnarstest1.h"
#include "dalgorandom.h"

#include <iostream>
using namespace std;


// Läs Detta!

// Pekaruppdragen går ut på att implementera nedastående funktioner
// Många funktioner skall implementeras på två olika sätt (I och P):
// Version I: Räkna ut size och använd arraynotation med hakparanteser och heltalsindex.
// Version P: Använd istället pekarnotation, dvs  *p,  p+=1,  etc.




// ************************************************************
// ANROP:   char* namn = nameOfStudent1();
// UPPGIFT: Returnerar ditt namn!
// ************************************************************
const char* nameOfTheStudent1(){
    return "Nour Alnajar";  // Byt ut denna sträng mot ditt eget namn!
}




// ################ version I, löses med [ ]  och indexnotation #############



// ************************************************************
// ANROP:   float value = minimumI(&arr[0], &arr[size]);
// UPPGIFT: Returnerar arrayens minsta värde
// ************************************************************
float minimumI(const float *pBegin, const float *pEnd){

    // Jag låter min egen lösnin ligga kvar.
    // Förstå denna! Lös de andra uppgifterna själv.

    assert( pBegin < pEnd );

    int size = pEnd - pBegin;
    float extreme = pBegin[0];
    for (int i=0; i<size ; i+=1)
        if (pBegin[i]<extreme)
            extreme = pBegin[i];
    return extreme;
}


// ************************************************************
// ANROP:   float value = maximumI( &arr[0], &arr[size] );
// UPPGIFT: Returnerar arrayens största värde
// ************************************************************
float maximumI(const float *pBegin, const float *pEnd){

    // TODO
    assert( pBegin < pEnd );

    int size=pEnd-pBegin;
    float maxtal=pBegin[0];
    for(int x=0;x<size;x+=1){
        if(pBegin[x]>maxtal)
            maxtal=pBegin[x];
    }
    return maxtal; // felaktig kodrad
}


// ************************************************************
// ANROP:   float value = sumI( &arr[0], &arr[size] );
// UPPGIFT: Returnerar summan av alla element.
// ************************************************************
float sumI(const float *pBegin, const float *pEnd){

    // TODO
    float summa=0;
    int size=pEnd-pBegin;
    for(int x=0;x<size;x+=1){
        summa+=pBegin[x];
    }
    return summa; // felaktig kodrad
}


// ************************************************************
// ANROP:   fillRandomI( &arr[0], &arr[size] );
// UPPGIFT: Fyller arrayen med oberoende slumpdata
// ************************************************************
void fillRandomI(float *pBegin, float *pEnd){
    // TODO
    int size=pEnd-pBegin;
    for(int x=0;x<size;x+=1){
        pBegin[x]=dalgoRandom();
    }


}

// ************************************************************
// ANROP:   fillSortedRandomI( &arr[0], &arr[size] );
// UPPGIFT: Fyller arrayen med sorterat slumpdata. Minst först
// ************************************************************
void fillSortedRandomI(float *pBegin, float *pEnd){
    int size=pEnd-pBegin;
    pBegin[0]=(dalgoRandom());
    for(int x=1;x<size;x+=1){
        pBegin[x]=pBegin[x-1]+(dalgoRandom());
    }
}




// ************************************************************
// ANROP:   bool contains = hasValueInRangeI(min, max, &arr[0], &arr[size] );
// UPPGIFT: Returnerar true om arrayen ett värde i det halvt öppna intervallet min <= x < max.
// ************************************************************
bool  hasValueInRangeI(float min, float max, const float *pBegin, const float *pEnd){
    // TODO
    int size=pEnd-pBegin;
    for(int x=0;x<size;x+=1){
        if (pBegin[x]<max&&pBegin[x]>min)
            return true;
    }
    return false;
     // felaktig kodrad
}

// ************************************************************
// ANROP:   int number = numberOfValuesInRange(min, max,  &arr[0], &arr[size] );
// UPPGIFT: Returnerar antalet värden som ligger i det halvt öppna intervallet  min <= x < max.
// ************************************************************
int numberOfValuesInRangeI(float min, float max, const float *pBegin, const float *pEnd){
    int antalTaliRange=0;
    int size=pEnd-pBegin;
    for(int x=0;x<size;x+=1){
        if ((pBegin[x]<max) && (pBegin[x]>=min))
            antalTaliRange+=1;
    }
    return antalTaliRange; // felaktig kodrad
     // felaktig kodrad
}




// ################ version P, samma uppgifter löses nu med pekarnotation  ###############






float minimumP(const float *pBegin, const float *pEnd){
    // Jag låter min egen lösnin ligga kvar.
    // Förstå denna! Lös de andra uppgifterna själv.

    assert( pBegin < pEnd );
    float extreme = *pBegin;
    for (const float *p=pBegin ; p<pEnd; p+=1)
        if (*p<extreme)
            extreme = *p;
    return extreme;
}


float maximumP(const float *pBegin, const float *pEnd){
    // TODO
    assert( pBegin < pEnd );


    float maxtal=*pBegin;
    for(const float *x=pBegin;x<pEnd;x+=1){
        if(*x>maxtal)
            maxtal=*x;
    }
    return maxtal;// felaktig kodrad
}

float sumP(const float *pBegin, const float *pEnd){
    // TODO
    float summa=0;

    for(const float *x=pBegin;x<pEnd;x+=1){
        summa+=*x;
    }
    return summa; // felaktig kodrad
}

void fillRandomP(float *pBegin, float *pEnd){
    // TODO

    for(float *x=pBegin;x<pEnd;x+=1){
        *x=rand()%100+1;
    }
}



void fillSortedRandomP(float *pBegin, float *pEnd){
    // TODO
    *pBegin= rand()%10+1;
    for(float *x=pBegin+1;x<pEnd;x+=1){
        *x=(*(x-1) + (rand()%10+1));
    }

}



bool hasValueInRangeP(float min, float max, const float *pBegin, const float *pEnd){
    // TODO
    for(const float *x=pBegin;x<pEnd;x+=1){
        if (*x<max&&*x>min)
            return true;
    }
    return false; // felaktig kodrad

}


int  numberOfValuesInRangeP(float min, float max, const float *pBegin, const float *pEnd){
    // TODO
    int antalTaliRange=0;
    for(const float *x=pBegin;x<pEnd;x+=1){
        if ((*x<max) && (*x>min))
            antalTaliRange+=1;
    }
    return antalTaliRange; // felaktig kodrad
}


// ################ Skriv din egen testkod här! #################


void studentsTest1(){
    float arr[5]{0,1,2,3,4};
    assert(maximumI(&arr[0],&arr[5])==4);
    assert(minimumI(&arr[0],&arr[5])==0);
    assert(maximumP(&arr[0],&arr[5])==4);
    assert(minimumP(&arr[0],&arr[5])==0);
    assert(sumP(&arr[0],&arr[5])==10);
    assert(sumI(&arr[0],&arr[5])==10);
    assert(hasValueInRangeP(1.5,2.5,&arr[0],&arr[5]));
    assert(!hasValueInRangeP(1.5,1.9,&arr[0],&arr[5]));
    assert(numberOfValuesInRangeP(1,3,&arr[0],&arr[5])==1);
    assert(numberOfValuesInRangeP(4,5,&arr[0],&arr[5])==0);

    //fillSortedRandomP(&arr[0],&arr[5]);

    // Testa själv dina funktioner här!
    // Det är OBLIGATRORISKT att anropa varje funktion som du själv
    // implementeratrat,  så att labansvarig kan se att du förstått hur funktionerna skall
    // anropas!

    // Helst bör du också skriva kod som verifierar att dina funktioner
    // returnerar korrekta resultat för vissa exempeel på indata.
    // Istället för att skriva ut ett felmedelande på skärmen bör du se
    // till så att programmet kraschar om det innehåller ett fel!
    // Man kan göra detta genom att anropa:
    //   assert( false );
    // Men istället för att skriva:
    // if (!isOk) // om inte okay..
    //    assert( false );  // ..krascha programmet!
    // Bör man skriva:
    //   assert( isOk );
    // Ännu bättre... Istället för att skriva isOK kan man skriva ett uttryck som
    // blir true eller false, exempelvis (förutsatt att arr[0]==1 och arr[1]==2)
    //   assert( averageElementP(&arr[0],  &arr[2]) == 1.5 );



    cout << "(dina egna tester borde komma har!)\n";

    // TODO

}




void mainFunctionInStudent1(){

    cout << "\n\n\n################ testingCode1 ################# \n\n";

    studentsTest1();

    ragnarsTest1();
}


