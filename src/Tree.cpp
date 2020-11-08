#include <iostream>
#include "../include/Tree.h"
#include "../include/Session.h"

using namespace std;

//Tree
Tree::Tree(int rootLabel) : node(rootLabel),children(vector<Tree*>()){
}

void Tree::addChild(const Tree &child) {
    children.push_back(child.clone());
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


Tree *CycleTree::clone() const {
    return new CycleTree(*this);
}


//MaxRankTree
MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {

}

int MaxRankTree::traceTree() {

}

Tree * MaxRankTree::clone() const {
    return new MaxRankTree(*this);
}
//RootTree
RootTree::RootTree(int rootLabel) : Tree(rootLabel){

}
int RootTree::traceTree() {

}
Tree * RootTree::clone() const {
    return new RootTree(*this);
}
