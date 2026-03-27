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
            bool fixing = true;

            if (current->_data->_songTitle.compare(songTitle) > 0 && current->leftChild->_data == nullptr) {
                current->leftChild->_data = new Data(songTitle, artistName, releaseYear, popularity);
                current->leftChild->isBlack = false;
                current->leftChild->parent = current;
                inserting = false;
            }
            else if (current->rightChild->_data == nullptr) {
                current->rightChild->_data = new Data(songTitle, artistName, releaseYear, popularity);
                current->rightChild->isBlack = false;
                current->rightChild->parent = current;
                inserting = false;
            }
            else {
                fixing = false;
            }

            while (fixing) {
                if (current->parent->isBlack) {
                    fixing = false;
                }
                else if (!current->parent->parent->leftChild->isBlack && !current->parent->parent->rightChild->isBlack) {
                    current->parent->parent->isBlack = false;
                    current->parent->parent->leftChild->isBlack = true;
                    current->parent->parent->rightChild->isBlack = true;

                    if (current->parent->parent == _root) {
                        _root->isBlack = true;
                        fixing = false;
                    }
                }
                else {
                    bool childPosition = false; //false means leftChild relative to parent node, true means rightChild relative to parent node
                    bool parentPosition = false;
                    bool grandparentPosition = false;
                    RBTreeNode* _parent = current->parent;
                    RBTreeNode* _grandparent = current->parent->parent;
                    RBTreeNode* _greatgrandparent = current->parent->parent->parent;

                    if (current->_data->_songTitle.compare(_parent->_data->_songTitle) > 0) {
                        childPosition = true;
                    }

                    if (_parent->_data->_songTitle.compare(_grandparent->_data->_songTitle) > 0) {
                        parentPosition = true;
                    }

                    if (_grandparent->_data->_songTitle.compare(_greatgrandparent->_data->_songTitle) > 0) {
                        grandparentPosition = true;
                    }

                    if (childPosition && parentPosition) {
                        _parent->leftChild->parent = _grandparent;
                        _grandparent->rightChild = _parent->leftChild;
                        _parent->leftChild = _grandparent;
                        _grandparent->parent = _parent;
                        _parent->isBlack = true;
                        _grandparent->isBlack = false;

                        if (grandparentPosition) {
                            _greatgrandparent->rightChild = _parent;
                            _parent->parent = _greatgrandparent;
                        }
                        else {
                            _greatgrandparent->leftChild = _parent;
                            _parent->parent = _greatgrandparent;
                        }
                    }
                    else if (!childPosition && !parentPosition) {
                        _parent->rightChild->parent = _grandparent;
                        _grandparent->leftChild = _parent->rightChild;
                        _parent->rightChild = _grandparent;
                        _grandparent->parent = _parent;
                        _parent->isBlack = true;
                        _grandparent->isBlack = false;

                        if (grandparentPosition) {
                            _greatgrandparent->rightChild = _parent;
                            _parent->parent = _greatgrandparent;
                        }
                        else {
                            _greatgrandparent->leftChild = _parent;
                            _parent->parent = _greatgrandparent;
                        }
                    }
                    else if (parentPosition) {
                        _parent->parent = _parent->leftChild;
                        _parent->leftChild = _grandparent;
                        _grandparent->parent = _parent;
                        _grandparent->rightChild = nullptr;
                        _grandparent->rightChild->isBlack = true;
                        current->parent = _greatgrandparent;

                        if (grandparentPosition) {
                            _greatgrandparent->rightChild = current;
                        }
                        else {
                            _greatgrandparent->leftChild = current;
                        }

                        _grandparent->parent = current;
                        _parent->leftChild = nullptr;
                        _parent->leftChild->isBlack = true;
                        current->leftChild = _grandparent;
                        current->isBlack = true;
                        _grandparent->isBlack = false;
                        current = _parent;
                    }
                    else {
                        _parent->parent = _parent->rightChild;
                        _parent->rightChild = _grandparent;
                        _grandparent->parent = _parent;
                        _grandparent->leftChild = nullptr;
                        _grandparent->leftChild->isBlack = true;
                        current->parent = _greatgrandparent;

                        if (grandparentPosition) {
                            _greatgrandparent->rightChild = current;
                        }
                        else {
                            _greatgrandparent->leftChild = current;
                        }

                        _grandparent->parent = current;
                        _parent->rightChild = nullptr;
                        _parent->rightChild->isBlack = true;
                        current->rightChild = _grandparent;
                        current->isBlack = true;
                        _grandparent->isBlack = false;
                        current = _parent;
                    }
                }
                current = current->parent->parent;
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