#include <iostream>
#include "../include/Graph.h"

using namespace std;

//base constructor
Graph::Graph(std::vector<std::vector<int>> matrix) : edges(matrix), nodeStatusList(std::vector<char>(matrix.size())) {
    for (int i = 0; i <= nodeStatusList.size() - 1; i++) {
        nodeStatusList[i] = 'H';
    }
}

//Copy constructor  //TODO: decide whether should copy node's status as well
Graph::Graph(const Graph &copyGraph) : edges(copyGraph.getEdges()),
                                       nodeStatusList(std::vector<char>(copyGraph.getEdges().size())) {
    for (int i = 0; i <= nodeStatusList.size() - 1; i++) {
        nodeStatusList[i] = 'H';
    }
}

const bool Graph::isInfected(int nodeInd) const {
    return nodeStatusList[nodeInd]=='I';
}

const std::vector<std::vector<int>> &Graph::getEdges() const {
    return edges;
}

const std::vector<char> &Graph::getNodeStatusList() const {
    return nodeStatusList;
}

void Graph::infectNode(int nodeInd) {
    nodeStatusList[nodeInd] = 'I';
}
void Graph::spreadVirus(int nodeInd) {
    nodeStatusList[nodeInd] = 'V';
}
