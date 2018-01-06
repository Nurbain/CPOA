#include "csgTree.h"
#include "csgOperation.h"

csgTree::csgTree() {

}


std::set<csgNode *> csgTree::getTreeSet()
{
    return TreeSet;
}



void csgTree::setTreeSet(const std::set<csgNode *> &csgTreeSet)
{
    this->TreeSet = TreeSet;
}


csgNode* csgTree::getNode(int id) {
    csgNode * node;
    node = TreeMap.find(id)->second;
    return node;
}


void csgTree::addPrimitive(csgNode *node) {
    TreeSet.insert(node);
    TreeMap.insert(std::pair<int, csgNode*>(node->getId(), node));
}

void csgTree::joinPrimitive(csgNode *node) {

    std::set<csgNode*>::iterator iterator;
    csgOperation *op = static_cast<csgOperation*>(node);

    iterator = TreeSet.find(op->getFilsDroit());
    TreeSet.erase(*iterator);
    iterator = TreeSet.find(op->getFilsGauche());
    TreeSet.erase(*iterator);
    TreeSet.insert(node);
}


void csgTree::afficheTree() {
    std::set<csgNode*>::iterator iterator = TreeSet.begin();
    for (iterator= TreeSet.begin(); iterator!=TreeSet.end(); ++iterator)
        std::cout << (*iterator)->getLabel() << ' ' << (*iterator)->getId() << ' ';

    std::cout << std::endl;
}
