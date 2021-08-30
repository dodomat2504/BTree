#ifndef DBINSEARCHTREE_H
#define DBINSEARCHTREE_H

#include "dbtree.h"
#include <cmath>


class DBinSearchTree : public DBTree {
private:
    int maxTiefe;

    void ebenenweiseAusgabe(const int ebene, int tiefeCounter = 0) const {
            if (tiefeCounter == ebene) {
                std::cout << root->getData() << " ";
            } else {
                if (root->getLeft() != nullptr) {
                    DBinSearchTree(root->getLeft(), true).ebenenweiseAusgabe(ebene, tiefeCounter+1);
                } else {
                    for (int i = 0; i < pow(2, ebene - tiefeCounter - 1); i++) {
                        std::cout << "|X| ";
                    }
                }
                if (root->getRight() != nullptr) {
                    DBinSearchTree(root->getRight(), true).ebenenweiseAusgabe(ebene, tiefeCounter+1);
                } else {
                    for (int i = 0; i < pow(2, ebene - tiefeCounter - 1); i++) {
                        std::cout << "|X| ";
                    }
                }
            }
        }

public:
    DBinSearchTree(Knoten* r = nullptr, const bool isSubTree = false): DBTree(r, isSubTree), maxTiefe(0) {}

    void insert(const std::string& data) {
        Knoten* node = root;
        Knoten* prev = nullptr;
        bool wentRight = true;
        int tiefeCounter = 1;

        while (node != nullptr) {
            prev = node;
            if (node->getData() < data) {
                node = node->getRight();
                wentRight = true;
            } else {
                wentRight = false;
                node = node->getLeft();
            }
            tiefeCounter++;
        }

        node = new Knoten(data);
        if (prev != nullptr) {
            if (wentRight) prev->setRight(node);
            else prev->setLeft(node);
            if (maxTiefe < tiefeCounter) maxTiefe = tiefeCounter;
        } else {
            root = node;
            maxTiefe = 1;
        }
        std::cout << "Maxtiefe: " << maxTiefe << std::endl;
    }

    /*
    void insertRec(const std::string& data, Knoten* node) {
        if (node == nullptr) {
            root = new Knoten(data);
            return;
        }
        if (data <= node->getData()) {
            if (node->getLeft() == nullptr) node->setLeft(new Knoten(data));
            else insertRec(data, node->getLeft());
        } else {
            if (node->getRight() == nullptr) node->setRight(new Knoten(data));
            else insertRec(data, node->getRight());
        }
    }
    */

    void EbenenweiseAusgabe() const {
        for (int i = 0; i < maxTiefe; i++) {
            ebenenweiseAusgabe(i);
            std::cout << std::endl;
        }
    }
};

#endif // DBINSEARCHTREE_H
