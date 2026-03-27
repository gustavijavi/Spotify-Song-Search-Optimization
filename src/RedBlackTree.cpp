#include "RedBlackTree.h"
#include <string>

using namespace std;

//Definition for RedBlackTree Metadata constructor
Data::Data(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity)
{
    _songTitle = songTitle;
    _artistName = artistName;
    _releaseYear = releaseYear;
    _popularity = popularity;
}

RBTreeNode::RBTreeNode()
{
    isBlack = true;
    _data = nullptr;
}

RedBlackTree::RedBlackTree()
{
    _root = new RBTreeNode();
}

RedBlackTree::~RedBlackTree()
{
    deleteNode(_root);
}

void RedBlackTree::deleteNode(const RBTreeNode* node) {
    if (node == nullptr) {
        return;
    }

    deleteNode(node->leftChild);
    deleteNode(node->rightChild);

    delete node->_data;
    delete node;
}

void RedBlackTree::insert(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity) const
{
    if (_root->_data == nullptr) {
        _root->_data = new Data(songTitle, artistName, releaseYear, popularity);
    }

    RBTreeNode* current = _root;

    bool inserting = true;

    while (inserting) {
        if (current->leftChild->_data == nullptr) {
            if (current->isBlack) {
                current->leftChild->_data = new Data(songTitle, artistName, releaseYear, popularity);
                current->leftChild->isBlack = false;
                current->leftChild->parent = current;
            }
            else {
                //fix/balance tree code
            }
        }
        else if (current->rightChild->_data == nullptr) {
            if (current->isBlack) {
                current->rightChild->_data = new Data(songTitle, artistName, releaseYear, popularity);
                current->rightChild->isBlack = false;
                current->rightChild->parent = current;
            }
            else {
                //fix/balance tree code
            }
        }
    }
}

//Song search function for RedBlackTree
Data* RedBlackTree::search(const string& songTitle) const
{
    RBTreeNode* current = _root;
    bool searching = true;
    while (searching) {
        string currentSongTitle = current->_data->_songTitle;

        if (current->_data == nullptr) {
            return nullptr;
        }

        if (currentSongTitle.compare(songTitle) < 0) {
            current = current->rightChild;
        }
        else if (currentSongTitle.compare(songTitle) > 0) {
            current = current->leftChild;
        }
        else {
            return current->_data;
        }
    }
}
