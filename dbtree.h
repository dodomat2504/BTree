#ifndef DBTREE_H
#define DBTREE_H

#include <iostream>


class Knoten {
private:
    const int ID;

    std::string data;
    Knoten* left;
    Knoten* right;

    static int IDCounter;
public:
    Knoten(const std::string& data, Knoten* l = nullptr, Knoten* r = nullptr): ID(IDCounter++), data(data), left(l), right(r) {}

    int getID() const {return ID;}
    std::string getData() const {return data;}
    Knoten* getLeft() {return left;}
    Knoten* getRight() {return right;}
    void setLeft(Knoten* l) {left = l;}
    void setRight(Knoten* r) {right = r;}
};

int Knoten::IDCounter = 0;

class DBTree {
protected:
    Knoten* root;
    bool isSubTree;

    void deleteAllNodes(Knoten* node) {
        if (node == nullptr) return;
        deleteAllNodes(node->getLeft());
        deleteAllNodes(node->getRight());
        delete node;
    }

    Knoten* copyRecursively(Knoten* node) const {
        if (node == nullptr) return nullptr;

        Knoten* l = copyRecursively(node->getLeft());
        Knoten* r = copyRecursively(node->getRight());

        Knoten* n = new Knoten(node->getData(), l, r);
        return n;
    }
public:
    DBTree(Knoten* rootNode = nullptr, const bool isSubTree = false): root(rootNode), isSubTree(isSubTree) {}

    DBTree(const DBTree& tree): root(nullptr) {this->root = copyRecursively(tree.getRoot());}

    ~DBTree() {if (!isSubTree) deleteAllNodes(root);}

    Knoten* getRoot() const {return root;}

    bool empty(Knoten* node) const {return node == nullptr;}

    std::string value(Knoten* node) const {
        if (node != nullptr) return node->getData();
        else throw std::invalid_argument("Parameter 'node' is a nullpointer!");
    }

    Knoten* left(Knoten* node) const {
        if (node != nullptr) return node->getLeft();
        else return nullptr;
    }

    Knoten* right(Knoten* node) const {
        if (node != nullptr) return node->getRight();
        else return nullptr;
    }

    Knoten* create() {return nullptr;}

    void print(Knoten* node) const {
        if (node == nullptr) return;
        print(left(node));
        std::cout << "Nummer: " << node->getID() << ", Text: '" << node->getData() << "'" << std::endl;
        print(right(node));
    }

    Knoten* node(Knoten* l, const std::string& data, Knoten* r) {return new Knoten(data, l, r);}

    void testAufgabe() {
        root = node(node(create(), "Peter" ,node(create(), "Altenbernd", create())), "faehrt", node(create(), "nach", node(create(), "Darmstadt", create())));
    }

};

#endif // DBTREE_H
