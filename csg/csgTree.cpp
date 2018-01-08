#include "csgTree.h"
#include "csgOperation.h"
#include "CsgDisk.h"
#include "CsgPolygon.h"
#include "csgPrimitive.h"

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



std::string csgTree::afficheTree() {
    std::string result;
    std::set<csgNode*>::iterator iterator = TreeSet.begin();
    for (iterator= TreeSet.begin(); iterator!=TreeSet.end(); ++iterator){
         csgNode* tmp = (*iterator);
        if(tmp->getLabel().compare("disk") == 0){
             csgPrimitive* tmpprim = dynamic_cast<csgPrimitive*>(tmp);
             csgDisk* tmpdisk = dynamic_cast<csgDisk*>(tmpprim);
             if(tmpdisk!=NULL)
                result = result+tmpdisk->getLabel()+" id:"+std::to_string(tmpdisk->getId())+" prim de rayon: "+std::to_string(tmpdisk->getRayon())+"\n";
        }
        else if(tmp->getLabel().compare("polygon")==0){
            csgPrimitive* tmpprim = dynamic_cast<csgPrimitive*>(tmp);
            csgPolygon* tmppoly = dynamic_cast<csgPolygon*>(tmpprim);
            if(tmppoly!=NULL)
                result = result+tmppoly->getLabel()+" id:"+std::to_string(tmppoly->getId())+" poly à face: "+std::to_string(tmppoly->getNbFace())+"\n";
        }else{
            csgOperation* tmpOp = dynamic_cast<csgOperation*>(tmp);
            result = result+tmp->getLabel()+" id:"+std::to_string(tmp->getId())+"\n";
            result =result+"=> filsG : "+tmpOp->getFilsGauche()->getLabel()+" "+std::to_string(tmpOp->getFilsGauche()->getId())+" | filsD: "+tmpOp->getFilsDroit()->getLabel()+" "+std::to_string(tmpOp->getFilsDroit()->getId())+"\n";
        }
    }

    return result;
}

