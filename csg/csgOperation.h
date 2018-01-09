#ifndef CSGOPERATION_H
#define CSGOPERATION_H

#include "csgNode.h"

//Enumeration des types d'operation
enum operation{ opUnion,opIntersect,opDifference};


/**
 * @brief The csgOperation class, class des noeuds de primitives d'operation
 */
class csgOperation : public csgNode {
public:
    csgNode* filsG;
    csgNode* filsD;
    enum operation operation;

    /**
     * @brief csgOperation, constructeur
     * @param label, "Intersect","Union","Diff"
     * @param filsG, fils gauche
     * @param filsD, fils droit
     * @param op, operation du noeud
     */
    csgOperation(std::string label,csgNode* filsG, csgNode* filsD, enum operation op);
    csgOperation(const csgOperation& copy);
    ~csgOperation();

    //Get/Set
    enum operation getOperation();
    csgNode *getFilsGauche();
    csgNode *getFilsDroit();

    void setOperation(enum operation op);
    void setFilsGauche(csgOperation *filsG);
    void setFilsDroit(csgOperation *filsD);

    /**
     * @brief Intersect, Intersection du point avec le noeud
     * @param v, point
     * @return
     */
    bool Intersect(Vec2d v);

    /**
     * @brief IntersectBBox, Intersection du point avec la BoundingBox du noeud
     * @param v, point
     * @return
     */
    bool IntersectBBox(Vec2d v);
};


#endif
