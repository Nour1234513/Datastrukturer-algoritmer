


#include "node.h"
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <QDebug>
#include "students.h"

using namespace std;


const char* nameOfStudent3(){
    return "Nour alnajar";
}

/**************************************************************************
 * Serialisering.
 *
 * Läsa och skriva träd från fil.
 * Dessa algoritmer skall fungera för alla typer av träd, inte bara sökträd.
 * Om man sparar ett träd och därefter läser filen skall det återskapade
 * trädet ha exakt samma struktur som det sparade trädet.
 **************************************************************************/


/**************************************************************************
 * Serialisering.
 *
 * Läsa och skriva träd från fil.
 * Dessa algoritmer skall fungera för alla typer av träd, inte bara sökträd.
 * Om man sparar ett träd och därefter läser filen skall det återskapade
 * trädet ha exakt samma struktur som det sparade trädet.
 **************************************************************************/

void saveTreeToStream(ofstream& utfil, Node *pTree){
  // TOD

    if(pTree==nullptr){
        utfil<<"x";
        return;
    }


    utfil<<"v"<<(*pTree).m_key;
    saveTreeToStream(utfil,(*pTree).m_pLeft);
    saveTreeToStream(utfil,(*pTree).m_pRight);
}

Node *readTreeFromStream(ifstream& infil){
    //TODO ändra

    int nummer=0;
    char index;

    if(!infil.fail()){
       infil >>index;

    if(index=='x')
       return nullptr;

    if(index=='v'){
        infil>>nummer;
        Node *tree=new Node(nummer,nullptr,nullptr);
        tree->m_pLeft=readTreeFromStream(infil);
        tree->m_pRight=readTreeFromStream(infil);
        return tree;
        }
    }
    return nullptr;
}



void testfunktion3(Node *pTree){
    qDebug() << "testfunktion3";
    // frivilligt att skriva kod här
}
