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

void leftRotation(RBTreeNode* node) {
    //continue
}

void rightRotation(RBTreeNode* node) {
    //continue
}

void fixRedBlackTree(RBTreeNode* node) {
    if (node->parent == nullptr) {
        node->isBlack = true;
        return;
    }

    if (node->parent->parent == nullptr) {
        return;
    }

    RBTreeNode* _parent = node->parent;

    while (_parent != nullptr && !_parent->isBlack) {
        RBTreeNode* _uncle = nullptr;
        if (_parent == _parent->parent->leftChild) {
            _uncle = _parent->parent->rightChild;
        }
        else {
            _uncle = _parent->parent->leftChild;
        }

        if (_uncle != nullptr && !_uncle->isBlack) {
            _uncle->isBlack = true;
            _parent->isBlack = true;
            _parent->parent->isBlack = false;
            node = _parent->parent;
            _parent = node->parent;
        }
        else if (node == _parent->leftChild) {
            //continue
        }
        else {
           //continue
        }
    }
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