#include <iostream>
#include "dbtree.h"
#include "dbinsearchtree.h"


int main() {
    DBTree tree;
    tree.testAufgabe();

    tree.print(tree.getRoot());

    DBTree neuerAal(tree);

    std::cout << "Der Neue Aal:" << std::endl;
    neuerAal.print(neuerAal.getRoot());

    DBinSearchTree d;


    d.insert("Peter");
    d.insert("Altenbernd");
    d.insert("faehrt");
    d.insert("nach");
    d.insert("Darmstadt");

    d.print(d.getRoot());
    std::cout << "Zeylenymbrych" << std::endl << std::endl;

    d.EbenenweiseAusgabe();

    return 0;
}
