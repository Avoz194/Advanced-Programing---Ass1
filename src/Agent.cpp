#include <iostream>
#include "../include/Agent.h"
//TODO: check about this

using namespace std;

Agent::Agent(Session &session) : session(session) {
        session = this->session;
}
Agent * Agent::clone() {

}


void Agent::act() {

}

ContactTracer::ContactTracer() {
    session = this->session;
}

void ContactTracer::act(Session &session) {
    Graph &g1 = session.getGraph();
    Virus viral =  session.getInfectedQueue().pop();
    int num = virus.getIndex();
    g1.isolateNode(num);
}

Virus::Virus(int nodeInd) : nodeInd(nodeInd) {
}

void Virus::act(Session &session) {
    Graph &g1 = session.getGraph();
    if (!g1.isInfected(getIndex())) { //if agent hasn't been infected already - infect it and add to Q
        g1.infectNode(getIndex());
        session.enqueueInfected(getIndex());
    }
    const vector<int> &neighbors(g1.getEdges()[getIndex()]); //go over neighbors to look for a neighbor that isn't infected
    bool spread = false;
    for (int i = 0; !spread & i < neighbors.size(); i++) {
        if (neighbors[i] == 1 & !g1.hasVirus(i)) {
            g1.spreadVirus(i);  //spread the virus to node i
            Agent *nextVirus = new Virus(i);
            session.addAgent(*nextVirus); //add as an agent
            delete nextVirus; //addAgent clone the nextVirus so need to delete nextVirus
            spread=true;
        }
    }
}

const int Virus::getIndex() const { return nodeInd; }
Agent* Virus::clone() {
    return new Virus(*this));
}
