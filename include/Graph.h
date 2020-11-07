#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    Graph(const Graph &copyGraph); //copy constructor

     void infectNode(int nodeInd); //Change nodeStatus to I
    void spreadVirus(int nodeInd); //Change nodeStatus to C
    void isolateNode(int nodeInd);
    const bool isInfected(int nodeInd) const;
    const bool hasVirus(int nodeInd) const;
    const std::vector<std::vector<int>>& getEdges() const;
    const std::vector<char>& getNodeStatusList() const;
private:
    std::vector<std::vector<int>> edges;
    std::vector<char> nodeStatusList;  // H=Healthy, I= infected (operating virus), C=carrier (not yet infected)
};

#endif
