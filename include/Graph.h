#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    Graph(const Graph &copyGraph); //copy constructor //TODO make sure required, added for input

    void infectNode(int nodeInd);
    const bool isInfected(int nodeInd);
    const std::vector<std::vector<int>>& getEdges() const; //TODO make sure required, added for input
    const std::vector<bool>& getIsInfectedList() const;
private:
    std::vector<std::vector<int>> edges;
    std::vector<bool> isInfectedList;
};

#endif
