#include <iostream>
#include "../include/Graph.h"

using namespace std;

//base constructor
Graph::Graph(std::vector<std::vector<int>> matrix): edges(matrix),isInfectedList(std::vector<bool>(matrix.size())){
    for(int i=0;i<=isInfectedList.size()-1;i++) {
        isInfectedList[i] = false;
    }
}
//Copy constructor
Graph::Graph(const Graph &copyGraph): edges(copyGraph.getEdges()), isInfectedList(std::vector<bool>(copyGraph.getEdges().size())) {
    for(int i=0;i<=isInfectedList.size()-1;i++) {
        isInfectedList[i] = false;
    }
}
const bool Graph::isInfected(int nodeInd) {return isInfectedList[nodeInd];}
const std::vector<std::vector<int>> & Graph::getEdges() const {
    return edges;
}