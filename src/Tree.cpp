#include <iostream>
#include "../include/Tree.h"
#include "../include/Session.h"

using namespace std;

//Tree
Tree::Tree(int rootLabel) : node(rootLabel),children(new vector<Tree*> ()){ // , children ( new std::vector<Tree*>)?
    node = rootLabel;
    children =  std::vector<Tree*> (2); // in the constructor ?

}
void Tree::addChild(const Tree &child) {

}
Tree* Tree::createTree(const Session &session, int rootLabel) {
    switch (session.getTreeType()) {
        case MaxRank:{
            return new MaxRankTree(rootLabel);
        }
        case Root:{
            return new RootTree(rootLabel);
        }
        case Cycle:{
            return new CycleTree(rootLabel, session.getCycle());
        }
    }

}
int Tree::traceTree() {

}
//CycleTree
CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel) , currCycle(currCycle) {

}
int CycleTree::traceTree() {

}


//MaxRankTree
MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {

}

int MaxRankTree::traceTree() {

}
//RootTree
RootTree::RootTree(int rootLabel) : Tree(rootLabel){

}
int RootTree::traceTree() {

}
