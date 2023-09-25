#include "ragnarstest.h"
#include "studentArrayrekursioner.h"
#include "stuff.h"
#include <assert.h>
#include <string>
#include <iostream>

using namespace std;
using namespace ragstuff;


void assertApproximation(float value, float approximation){
    float diff = value - approximation;
    float epsilon = 0.01f;
    assert( -epsilon <= diff && diff <= epsilon );
}

void testaSum(){
    slout << "test: sum" << endl;
    const int size = 4;
    float arr[size]{ 3,1,1,5.5 };
    assertApproximation( sum( &arr[0], &arr[size]), 3+1+1+5.5 );
    slout  << "     ok" << endl;

}

void testaFillValue(){
    slout << "test: fillValue" << endl;

    const int size = 10;
    float arr[size]{0};
    fillValue(1, &arr[1], &arr[size-1]);
    assert( arr[0] == 0);
    assert( arr[1] == 1);
    assert( arr[size-2] == 1);
    assert( arr[size-1] == 0);
    slout  << "     ok" << endl;
}

void testaHasValueInRange(){
    slout << "test: hasValueInRange" << endl;

    const int size = 4;
    float arr[size]{ 3,1,1,5.5 };
    const float epsilon = 0.001;
    assert( hasValueInRange(3-epsilon, 3+epsilon,  &arr[0], &arr[size]) );
    assert( hasValueInRange(5.5-epsilon, 5.5+epsilon,  &arr[0], &arr[size]) );
    slout  << "     ok" << endl;
}


void testaNumberOfValuesInRange(){
    slout << "test: hasValueInRange" << endl;

    const int size = 4;
    float arr[size]{ 5.5, 5.5, 1, 5.5 };
    const float epsilon = 0.001;
    assert( numberOfValuesInRange(5.5-epsilon, 5.5+epsilon,  &arr[0], &arr[size]) == 3 );
    assert( numberOfValuesInRange(1-epsilon, 1+epsilon,  &arr[0], &arr[size]) == 1 );
    assert( numberOfValuesInRange(4-epsilon, 4+epsilon,  &arr[0], &arr[size]) == 0 );
    slout  << "     ok" << endl;
}


void ragnarsTest(){

    slout << R"(
    ragnarsTest1 för arrayrekursioner.
    Efter testen skriver jag ut att den har lyckats,
    om du inte ser den utskriften har den misslyckats!

    )";

    cout << endl;
    verifyStudentsName( nameOfStudent() );


    testaSum();
    testaFillValue();
    testaHasValueInRange();
    testaNumberOfValuesInRange();

    slout << R"(
    Grattis, ragnarsTest1 för arrayrekursioner har lyckats!
    )";

}


