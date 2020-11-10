#include <iostream>
#include "../include/Tree.h"
#include "../include/Session.h"

using namespace std;

//Tree
Tree::Tree(int rootLabel) : node(rootLabel), children(vector<Tree *>()) {
}

void Tree::addChild(const Tree &child) {
    children.push_back(child.clone());
}

const std::vector<Tree *> &Tree::getChildren() const { //TODO: MRT,CT,RT - Test to make sure activates correct function (maybe add Tree::)
    return children;
}

const int &Tree::getLabel() const {//TODO: MRT,CT,RT - Test to make sure activates correct function
    return node;
}


Tree *Tree::createTree(const Session &session, int rootLabel) {
    switch (session.getTreeType()) {
        case MaxRank: {
            return new MaxRankTree(rootLabel);
        }
        case Root: {
            return new RootTree(rootLabel);
        }
        case Cycle: {
            return new CycleTree(rootLabel, session.getCycle());
        }
    }

}

int Tree::traceTree() { //TODO: what to return here ?

}

//CycleTree
CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel), currCycle(currCycle) {

}

int CycleTree::traceTree() {
    Tree *tree = this->clone();
    int op = node;
    while (!tree->getChildren().empty()) {
        tree = tree->getChildren()[0];
        op = tree->getLabel();
    }

    return op;

}


Tree *CycleTree::clone() const {
    return new CycleTree(*this);
}
/*
const int &CycleTree::getLabel() const {//TODO: MRT,CT,RT
    return node;
}

const std::vector<Tree *> &CycleTree::getChildren() const { //TODO: MRT,CT,RT
    return children;
}
*/

//MaxRankTree
MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {

}


int MaxRankTree::traceTree() {
    Tree *tree = this->clone();
    int tempMaxRank;
    int tempMaxLabel;

    std::vector<bool> visited(false);
    std::vector<Tree *> q;

    q.push_back(tree);

    visited[this->node] = true;
    tempMaxLabel = q[0]->getLabel();
    tempMaxRank = this->getChildren().size();

    while (!q.empty()) {
        Tree *tempTree = q[0];
        q.erase(q.begin());

        for (int i = 0; i < tempTree->getChildren().size(); i++) { //loop on tempTree children
            if ((tempTree->getChildren()[i]->getChildren().size() > tempMaxRank) &&
                (!visited[tempTree->getChildren()[i]->getLabel()])) { //first con.
                tempMaxLabel = tempTree->getChildren()[i]->getLabel();
                tempMaxRank = tempTree->getChildren()[i]->getChildren().size();
                tempTree = tempTree->getChildren()[i];
                q.push_back(tempTree);
                visited[tempMaxLabel] = true;
            }
        }
    }
    return tempMaxLabel;
}

Tree *MaxRankTree::clone() const {
    return new MaxRankTree(*this);
}
/*
const int &MaxRankTree::getLabel() const {//TODO: MRT,CT,RT
    return node;
}

const std::vector<Tree *> &MaxRankTree::getChildren() const { //TODO: MRT,CT,RT
    return children;
}
*/
//RootTree
RootTree::RootTree(int rootLabel) : Tree(rootLabel) {

}

int RootTree::traceTree() {
    return node;
}

Tree *RootTree::clone() const {
    return new RootTree(*this);
}
/*
const int &RootTree::getLabel() const {//TODO: MRT,CT,RT
    return node;
}

const std::vector<Tree *> &RootTree::getChildren() const { //TODO: MRT,CT,RT
    return children;
}
*/
//--------------Rule of 5--------------
//Destructor
void Tree::clear(){
    for (int i = 0; i < children.size(); i++) {
        delete children[i];
        children[i] = nullptr;
    }
}

Tree::~Tree() {
    clear();
}

//copyConstructor
Tree::Tree(const Tree &other) :node(other.node) , children(other.children) {
        for (Tree * tc :other.children){
            children.push_back(tc->clone());
        }
}

//copy assignment
Tree &Tree::operator=(const Tree &other) {
    if (this == &other) {
        return *this;
    }
    if ((!(children.empty())) & (node >0)) {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
            children[i] = nullptr;
        }
    }
    node = other.node;
    children = other.children;
    for (Tree * tT:other.children){
        children.push_back(tT->clone());
    }

}

//move constructor
Tree::Tree(Tree &&other) : node(other.node) , children(other.getChildren()) {
    other.clear();
}


//move assignment
Tree &Tree::operator=(Tree &&other) {
    if(!(children.empty())){
        clear();
    }
    children = other.getChildren();
    node = other.getLabel();

    return *this;
}
