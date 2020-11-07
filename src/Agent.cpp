#include <iostream>
#include "../include/Agent.h"
//TODO: check about this
using namespace std;

Agent::Agent(Session &session, Session &session1) : session(session1) {}


void Agent::act() {

}

ContactTracer::ContactTracer(Session &session) : Agent(session) {

}

void ContactTracer::act() {

}

Virus::Virus(int nodeInd) : nodeInd(nodeInd) {
}

void Virus::act(Session &session) {
    Graph &g1 = session.getGraph();
    if (!g1.isInfected(getIndex())) { //if agent haven't been infected already - infect it
        g1.infectNode(getIndex());
        session.enqueueInfected(getIndex());
    }
    const vector<int> &neighbors(
            g1.getEdges()[getIndex()]); //go over neighbors to look for a neighbor that isn't infected
    bool spread = false;
    for (int i = 0; !spread & i < neighbors.size(); i++) {
        if (neighbors[i] == 1 & !g1.isInfected(i)) {
            g1.spreadVirus(i);  //spread the node
            Agent *nextVirus = new Virus(i);
            session.addAgent(*nextVirus); //add as agent
            delete nextVirus;
        }
    }
}

const int Virus::getIndex() const { return nodeInd; }
