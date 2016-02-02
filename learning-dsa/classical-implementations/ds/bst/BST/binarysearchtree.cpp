#include "binarysearchtree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree()
{
    std::cout << "Calling constructor" << std::endl;
    initializeBinarySearchTree();
}

BinarySearchTree::BinarySearchTree(BinarySearchTree const &)
{
    std::cout << "Calling copy constructor" << std::endl;
}

BinarySearchTree& BinarySearchTree::operator=(BinarySearchTree const &)
{
    std::cout << "Calling operator =" << std::endl;
}

BinarySearchTree::~BinarySearchTree()
{
    std::cout << "Calling destructor" << std::endl;
    clearBinarySearchTree();
}

void BinarySearchTree::initializeBinarySearchTree()
{
    this->root = NULL;
}

void BinarySearchTree::insert(int x)
{
    Node* tmp = this->root;
    Node* tmpParent = NULL;
    bool found = true;
    while(tmp != NULL && !found)
    {
        tmpParent = tmp;
        if(x < tmp->data)
            tmp = tmp->left;
        else if( x > tmp->data)
            tmp = tmp->right;
        else found = true;
    }
    if (fount) return;

    if(tmpParent == NULL)
    {
        Node* node = new Node(x, NULL, NULL, NULL);
        this->root = node;
    }
    else
    {
        Node* node = new Node(x, NULL, NULL, tmpParent);
        if(x < tmpParent->data) tmpParent->left = node;
        else tmpParent->right = node;
    }
}

Node* BinarySearchTree::search(int data)
{
    return NULL;
}

void BinarySearchTree::clearBinarySearchTree()
{
    clearBinarySearchTreeHelper(this->root);
}

void BinarySearchTree::clearBinarySearchTreeHelper(Node* node)
{
    clearBinarySearchTreeHelper(node->left);
    clearBinarySearchTreeHelper(node->left);
    delete node;
}

void BinarySearchTree::inOrderWalk()
{
    inOrderWalkHelper(this->root);
    std::cout << std::endl;
}

void BinarySearchTree::inOrderWalkHelper(Node* node)
{
    if (node == NULL) return;
    inOrderWalkHelper(node->left);
    std::cout << node->data << " ";
    inOrderWalkHelper(node->right);
}
