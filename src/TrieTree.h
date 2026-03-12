#pragma once
#include <iostream>
#include <string>
#include <array>

using namespace std;


struct Node {
    array<Node*, 26> children; // for all the 26 letters in alphabet
    bool isSongTitle;
    string artistName;
    int releaseYear;
    int popularity;

    Node(int releaseYear, int popularity);
};


class TrieTree {

private:

    Node* root;

    // TODO: implement private functions

// public functions here
public:

    TrieTree();

    ~TrieTree();

    void insert(const string& songOrArtist);

    // I'm thinking for the search we return a boolean for whether
    // it was successful and then have references to variables from
    // main.cpp to store the artist name, release year, and popularity
    // in.
    // ex. bool searchBySongTitle(const string& songTitle, string& artistName, int& releaseYear, int& popularity){}
    bool searchBySongTitle(const string& songTitle);

    // same thing here just switching around song title and artistname
    // searching for artist will be a lot harder though since the trie is going to be
    // sorted by the song titles not artist. But let me know if you guys think we could do this differently.
    bool searchByArtistName(const string& artistName);


};