#pragma once
#include <string>
#include <unordered_map>
using namespace std;

struct Metadata
{
    string _songTitle;
    string _artistName;
    string _releaseYear;
    string _popularity;
    Metadata(const string& songTitle, const string& artistName, const string& releaseYear, const string& popularity);
};

struct TrieNode
{
    unordered_map<char32_t, TrieNode*> _children;
    bool _isSongTitle;
    Metadata* _metadata;
    TrieNode();
};

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