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
//for efficiency reasons as instructed in the office hours
void Tree::addChild(Tree* child){
    children.push_back(child);
}

const std::vector<Tree *> &
Tree::getChildren() const { //TODO: MRT,CT,RT - Test to make sure activates correct function (maybe add Tree::)
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
        default:
            return 0;
    }

}


//CycleTree
CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel), currCycle(currCycle) {

}

int CycleTree::traceTree() {
    Tree *tree = this->clone();
    int cC = this->currCycle;
    int op = node;
    while (!tree->getChildren().empty() & (cC!=0)) {
        tree = tree->getChildren()[0];
        op = tree->getLabel();
        cC--;
    }
    return op;
}


Tree *CycleTree::clone() const {
    return new CycleTree(*this);
}

//MaxRankTree
MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {

}

Tree *MaxRankTree::clone() const {
    return new MaxRankTree(*this);
}

int MaxRankTree::traceTree() { // commit BFS travel over the tree (due to code clearance decided not to add to BFS function logic)
    //  Tree *tree = this->clone();

    std::deque<Tree *> q;
    q.push_back(this);
    int tempMaxLabel = q[0]->getLabel();
    int tempMaxRank = this->getChildren().size();
    while (!q.empty()) {
        Tree *tempTree = q[0];
        q.pop_front();
        for (int i = 0; i < tempTree->getChildren().size(); i++) { //loop on tempTree children
            if ((tempTree->getChildren()[i]->getChildren().size() > tempMaxRank))
            {
                tempMaxLabel = tempTree->getChildren()[i]->getLabel();
                tempMaxRank = tempTree->getChildren()[i]->getChildren().size();

            }
            tempTree = tempTree->getChildren()[i];
            q.push_back(tempTree);
        }
    }
    return tempMaxLabel;
}
RootTree::RootTree(int rootLabel) : Tree(rootLabel) {

}

int RootTree::traceTree() {
    return node;
}

Tree *RootTree::clone() const {
    return new RootTree(*this);
}


//-----------------------------------------------------Rule of 5--------------------------------------------------
//Destructor
void Tree::clear() {
    for (int i = 0;( i < children.size() )& !(children.empty()); i++) {
        if(children[i]!= nullptr){
            children[i]->clear();
            children[i] = nullptr;
        }
    }
    children.clear();
}
Tree::~Tree() {
    clear();
}
//copyConstructor
void Tree::copy(const vector<Tree *> &other_children , const int &other_node) {
    children = other_children;
    node = other_node;
    for (int i = 0; (i < other_children.size()) & !(other_children.empty()); i++) {
            children.push_back(other_children[i]->clone());
    }
}
Tree::Tree(const Tree &other) : node(other.node), children(other.children) {
    copy(other.children,other.node);
}

//copy assignment
Tree &Tree::operator=(Tree& other) {
    if (this == &other) {  // how to change this one
        return *this;
    }
    other.clear();
    copy(other.children, other.node);
    return *this;
}

//move constructor
Tree::Tree(Tree&& other) : node(other.node), children(other.getChildren()) {
    other.clear();
}
//move assignment
Tree &Tree::operator=(Tree&& other) {
    if (!(children.empty())) {
        clear();
    }
    children = other.getChildren();
    node = other.getLabel();
    other.children.clear();
    return *this;
}

//-------------------------------------------------end Rule of 5--------------------------------------------------
