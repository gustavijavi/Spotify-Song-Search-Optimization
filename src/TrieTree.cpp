#include "TrieTree.h"
#include <iostream>


Metadata::Metadata(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity)
{
    _songTitle = songTitle;
    _artistName = artistName;
    _releaseYear = releaseYear;
    _popularity = popularity;
}

TrieNode::TrieNode()
{
    _isSongTitle = false;
    _metadata = nullptr;
}

TrieTree::TrieTree()
{
    _root = new TrieNode();
}

TrieTree::~TrieTree()
{
    deleteNode(_root);
}

void TrieTree::deleteNode(const TrieNode* node)
{
    if (!node)
        return;
    for (auto& child: node->_children)
    {
        deleteNode(child.second);
    }
    delete node->_metadata;
    delete node;
}

void TrieTree::insert(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity) const
{
    TrieNode* current = _root;
    for (char32_t letter : songTitle)
    {
        if (current->_children.find(letter) == current->_children.end())
            current->_children[letter] = new TrieNode();

        current = current->_children[letter];
    }
    current->_isSongTitle = true;
    current->_metadata = new Metadata(songTitle, artistName, releaseYear, popularity);
}

Metadata* TrieTree::search(const string& songTitle) const
{
    TrieNode* current = _root;
    for (char32_t letter : songTitle)
    {
        if (current->_children.find(letter) == current->_children.end())
            return nullptr;
        current = current->_children[letter];
    }
    return current->_metadata;
}
