#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RedBlackTree {

// private for node struct and functions
private:
    
    struct Node {
        string songTitle, artistName;
        int releaseYear, popularity;
        bool isRed;
        Node *parent, *left, *right;

        Node(const string& songTitle, const string& artistName, int releaseYear, int popularity);
    };

    Node* root;

    // TODO: implement private functions here


// public functions here
public:

    RedBlackTree();

    ~RedBlackTree();

    bool insert(const string& songTitle, const string& artistName, int releaseYear, int popularity);

    // TODO: add correct return type for both searches once we discuss on how we'll go about it
    void searchBySongTitle(const string& songTitle);

    void searchByArtistName(const string& artistName);

};