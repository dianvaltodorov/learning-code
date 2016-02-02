#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int data, Node* left, Node* right, Node* parent)
        : data(data)
        , left(left)
        , right(right)
        , parent(parent)
    {}
};


class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(BinarySearchTree const &);
    BinarySearchTree& operator=(BinarySearchTree const &);
    ~BinarySearchTree();
public:
    void insert(int x);
    Node* search(int x);
    void deleteNode(int x);
    int minimum();
    int maximum();
    int successor();
    void transplant();
    int predecessor();
    int height();
    void inOrderWalk();
    void preOrderWalk();
    void postOrderWalk();

private:
    void inOrderWalkHelper(Node* node);
    void postOrderWalkHelper(Node* node);
    void OrderWalkHelper(Node* node);

private:
   void clearBinarySearchTree();
   void clearBinarySearchTreeHelper(Node* node);
   void initializeBinarySearchTree();


private:
    Node* root;
};

#endif // BINARYSEARCHTREE_H
