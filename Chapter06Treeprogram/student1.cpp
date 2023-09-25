#include "node.h"
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <QDebug>

#include "students.h"

const char* nameOfStudent1(){
    return "Nour alnajar";
}




/**************************************************************************
 * Trädklättring.
 *
 *
 **************************************************************************/

Node* testTree1(){

    // TODO Returnera det testträd som finns avbildat i uppdragshäftet.
    Node *pNode4 = new Node(4,nullptr,nullptr);
    Node *pNode2 = new Node(2, pNode4,nullptr);

  //  Node *pNode6 = new Node(6, nullptr,nullptr);
//    Node *pNode5 = new Node(5, nullptr,nullptr);
//    Node *pNode4 = new Node(4,nullptr,nullptr);
//    Node *pNode3 = new Node(3, pNode5,pNode6);
//    Node *pNode2 = new Node(2, pNode4,nullptr);
   // Node *pNode1 = nullptr;//new Node(1, nullptr,nullptr);

  return pNode2; // FEL
}


void flashPreOrder(Node *pTree){
    if(pTree==nullptr)
        return;
    (*pTree).flash();
    flashPreOrder((*pTree).m_pLeft);
    flashPreOrder((*pTree).m_pRight);
}

void flashInOrder(Node *pTree){
    if(pTree==nullptr)
        return;

    flashInOrder((*pTree).m_pLeft);
    (*pTree).flash();
    flashInOrder((*pTree).m_pRight);
}

void flashPostOrder(Node *pTree){
    if(pTree==nullptr)
        return;

    flashPostOrder((*pTree).m_pLeft);
    flashPostOrder((*pTree).m_pRight);
    (*pTree).flash();
}


// Nedanstående funktion skall inte vara rekursiv.
// implementera den med hjälp av en FIFO-kö.
// Så här kan du deklarera fifo-kön:
// std::deque<Node*> que;
// så här stoppar du in ett värde i kön
// que.push_back( nodepekare );
// så här läser du det värde som ligger främst
// Node *p = que.front();
// så här avlägsnar du det främsta värdet från kön
// que.pop_front();

void flashNodesAtIncreasingDepth(Node *pTree){
    std::deque <Node*> ko;
    ko.push_back(pTree);

    while(!ko.empty()){
        pTree=ko.front();
    if(pTree!=nullptr){
        (*pTree).flash();
        ko.push_back(pTree->m_pLeft);
        ko.push_back(pTree->m_pRight);

    }
    ko.pop_front();
    }
}


// Nedanstående funktioner bör vara rekursiva.
// De kan då implementeras med några få raders kod.

int numberOfNodes(Node *pTree){
    // Funktioner bör implementeras med rekursion.
    if(pTree==nullptr)
        return 0;
    return 1+numberOfNodes(pTree->m_pLeft)+numberOfNodes(pTree->m_pRight);
}

int height(Node *pTree){
    // Funktioner bör implementeras med rekursion.
    int left=0;
    int right=0;
    if(pTree==nullptr)
       return -1;
    pTree->flash();
    left=+1+height(pTree->m_pLeft);
    right=+1+height(pTree->m_pRight);
    if (left>right)
    return  left;
    else return right;// FEL

}

void testfunktion1(Node *pTree){
    // frivilligt att skriva kod här
    qDebug() << "testfunktion1";
}

