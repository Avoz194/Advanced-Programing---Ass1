#include "../include/Graph.h"
#include <deque>

using namespace std;

//base constructor
Graph::Graph(std::vector<std::vector<int>> matrix) : edges(matrix), nodeStatusList(std::vector<char>(edges.size())) {
    int size = nodeStatusList.size();
    for (int i = 0; i < size; i++) {
        nodeStatusList[i] = 'H';
    }
}

const bool Graph::isInfected(int nodeInd) const {
    return nodeStatusList[nodeInd] == 'I';
}

const bool Graph::hasVirus(int nodeInd) const {
    return (nodeStatusList[nodeInd] == 'C') | (nodeStatusList[nodeInd] == 'I');
}

const std::vector<std::vector<int>> &Graph::getEdges() const {
    return edges;
}

const std::vector<char> &Graph::getNodeStatusList() const {
    return nodeStatusList;
}

void Graph::isolateNode(int nodeInd) {
    int size = edges.size();
    for (int (i) = 0; (i) < size; ++(i)) {
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
                                     nodeInd);
    int numOfNodes = edges.size();
    std::vector<bool> visited(numOfNodes, false);
    std::deque<Tree *> q;
    q.push_back(bfsTree);
    visited[nodeInd] = true;

    while (!q.empty()) {
        Tree *tempTree = q[0];
        q.pop_front();

        for (int i = 0; i < numOfNodes; i++) {
            if (edges[tempTree->getLabel()][i] == 1 && (!visited[i])) {
                Tree *toPush(Tree::createTree(sess, i));
                tempTree->addChild(toPush);
                q.push_back(toPush);
                visited[i] = true;
            }
        }
    }

    return bfsTree;
}
