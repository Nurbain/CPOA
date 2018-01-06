#ifndef CSGOPERATION_H
#define CSGOPERATION_H

#include "csgNode.h"

enum operation{ opUnion,opIntersect,opDifference};

class csgOperation : public csgNode {
public:
    csgNode* filsG;
    csgNode* filsD;
    enum operation operation;

    csgOperation(std::string label,csgNode* filsG, csgNode* filsD, enum operation op);
    csgOperation(const csgOperation& copy);
    ~csgOperation();

    enum operation getOperation();
    csgNode *getFilsGauche();
    csgNode *getFilsDroit();

    void setOperation(enum operation op);
    void setFilsGauche(csgOperation *filsG);
    void setFilsDroit(csgOperation *filsD);


    bool Intersect(Vec2d v);
    bool IntersectBBox(Vec2d v);
};


#endif
