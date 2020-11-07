#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "../include/Session.h"
#include "../include/Agent.h"

using json = nlohmann::json;
using namespace std;

Session::Session(const std::string &path) : g(vector<vector<int>>()) { //TODO: make sure if needed treeType in this line

    //read JSON file
    ifstream inP(path); //TODO: make sure works in MakeFile
    json inputFile;
    inputFile << inP;
    //build initial graph
    setGraph(Graph(inputFile["graph"])); //TODO: make sure how to handle reference here
    //build initial agent list
    for (auto &elem: inputFile["agents"]) {
        if (elem[0] == "V") {
            agents.push_back(new Virus(elem[1], *this));
        }
        if (elem[0] == "C") {
            agents.push_back(new ContactTracer(*this));
        }
    }

    // initial treeType
    if (inputFile["tree"] == "C") treeType = Cycle;
    if (inputFile["tree"] == "M") treeType = MaxRank;
    if (inputFile["tree"] == "R") treeType = Root;
}

TreeType Session::getTreeType() const {
    return this->treeType;
}

void Session::enqueueInfected(int nodeInd) {
    infectedQueue.push(nodeInd);
}

void Session::setGraph(const Graph &graph) {
    g = (graph);
}

void Session::addAgent(const Agent &agent) {
    agents.push_back(agent.clone());     //TODO:Need to activate clone;
}

void Session::simulate() {
    bool isFinished(false);
    int *cycle = new int(0);
    while (!isFinished) {
        for (Agent *ag:agents) {
            ag->act();
        }
        if (isEndOfSess()) isFinished = (true);
        (*cycle)++;
    }
    delete cycle;
    createOutput();
}

const bool Session::isEndOfSess() const {
    bool isSatisfied(true);
    vector<Agent *>::const_iterator iter;
    iter = agents.begin();
    const Graph &g1 = getGraph();
    while (isSatisfied && iter != agents.end()) { //Iterate through the agents list
        if (*iter.type = Virus) {//TODO:figure out how to know whether virus or not
            int index = iter->getIndex();
            if (!g1->isInfected(index)) { //if agent is virus and not infeceted return false;
                isSatisfied = false;
                break;
            }
            //iterate through the edges of the graph to make sure neighbors are infected;
            const vector<int> &neighbors = g.getEdges()[index];
            for (int i = 0; i < neighbors.size(); i++) {
                if (neighbors[i] == 0 || !g1.isInfected(i)) {
                    isSatisfied = false;
                    break;
                }
            }
        }
        iter++;
    }
    return isSatisfied;

}

void Session::createOutput() {
    json output;
    const vector<bool> &infectedBool = g.getIsInfectedList();
    vector<int> infectedList;
    for (int i = 0; i < infectedBool.size(); i++) {
        if (infectedBool[i]) infectedList.push_back(i);
    }
    output["infected_Nodes"] = infectedList; //TODO: need to handle dequeue for full queue or use the g.isInfectedList
    output["graph"] = g.getEdges();
    ofstream outFile("../Output.json");
    outFile << output;
}







