#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "../include/Session.h"
#include "../include/Agent.h"

using json = nlohmann::json;
using namespace std;

Session::Session(const std::string &path) : g(std::vector<std::vector<int>>()),treeType() { //TODO: make sure if needed treeType in this line

    //read JSON file
    ifstream inP("config1.json"); //TODO: change config1.json to path eventually
    json inputFile;
    inputFile << inP;
    //build initial graph
    setGraph(Graph(inputFile["graph"])); //TODO: make sure how to handle reference here
    //build initial agent list
    for (auto& elem: inputFile["agents"]) {
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
    infectedQueue.push(nodeInd);
}

void Session::setGraph(const Graph &graph) {
    g=(graph);
}
void Session::addAgent(const Agent &agent) {
       agents.push_back(&agent);     //TODO:Need to activate clone;
}
void Session::simulate() {
    bool isFinished(false);
    int* cycle = new int(0);
    while(!isFinished) {
        for (Agent *ag:agents) {
            ag->act();
        }
        if(isEndOfSess()) isFinished=(true);
        ( *cycle)++;
    }
    delete  cycle;
    createOutput();
}

void Session::createOutput() {
    json output;
    output["infected_Nodes"] = g.; //TODO: need to handle dequeue for full queue or use the g.isInfectedList
    output["graph"] = g.getEdges();
    ofstream outFile("../Output.json");
    outFile<<output;
}





