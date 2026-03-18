#pragma once
#include <string>
#include <unordered_map>
using namespace std;

struct Metadata
{
    string _songTitle;
    string _artistName;
    int _releaseYear;
    int _popularity;
    Metadata(string songTitle, string artistName, int releaseYear, int popularity);
};

struct TrieNode
{
    unordered_map<char, TrieNode*> _children;
    bool _isSongTitle;
    Metadata* _metadata;
    TrieNode();
};

class TrieTree
{
    TrieNode* _root;

    TrieTree();
    ~TrieTree();
    void insert(const string& songTitle, string artistName, int releaseYear, int popularity);
    bool search(const string& songTitle);
};