#ifndef CSGTREE_H
#define CSGTREE_H

#include "csgNode.h"
#include <set>
#include <map>


class csgTree{

public:
    std::set<csgNode*> TreeSet;
    std::map<int, csgNode*> TreeMap;

    csgTree();

    std::set<csgNode *> getTreeSet();
    void setTreeSet(const std::set<csgNode *> &csgTreeSet);
    csgNode* getNode(int id);


    void addPrimitive(csgNode *node);
    void joinPrimitive(csgNode *node);

    std::string afficheTree();
};


#endif
