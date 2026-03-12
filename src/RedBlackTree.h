#pragma once
#include <iostream>
#include <string>

using namespace std;

class RedBlackTree {

// private for creating root variable and functions
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

    // I'm thinking for the search we return a boolean for whether
    // it was successful and then have references to variables from
    // main.cpp to store the artist name, release year, and popularity
    // in.
    // ex. bool searchBySongTitle(const string& songTitle, string& artistName, int& releaseYear, int& popularity){}
    bool searchBySongTitle(const string& songTitle);

    // same thing here just switching around song title and artist name
    bool searchByArtistName(const string& artistName);

};