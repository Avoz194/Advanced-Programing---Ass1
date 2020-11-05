#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "../include/Session.h"
#include "../include/Agent.h"

using json = nlohmann::json;
using namespace std;

Session::Session(const std::string &path) : initialGraph(),g(),treeType() { //TODO: make sure if needed treeType in this line

    //read JSON file
    ifstream inP("path.json");
    json inputFile;
    inputFile << inP;
    //build initial graph
    initialGraph=Graph(inputFile["graph"]);
    //build initial agent list
    for (auto &elem: inputFile["agents"]) {
        if (elem[0] == "V") {
            addAgent(Virus(elem[1],*this));
        }
        if (elem[0] == "C") {
            addAgent(ContactTracer(*this));
        }
    }
    // initial treeType
    if(inputFile["tree"] =="C") treeType = Cycle;
    if(inputFile["tree"] =="M") treeType = MaxRank;
    if(inputFile["tree"] =="R") treeType = Root;
}
TreeType Session::getTreeType() const {
    return this->treeType;
}

void Session::enqueueInfected(int nodeInd) {
    infectedList.push_back(nodeInd);
}



void Session::createOutput() {
    json output;
    output["infected_Nodes"] = infectedList;
    output["graph"] = g.getEdges();
    ofstream outFile("~/sessionOutput.json");
    outFile<<output;
}





