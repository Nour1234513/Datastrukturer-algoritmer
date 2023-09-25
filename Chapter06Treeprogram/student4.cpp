
#include "node.h"
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <QDebug>
#include <iostream>
#include "students.h"


const char* nameOfStudent4(){
    return "Nour alnajar";
}

/**************************************************************************
 * Fler uppgifter.
 **************************************************************************/

bool hasPathToTarget(Node *pTree){
  // Funktionen anropas när man kontextklickar på en nod och
  // väljer detta menyalternativ.

    pTree->flash();
    if(pTree==nullptr)
        return false;

    if(pTree->isTarget()){
        pTree->makeRed();
        return true;
    }
    if((hasPathToTarget(pTree->m_pLeft)||hasPathToTarget(pTree->m_pRight))){
        pTree->makeRed();
        return true;
    }
    return false;

}


bool didFind500(Node *pTree){
    // Detta är ingen uppgift!
  return true;
}

void testfunktion4(Node *pTree){
    qDebug() << "testfunktion4";

    // frivilligt att skriva kod här

}





