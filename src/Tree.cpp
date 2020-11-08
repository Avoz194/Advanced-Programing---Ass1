#include <iostream>
#include "../include/Tree.h"
#include "../include/Session.h"

using namespace std;

//Tree
Tree::Tree(int rootLabel) : node(rootLabel),children(new std::vector<Tree*> ){ // , children ( new std::vector<Tree*>)?
    node = rootLabel;
    children =  std::vector<Tree*> (2); // in the constructor ?

}
void Tree::addChild(const Tree &child) {

}
static Tree* Tree::createTree(const Session &session, int rootLabel) {
    return 0;
}
int Tree::traceTree() {

}
//CycleTree
CycleTree::CycleTree(int rootLabel, int currCycle) {
    node = rootLabel;
    currCycle = currCycle;
}
int CycleTree::traceTree() {

}
//MaxRankTree
MaxRankTree::MaxRankTree(int rootLabel) {
    node = rootLabel;
}
int MaxRankTree::traceTree() {

}
//RootTree
RootTree::RootTree(int rootLabel) {
    node = rootLabel;
}
int RootTree::traceTree() {

}
