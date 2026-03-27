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
    isBlack = true;
    _data = nullptr;
}

//Definition for RedBlackTree constructor
RedBlackTree::RedBlackTree()
{
    _root = new RBTreeNode();
}

//Definition for RedBlackTree deconstructor
RedBlackTree::~RedBlackTree()
{
    deleteNode(_root);
}

//Song delete function for RedBlackTree deconstructor
void RedBlackTree::deleteNode(const RBTreeNode* node) {
    if (node == nullptr) {
        return;
    }

    deleteNode(node->leftChild);
    deleteNode(node->rightChild);

    delete node->_data;
    delete node;
}

//Song insert function for RedBlackTree
void RedBlackTree::insert(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity) const
{
    if (_root->_data == nullptr) {
        _root->_data = new Data(songTitle, artistName, releaseYear, popularity);
    }

    RBTreeNode* current = _root;

    bool inserting = true;

    while (inserting) {
        if (current->leftChild->_data == nullptr || current->rightChild->_data == nullptr) {
            if (current->isBlack) {
                if (current->_data->_songTitle.compare(songTitle) > 0) {
                    current->leftChild->_data = new Data(songTitle, artistName, releaseYear, popularity);
                    current->leftChild->isBlack = false;
                    current->leftChild->parent = current;
                    inserting = false;
                }
                else {
                    current->rightChild->_data = new Data(songTitle, artistName, releaseYear, popularity);
                    current->rightChild->isBlack = false;
                    current->rightChild->parent = current;
                    inserting = false;
                }
            }
            else {
                //code to fix or balance tree
            }
        }
        else {
            if (current->_data->_songTitle.compare(songTitle) > 0) {
                current = current->leftChild;
            }
            else {
                current = current->rightChild;
            }
        }
    }
}

//Song search function for RedBlackTree
Data* RedBlackTree::search(const string& songTitle) const
{
    RBTreeNode* current = _root;
    while (true) {
        if (current->_data == nullptr) {
            return nullptr; //nothing is returned if database is empty
        }

        if (current->_data->_songTitle.compare(songTitle) < 0) {
            current = current->rightChild; //Goes to right child to search for song title
        }
        else if (current->_data->_songTitle.compare(songTitle) > 0) {
            current = current->leftChild; //Goes to left child to search for song title
        }
        else {
            return current->_data; //Song title and other data returned
        }
    }
}