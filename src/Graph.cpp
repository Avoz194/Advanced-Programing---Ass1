#include <iostream>
#include "../include/Graph.h"

using namespace std;

Graph::Graph() {
    edges=std::vector<std::vector<int>>();
}
Graph::Graph(std::vector<std::vector<int>> matrix) {
    edges = matrix; //Todo: make sure vector copy constructor works here
}

Graph::Graph(const Graph &copyGraph) {
    this->edges= copyGraph.edges;
}
