#include <cstdlib>
#include <iostream>
#include "BST.h"


int main(int argc, char** argv) {

    int Tree[16] = {44, 9, 100, 36, 67, 12, 75, 2};
    BST myTree;
    for(int i = 0; i < 8; i++){
        myTree.AddLeaf(Tree[i]);
    }
    
    
    std::cout << "\nSuccess\n";
    return 0;
}