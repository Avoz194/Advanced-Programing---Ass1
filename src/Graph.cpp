#include <iostream>
#include "../include/Graph.h"
#include "../include/Tree.h"

using namespace std;

//base constructor
Graph::Graph(std::vector<std::vector<int>> matrix) : edges(matrix), nodeStatusList(std::vector<char>(matrix.size())) {
    for (int i = 0; i <= nodeStatusList.size() - 1; i++) {
        nodeStatusList[i] = 'H';
    }
}
/*

Graph::Graph(const Graph &copyGraph) : edges(copyGraph.getEdges()),
                                       nodeStatusList(std::vector<char>(copyGraph.getEdges().size())) {
}
*/
const bool Graph::isInfected(int nodeInd) const {
    return nodeStatusList[nodeInd] == 'I';
}

const bool Graph::hasVirus(int nodeInd) const {
    return nodeStatusList[nodeInd] == 'C' | nodeStatusList[nodeInd] == 'I';
}

const std::vector<std::vector<int>> &Graph::getEdges() const {
    return edges;
}

const std::vector<char> &Graph::getNodeStatusList() const {
    return nodeStatusList;
}

void Graph::isolateNode(int nodeInd) {
    for (int (i) = 0; (i) < edges.size(); ++(i)) {
        edges[nodeInd][i] = 0;
        edges[i][nodeInd] = 0;
    }
}

void Graph::infectNode(int nodeInd) {
    nodeStatusList[nodeInd] = 'I';
}

void Graph::spreadVirus(int nodeInd) {
    nodeStatusList[nodeInd] = 'C';
}

Tree *Graph::BFS(int nodeInd, Session &sess) const {
    Tree *bfsTree = Tree::createTree(sess,
                                     nodeInd); //TODO:Review: changed bfsTree to be pointer - Make sure how deletes it later
    int numOfNodes = edges.size();
    std::vector<bool> visited(numOfNodes, false);
    std::vector<int> q;
    q.push_back(nodeInd);

    visited[nodeInd] = true;

    int vis;
    while (!q.empty()) {
        vis = q[0];

        q.erase(q.begin()); // delete the first element in the q

        for (int i = 0; i < numOfNodes; i++) {
            if (edges[vis][i] == 1 && (!visited[i])) {
                bfsTree->addChild(
                        *Tree::createTree(sess, i)); //TODO:Change to vis->    + Review: changed to *Tree in brackets
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
    return bfsTree;
}
