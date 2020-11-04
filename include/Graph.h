#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    Graph(const Graph &copyGraph); //copy constructor //TODO make sure required, added for input
    Graph(); //empty constructor //TODO make sure required, added for input

    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    std::vector<std::vector<int>>& getEdges(); //TODO make sure required, added for input
private:
    std::vector<std::vector<int>> edges;
};

#endif
