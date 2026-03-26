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

void RedBlackTree::insert(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity) const
{
    
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
