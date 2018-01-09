#ifndef CSGNODE_H
#define CSGNODE_H

#include <string>
#include "BoundingBox.h"
#include <iostream>

/**
 * @brief The csgNode class, classe Abstraite des noeuds de l'arbre csg
 */
class csgNode{

//Nombre de noeuds
static int nb_node;

public:

    int id;
    std::string label;
    csgNode* parent;
    BoundingBox box;   

    //Constructeur
    /**
     * @brief csgNode, constructeur
     * @param label
     */
    csgNode(std::string label);

    /**
     * @brief csgNode, constructeur par copy
     * @param copy
     */
    csgNode(const csgNode& copy);
    ~csgNode(){}

    // Get/Set de l'id,label,parent,box
    std::string getLabel();
    void setLabel(std::string label);

    int getId();
    void setId(int id);

    csgNode* getParent();
    void setParent(csgNode* parent);

    BoundingBox getBbox();
    void setBbox(const BoundingBox& box);


    /**
     * @brief Intersect,interesction de la primitive et un point
     * @param v, point
     * @return
     */
    virtual bool Intersect(Vec2d v) = 0;

    /**
     * @brief IntersectBBox, interesction du point et de la BoundingBox de la primitve
     * @param v, point
     * @return
     */
    virtual bool IntersectBBox(Vec2d v) = 0;
};



#endif
