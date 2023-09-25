#include "student2shortestpath.h"
#include<iostream>
#include <queue>
#include <assert.h>
#include <QDebug>

using namespace std;



const char* nameOfStudent2(){
    return "Nour alnajar";
}


vector<Ixnode> shortestPathBetweenNodes(const std::vector<Node>& graph,
                                        Ixnode ixStart, Ixnode ixStop, IVisualFeedback* pFeedback){

    // Jag låter diverse deklarationer ligga kvar, men du kan ta bort dem om du vill!
    // Deklarationerna skapar den tabell (infoAboutNode)
    // och den kö (inputsToBeExaminedsom) jag använde på föreläsningen.

    struct Nodeinfo{
        Ixnode m_ixPrevious;
        bool   m_hasKnownDistance;
        Nodeinfo(Ixnode ixPrevious=-1, bool hasKnownDistance = false)
            : m_ixPrevious(ixPrevious),m_hasKnownDistance(hasKnownDistance) {}
    };

    struct Input{
        Ixnode m_ixFrom;
        Ixnode m_ixTo;
        float  m_accumulatedCost;

        Input(Ixnode ixFrom=-1,Ixnode ixTo=-1,  float accumulatedCost=2e20) : m_ixFrom(ixFrom), m_ixTo(ixTo),  m_accumulatedCost(accumulatedCost) {}

        bool operator()(const Input& a, const Input& b ) const {
                return a.m_accumulatedCost > b.m_accumulatedCost;
        }
    };

    qDebug() << "isStart = " << ixStart << ", ixStop " << ixStop;

    vector<Nodeinfo>  infoAboutNode(graph.size(), Nodeinfo());

    priority_queue<Input, vector<Input>, Input> inputsToBeExamined;


    inputsToBeExamined.push( Input(-1, ixStart, 0.0) );


    while (!inputsToBeExamined.empty()){

        // TODO

        Input input=inputsToBeExamined.top();
        inputsToBeExamined.pop();

        if(infoAboutNode[input.m_ixTo].m_hasKnownDistance)
            continue;

        infoAboutNode[input.m_ixTo]=(Nodeinfo(input.m_ixFrom,true));
        pFeedback->knownDistanceToNode(input.m_ixTo,input.m_accumulatedCost);
        if(input.m_ixTo==ixStop)
            break;
        for(unsigned long long x=0;x<graph[input.m_ixTo]._outputs.size();x+=1 ){
            //if( infoAboutNode[graph[input.m_ixTo]._outputs[x].m_ixDestination].m_hasKnownDistance)
                //continue;
            Input ny;
            ny.m_ixFrom=input.m_ixTo;
            ny.m_ixTo=graph[input.m_ixTo]._outputs[x].m_ixDestination;
            ny.m_accumulatedCost=input.m_accumulatedCost+graph[input.m_ixTo]._outputs[x].m_cost;
            inputsToBeExamined.push(ny);
        }
    }





    vector<Ixnode> backtrack;
    while (ixStop!=ixStart){
        backtrack.push_back(ixStop);
        ixStop=infoAboutNode[ixStop].m_ixPrevious;
    }
    backtrack.push_back(ixStart);

    return backtrack;
}


vector<Ixnode> shortestPathBetweenNodes2(const std::vector<Node>& graph,
                                        Ixnode ixStart, Ixnode ixStop, IVisualFeedback* pFeedback){


    // Denna funktion är inget uppdrag.
    // (Den kommer att anropas om A* är aktiverad)

}
