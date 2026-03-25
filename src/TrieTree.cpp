#include "TrieTree.h"

//Define Metadata constructor
Metadata::Metadata(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity)
{
    _songTitle = songTitle;
    _artistName = artistName;
    _releaseYear = releaseYear;
    _popularity = popularity;
}

//Define Trie node constructor
TrieNode::TrieNode()
{
    _isSongTitle = false;                   //Indicates that node is end of song and holds metadata
    _metadata = nullptr;                    //Pointer to metadata struct
}

//Define TrieTree constructor
TrieTree::TrieTree()
{
    _root = new TrieNode();                 //Creates empty root node automatically
}

//Define TrieTree destructor
TrieTree::~TrieTree()
{
    deleteNode(_root);
}

//Recursively delete all nodes
void TrieTree::deleteNode(const TrieNode* node)
{
    if (!node)                                                          //If pointer is null return
        return;
    for (auto& child: node->_children)    //Traverse all child nodes
        deleteNode(child.second);

    delete node->_metadata;                                             //Delete metadata
    delete node;                                                        //Delete node
}

//Insert song title and metadata into Trie
void TrieTree::insert(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity) const
{
    TrieNode* current = _root;                                                              //Start at root
    for (char32_t letter : songTitle)                                                       //For each character in song title
    {
        if (current->_children.find(letter) == current->_children.end())                    //If character doesnt exist in branch
            current->_children[letter] = new TrieNode();                                    //Create new node with character

        current = current->_children[letter];                                               //Traverse to next character
    }
    current->_isSongTitle = true;                                                           //At end of song title set flag
    current->_metadata = new Metadata(songTitle, artistName, releaseYear, popularity);      //Insert metadata
}

//Search Trie for song title and return metadata
Metadata* TrieTree::search(const string& songTitle) const
{
    TrieNode* current = _root;                                                              //Start at root
    for (char32_t letter : songTitle)                                                       //For each character in song title
    {
        if (current->_children.find(letter) == current->_children.end())                    //If character doesnt exist in branch
            return nullptr;                                                                 //Return nullptr
        current = current->_children[letter];                                               //Traverse to next character
    }
    return current->_metadata;                                                              //At end of song title return metadata
}
