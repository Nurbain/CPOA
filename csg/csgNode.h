#ifndef CSGNODE_H
#define CSGNODE_H

#include <string>
#include "BoundingBox.h"

class csgNode{

static int nb_node;

public:
    int id;
    std::string label;
    csgNode* parent;
    BoundingBox box;   

    //Constructeur
    csgNode(std::string label);
    csgNode(const csgNode& copy);
    ~csgNode(){};

    std::string getLabel();
    void setLabel(std::string label);

    int getId();
    void setId(int id);

    csgNode* getParent();
    void setParent(csgNode* parent);

    BoundingBox getBbox();
    void setBbox(const BoundingBox& box);



    virtual bool Intersect(Vec2d v) = 0;
    virtual bool IntersectBBox(Vec2d v) = 0;
};



#endif
