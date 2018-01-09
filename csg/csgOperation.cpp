#include "csgOperation.h"

// ---------------------------------------------------------------------
// All explications for functions are in the file csgOperation.h
// ---------------------------------------------------------------------


csgOperation::csgOperation(std::string label, csgNode* filsG, csgNode* filsD, enum operation op) : csgNode(label){
    this->filsG = filsG;
    this->filsD = filsD;
    this->operation = op;

    if (operation == opUnion) {
        this->setBbox(filsG->getBbox() + filsD->getBbox());
    } else if (op == opIntersect) {
        this->setBbox(filsG->getBbox() ^ filsD->getBbox());
    }else {
        this->setBbox(filsG->getBbox() - filsD->getBbox());
    }

}


csgOperation::csgOperation(const csgOperation &copy) : csgNode(copy){
    operation = copy.operation;
    filsG = copy.filsG;
    filsD = copy.filsD;
}

csgNode *csgOperation::getFilsGauche() {
    return filsG;
}

void csgOperation::setFilsGauche(csgOperation *filsG) {
    this->filsG = filsG;
}

csgNode *csgOperation::getFilsDroit() {
    return filsD;
}


void csgOperation::setFilsDroit(csgOperation *filsD) {
    this->filsD = filsD;
}


void csgOperation::setOperation(enum operation op) {
    operation = op;
}

enum operation csgOperation::getOperation() {
    return operation;
}


bool csgOperation::Intersect(Vec2d v){
    Vec2d max = box.getMax();
    Vec2d min = box.getMin();

    if (v[0] > min[0] && v[0] < max[0]) {
        if (v[1] > max[1] && v[1] < min[1]) {
            return true;
        }
    }

    return true;
}


bool csgOperation::IntersectBBox(Vec2d v){
    if (operation == opUnion) {
        if (filsG->Intersect(v) && filsD->Intersect(v)) {
            return true;
        }
    } else if (operation == opIntersect) {
        if(filsG->Intersect(v) || filsD->Intersect(v)) {
            return true;
        }
    } else {
        if(filsG->Intersect(v) && filsD->Intersect(v)) {
            return false;
        } else if (filsG->Intersect(v) || filsD->Intersect(v)){
            return true;
        }
    }

    return false;

}

