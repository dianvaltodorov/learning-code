#include <iostream>
#include "binarysearchtree.h"

using namespace std;

int main()
{
    BinarySearchTree bst = BinarySearchTree();
    bst.insert(3);
    bst.insert(6);
    bst.insert(6);
    bst.insert(4);
    bst.insert(7);
    bst.insert(1);
    bst.insert(0);
    bst.inOrderWalk();
    return 0;
}
