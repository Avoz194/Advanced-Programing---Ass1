#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include "../include/Session.h"
#include "../include/Agent.h"

using json = nlohmann::json;
using namespace std;

Session::Session(const std::string &path) : g(vector<vector<int>>()), treeType(), cycle(0), agents(
        vector<Agent *>()), pendingAgents(
        vector<Agent *>()), infectedQueue(queue<int>()) {

    //read JSON file
    ifstream inP(path); //TODO: make sure works in MakeFile
    json inputFile;
    inP>>inputFile;
    //build initial graph
    setGraph(Graph(inputFile["graph"]));
    //build initial agent list
    for (auto &elem: inputFile["agents"]) {
        if (elem[0] == "C") {
            agents.push_back(new ContactTracer());
        } else if (elem[0] == "V") {
            agents.push_back(new Virus(elem[1]));
            g.spreadVirus(elem[1]);
        }

    }

    // initial treeType
    if (inputFile["tree"] == "C") treeType = Cycle;
    if (inputFile["tree"] == "M") treeType = MaxRank;
    if (inputFile["tree"] == "R") treeType = Root;
}


void Session::simulate() {
    bool isFinished(false);
    cycle = 0;
    while (!isFinished) {
        pendingAgents = vector<Agent *>();
        for (Agent *ag:agents) {
            ag->act(*this);
        }
        for (int i = 0; i <
                        pendingAgents.size(); i++) { //following the action of all current agents, add pendingAgents to the list.
            agents.push_back(pendingAgents[i]->clone());   //TODO:Possible data leak - make sure
            if (pendingAgents[i] != nullptr) {
                delete pendingAgents[i];
                pendingAgents[i] = nullptr;
            }
        }
        if (isEndOfSess()) isFinished = (true);
        (cycle)++;
    }
    cycle = 0;
    createOutput();
}

TreeType Session::getTreeType() const {
    return this->treeType;
}

const int Session::getCycle() const {
    return this->cycle;
}

Graph &Session::getGraph() {
    return g;
}

int Session::dequeueInfected() { //TODO: Check with aviv about this one
    int toPop = infectedQueue.front();
    infectedQueue.pop();
    return toPop;
}


void Session::enqueueInfected(int nodeInd) {
    infectedQueue.push(nodeInd);
}

void Session::setGraph(const Graph &graph) {
    g = (graph);
}

void Session::addAgent(const Agent &agent) {
    pendingAgents.push_back(agent.clone());
}

const bool
Session::isEndOfSess() const { //for every virus agent, make sure isInfected and make sure all neighbors are infected as well
    bool isSatisfied(true);
    for (int i = 0; isSatisfied && i < agents.size(); i++) {
        //Iterate through the agents list
        if (agents[i] == dynamic_cast<Virus *>(agents[i])) {//TODO:figure out how to know whether virus or not
            int index = agents[i]->getIndex();
            if (g.isInfected(index)) { //if agent is virus and not infected return false;
                isSatisfied = false;
                break;
            }
            //iterate through the edges of the graph to make sure neighbors are infected;
            const vector<int> &neighbors = g.getEdges()[index];
            for (int i = 0; i < neighbors.size(); i++) {
                if ((neighbors[i] == 1 )& !g.isInfected(i)) {
                    isSatisfied = false;
                    break;
                }
            }
        }
    }
    return isSatisfied;

}

void Session::createOutput() {
    json output;
    const vector<char> &infectedBool = g.getNodeStatusList();
    vector<int> infectedList;
    for (int i = 0; i < infectedBool.size(); i++) {
        if (infectedBool[i] == 'I') infectedList.push_back(i);
    }
    output["infected_Nodes"] = infectedList; //TODO: need to handle dequeue for full queue or use the g.isInfectedList
    output["graph"] = g.getEdges();
    ofstream outFile("./output.json");
    outFile << output;
}

//rule of 5



//destructor
void Session::clear() {
    //delete all agents on agents
    for (int i = 0; i < agents.size(); i++) {
        if (agents[i] != nullptr) {
            delete agents[i];
            agents[i] = nullptr;
        }
    }
    //delete all agents on pendingAgents - should be empty at that point already
    for (int i = 0; i < pendingAgents.size(); i++) {
        if (pendingAgents[i] != nullptr) {
            delete pendingAgents[i];
            pendingAgents[i] = nullptr;
        }
    }
}

Session::~Session() {
    clear();
}

//copy constructor

void Session::copy(const Graph &other_g, const TreeType &other_treeType, const int &other_cycle,
                   const vector<Agent *> &other_agents, const vector<Agent *> &other_pendingAgents,
                   const queue<int> &other_infectedQueue) { //Didn't pass session object to avoid unnecessary getters creation
    g = other_g; //Todo - make sure it's not a pointer but assignment operator
    treeType = other_treeType;
    cycle = other_cycle;
    infectedQueue = other_infectedQueue;
    agents = vector<Agent *>(other_agents.size());
    pendingAgents = vector<Agent *>(other_pendingAgents.size());

    for (Agent *ag:other_agents) {
        agents.push_back(ag->clone());
    }
    for (Agent *ag:other_pendingAgents) {
        pendingAgents.push_back(ag->clone());
    }
}


Session::Session(const Session &other) : g(vector<vector<int>>()) {
    copy(other.g, other.treeType, other.cycle, other.agents, other.pendingAgents, other.infectedQueue);
}

//copy assignment
Session &Session::operator=(const Session &other) {
    if (this == &other) {
        return *this;
    }
    //Todo:add safety
    clear();
    copy(other.g, other.treeType, other.cycle, other.agents, other.pendingAgents, other.infectedQueue);
    return *this;
}

//move constructor
Session::Session(Session &&other) : g(std::move(other.g)), treeType(other.treeType), cycle(other.cycle),
                                    agents(std::move(other.agents)), pendingAgents(std::move(other.pendingAgents)),
                                    infectedQueue(std::move(other.infectedQueue)) {
    other.agents.clear();
    other.pendingAgents.clear();
}

//move assignment
Session &Session::operator=(Session &&other) {
    if (this != &other) {
        clear();
        //Steal pointers
        g= std::move(other.g);
        treeType = other.treeType;
        cycle = other.cycle;
        agents = std::move(other.agents);
        pendingAgents = std::move(other.pendingAgents);
        infectedQueue = std::move(other.infectedQueue);

        other.agents.clear();
        other.pendingAgents.clear();
    }
    return *this;
}






