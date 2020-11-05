#include <iostream>
#include "../include/Graph.h"

using namespace std;

Graph::Graph(): edges(std::vector<std::vector<int>>()) {
}
Graph::Graph(std::vector<std::vector<int>> matrix): edges(matrix){
}

Graph::Graph(const Graph &copyGraph): edges(copyGraph.getEdges()) {
}
