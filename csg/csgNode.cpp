#include "csgNode.h"

// ---------------------------------------------------------------------
// All explications for functions are in the file csgNode.h
// ---------------------------------------------------------------------


// initialisation du membre statique
int csgNode::nb_node = 0;


csgNode::csgNode(std::string label) {
    this->label = label;
    id = nb_node;
    parent= NULL;

    nb_node++;
}

csgNode::csgNode(const csgNode& copy) {
    label = copy.label;
    id = copy.id;
    parent = copy.parent;

    nb_node++;
}


std::string csgNode::getLabel() {
    return label;
}

void csgNode::setLabel(std::string label) {
    this->label = label;
}

int csgNode::getId() {
    return id;
}

void csgNode::setId(int id) {
    this->label = label;
}

csgNode *csgNode::getParent() {
    return parent;
}

void csgNode::setParent(csgNode *parent) {
    this->parent = parent;
}


BoundingBox csgNode::getBbox(){
    return box;
}

void csgNode::setBbox(const BoundingBox& box)
{
    this->box = box;
}
