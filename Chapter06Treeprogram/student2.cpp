

#include "node.h"
#include <stdio.h>
#include <algorithm>
#include <deque>
#include <QDebug>
#include "students.h"


const char* nameOfStudent2(){
    return "Nour alnajar";
}

/**************************************************************************
 * Sökträd.
 *
 *
 **************************************************************************/

void insertKeyToSearchtree(Node*& pTree, int key){
   /* if(pTree==nullptr){
        pTree=new Node(key,nullptr,nullptr);
    }
    else if(pTree->m_key>key)
        insertKeyToSearchtree(pTree->m_pLeft,key);
    else if(pTree->m_key<key)
        insertKeyToSearchtree(pTree->m_pRight,key);*/
    Node *ny=pTree;
    while(ny!=nullptr){
        ny->flash();
        if(ny->m_key>key)
            ny=ny->m_pLeft;

        else if (ny->m_key<key)
            ny=ny->m_pRight;

        else if(ny->m_key==key)
           return;
    }

    if(ny==nullptr){
       Node *x=new Node(key,nullptr,nullptr);
        ny=x;
}
}

bool contains(Node *pTree, int key){

    /*if(pTree==nullptr)
        return false;
    if(pTree->m_key>key)
       return  contains(pTree->m_pLeft,key);
    if(pTree->m_key<key)
        return contains(pTree->m_pRight,key);
    return true;*/

    while (pTree!=nullptr){
        if(pTree->m_key==key)
            return true;

        if(pTree->m_key>key)
            pTree=pTree->m_pLeft;
        if(pTree->m_key<key)
            pTree=pTree->m_pRight;
    }
    return false;
}


Node* nodeWithMinimumKey(Node *pTree){

    // Enligt anvisning bör du ej göra den rekursiv
    // (så att ni inte skriver av min god på alla uppgifter)
   /* int mini=pTree->m_key;
    Node* plats;
    Node* pNy=pTree;
    while (pNy!=nullptr){
        if(pNy->m_key>mini)
            pNy=pNy->m_pLeft;
        if(pNy->m_key<mini){
            mini=pNy->m_key;
            plats=pNy;
        }
    }
    plats->flash();
    return plats; // FEL*/

    Node* plats=pTree;
    while(plats->m_pLeft!=nullptr){
        plats=plats->m_pLeft;
        plats->flash();
    }
    plats->makeRed();
    return plats;
}

void removeKeyFromSearchtree(Node* &pTree, int key){
    if(pTree==nullptr)
        return;
    else if (key<pTree->m_key)
        removeKeyFromSearchtree(pTree->m_pLeft,key);
    else if(key>pTree->m_key)
        removeKeyFromSearchtree(pTree->m_pRight,key);
    else {
    if(pTree->m_pRight==nullptr||pTree->m_pLeft==nullptr){
    Node *oldpTree=pTree;
        if(pTree->m_pRight!=nullptr)
            pTree=pTree->m_pRight;
        else
            pTree=pTree->m_pLeft;
        delete oldpTree;
    }
    else {
        pTree->m_key = nodeWithMinimumKey(pTree->m_pRight)->m_key;
        removeKeyFromSearchtree((pTree->m_pRight),pTree->m_key);
        }
    }
}

/*** redogörelse för experiment ***************************************

  Hur stort blir trädets höjd respektive genomsnittliga
   djup om man stoppar in 255 element (gör flera experiment om det går)?


  TODO...

  höjd =                17          13          14      14          13

  genomsnittligt djup = 8.933       7.905     7.98      7.749       7.258

  (gör flera experiment)

   OBS på Windowsmaskiner kan det vara svårt att utföra flera olika experiment.


  varför är det genomsnittliga djupet intressant? ...??


 ******************************************************************************/



void testfunktion2(Node *pTree){
    qDebug() << "testfunktion2";

}
