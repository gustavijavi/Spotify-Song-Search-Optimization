#include "RedBlackTree.h"
#include <string>

using namespace std;

//Definition for RedBlackTree Data constructor
Data::Data(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity)
{
    _songTitle = songTitle;
    _artistName = artistName;
    _releaseYear = releaseYear;
    _popularity = popularity;
}

//Definition for RBTreeNode constructor
RBTreeNode::RBTreeNode()
{
    parent = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
    isBlack = true;
    _data = nullptr;
}

//Definition for RedBlackTree constructor
RedBlackTree::RedBlackTree()
{
    _root = nullptr;
}

//Definition for RedBlackTree deconstructor
RedBlackTree::~RedBlackTree()
{
    deleteNode(_root);
}

//Song delete function for RedBlackTree deconstructor
void RedBlackTree::deleteNode(RBTreeNode* node) {
    if (node == nullptr) {
        return;
    }

    deleteNode(node->leftChild);
    deleteNode(node->rightChild);

    delete node->_data;
    delete node;
}

//Function for doing left rotations
void RedBlackTree::leftRotation(RBTreeNode* node) {
    RBTreeNode* nodeChild = node->rightChild;

    node->rightChild = nodeChild->leftChild;

    if (nodeChild->leftChild != nullptr) {
        nodeChild->leftChild->parent = node;
    }

    nodeChild->parent = node->parent;

    if (node->parent == nullptr) {
        _root = nodeChild;
    }
    else if (node == node->parent->leftChild) {
        node->parent->leftChild = nodeChild;
    }
    else {
        node->parent->rightChild = nodeChild;
    }

    nodeChild->leftChild = node;
    node->parent = nodeChild;
}

//Functions for doing right rotations
void RedBlackTree::rightRotation(RBTreeNode* node) {
    RBTreeNode* nodeChild = node->leftChild;

    node->leftChild = nodeChild->rightChild;

    if (nodeChild->rightChild != nullptr) {
        nodeChild->rightChild->parent = node;
    }

    nodeChild->parent = node->parent;

    if (node->parent == nullptr) {
        _root = nodeChild;
    }
    else if (node == node->parent->rightChild) {
        node->parent->rightChild = nodeChild;
    }
    else {
        node->parent->leftChild = nodeChild;
    }

    nodeChild->rightChild = node;
    node->parent = nodeChild;
}

//Rebalancing and color flipping function for Red Black Tree
void RedBlackTree::fixRedBlackTree(RBTreeNode* node) {
    if (node->parent == nullptr) {
        node->isBlack = true;
        return;
    }

    if (node->parent->parent == nullptr) {
        return;
    }

    while (node->parent != nullptr && !node->parent->isBlack) {
        RBTreeNode* _uncle = nullptr;
        if (node->parent == node->parent->parent->leftChild) {
            _uncle = node->parent->parent->rightChild;
        }
        else {
            _uncle = node->parent->parent->leftChild;
        }

        if (_uncle != nullptr && !_uncle->isBlack) { //Case where uncle is red.
            _uncle->isBlack = true;
            node->parent->isBlack = true;
            node->parent->parent->isBlack = false;
            node = node->parent->parent;
        }
        else if (_uncle == node->parent->parent->rightChild) { //Parent is left child of grandparent node
            if (node == node->parent->rightChild) {
                node = node->parent;
                leftRotation(node); //For left-right case
            }

            node->parent->isBlack = true;
            node->parent->parent->isBlack = false;
            rightRotation(node->parent->parent); //For left-left case
        }
        else {
            if (node == node->parent->leftChild) {
                node = node->parent;
                rightRotation(node); //For right-left case
            }

            node->parent->isBlack = true;
            node->parent->parent->isBlack = false;
            leftRotation(node->parent->parent); //For right-right case
        }
    }
    _root->isBlack = true; //root node has to be always black
}

//Song insert function for RedBlackTree
void RedBlackTree::insert(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity) {
    RBTreeNode* insertedNode = new RBTreeNode();
    insertedNode->_data = new Data(songTitle, artistName, releaseYear, popularity);
    insertedNode->isBlack = false;

    RBTreeNode* current = _root;
    RBTreeNode* currentParent = nullptr;

    while (current != nullptr) {
        currentParent = current;

        if (current->_data->_songTitle.compare(songTitle) < 0) {
            current = current->rightChild;
        }
        else if (current->_data->_songTitle.compare(songTitle) > 0) {
            current = current->leftChild;
        }
        else {
            delete insertedNode->_data; //Just in case if node with song data already exists
            delete insertedNode;
            return;
        }
    }

    insertedNode->parent = currentParent;

    if (currentParent == nullptr) {
        _root = insertedNode;
    }
    else if (insertedNode->_data->_songTitle.compare(currentParent->_data->_songTitle) > 0) {
        currentParent->rightChild = insertedNode;
    }
    else {
        currentParent->leftChild = insertedNode;
    }

    fixRedBlackTree(insertedNode);
}

//Song search function for RedBlackTree
Data* RedBlackTree::search(const string& songTitle) const
{
    RBTreeNode* current = _root;

    while (current != nullptr) {
        if (current->_data->_songTitle.compare(songTitle) < 0) {
            current = current->rightChild; //Goes to right child to search for song title
        }
        else if (current->_data->_songTitle.compare(songTitle) > 0) {
            current = current->leftChild; //Goes to left child to search for song title
        }
        else if (current->_data->_songTitle == songTitle) {
            return current->_data; //Song title and other data returned
        }
    }

    return nullptr;
}