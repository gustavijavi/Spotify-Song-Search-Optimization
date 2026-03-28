#pragma once
#include <string>

using namespace std;

//struct definition for RedBlackTree Data
struct Data
{
    string _songTitle;
    string _artistName;
    string _releaseYear;
    string _popularity;
    Data(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity);
};

//struct definition for RBTreeNode
struct RBTreeNode {
    RBTreeNode* parent;
    RBTreeNode* rightChild;
    RBTreeNode* leftChild;
    bool isBlack; //Identifies whether a node is black or red
    Data* _data;
    RBTreeNode();
};

//class definition for RedBlackTree
class RedBlackTree {
    RBTreeNode* _root;
    void deleteNode(RBTreeNode* node);
public:
    RedBlackTree();
    ~RedBlackTree();
    void insert(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity);
    Data* search(const string& songTitle) const;
};