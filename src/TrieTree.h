#pragma once
#include <string>
#include <unordered_map>
using namespace std;

//Define Metadata struct
struct Metadata
{
    string _songTitle;
    string _artistName;
    string _releaseYear;
    string _popularity;
    Metadata(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity);
};

//Define TrieNode struct
struct TrieNode
{
    unordered_map<char32_t, TrieNode*> _children;       //Unordered map with char32_t keys used for special characters
    bool _isSongTitle;
    Metadata* _metadata;
    TrieNode();
};

//Define TrieTree class
class TrieTree
{
    TrieNode* _root;
    void deleteNode(const TrieNode* node);
public:
    TrieTree();
    ~TrieTree();
    void insert(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity) const;
    Metadata* search(const string& songTitle) const;
};