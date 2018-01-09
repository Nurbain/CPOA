#ifndef CSGTREE_H
#define CSGTREE_H

#include "csgNode.h"
#include <set>
#include <map>

/**
 * @brief The csgTree class, classe de l'arbre de noeud de csg
 */
class csgTree{

public:

    std::set<csgNode*> TreeSet;
    std::map<int, csgNode*> TreeMap;

    csgTree();

    //Set/Get
    std::set<csgNode *> getTreeSet();
    void setTreeSet(const std::set<csgNode *> &csgTreeSet);
    csgNode* getNode(int id);

    /**
     * @brief addPrimitive, ajoute une primitive a l'arbre
     * @param node
     */
    void addPrimitive(csgNode *node);

    /**
     * @brief joinPrimitive, operation entre noeud
     * @param node
     */
    void joinPrimitive(csgNode *node);

    /**
     * @brief afficheTree, affiche l'arbre en texte
     * @return
     */
    std::string afficheTree();
};


#endif
