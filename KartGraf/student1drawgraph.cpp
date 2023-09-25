#include "student1drawgraph.h"


const char* nameOfStudent1(){
    return  "Nour alnajar";
}


void studentsDrawGraph(QPainter& painter,  const std::vector<Node>& graph){
    //TODO
    for(std::vector<Node>::const_iterator pBegin=graph.begin();pBegin!=graph.end();pBegin+=1){
        const Node& node=*pBegin;

        painter.fillRect(node._point.x(), node._point.y(),1,1, Qt::black);

        for(unsigned long long x=0;x<node._outputs.size();x+=1){
            //const Ixnode node2=node._outputs[x].m_ixDestination;
            if(node._outputs[x].m_isVisible)
                painter.drawLine(node._point,graph[node._outputs[x].m_ixDestination]._point);
        }
    }
}


