#include <iostream>
#include "../include/Agent.h"
//TODO: check about this
using namespace std;

Agent::Agent(Session &session, Session &session1) : session(session1) {}


void Agent::act() {

}
ContactTracer::ContactTracer( Session &session) : Agent(session) {

}
void ContactTracer::act() {

}

Virus::Virus(int nodeInd, Session &session)  {}

void Virus::act() {

}