#ifndef TREE_H_
#define TREE_H_

#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel);
    void addChild(const Tree& child);
    static Tree* createTree(const Session& session, int rootLabel);

    virtual int traceTree()=0;
    virtual  Tree * clone() const =0;
    const std::vector<Tree*>& getChildren() const; // for MRT TODO:to delete if not necessary
    const int &getLabel() const;  // for MRT TODO:to delete if not necessary

protected:
    int node;
    std::vector<Tree*> children;
};


class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    virtual  Tree * clone() const;
    const int &getLabel() const;
    const std::vector<Tree*>& getChildren() const;

private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
    virtual  Tree * clone() const;
    const int &getLabel() const;
    const std::vector<Tree*>& getChildren() const;
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
    virtual  Tree * clone() const;
    const int &getLabel() const;
    const std::vector<Tree*>& getChildren() const;
};

#endif
