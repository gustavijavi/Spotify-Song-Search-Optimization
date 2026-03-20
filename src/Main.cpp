// including libraries used
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

// including header files
#include "RedBlackTree.h"
#include "TrieTree.h"

// beginning of program
int main(){

    // initializing trees to be used
    // RedBlackTree redBlackTree;
    // TrieTree trieTree;

    // insert songs from csv into trees here

    std::cout << std::endl << "Welcome to the Spotify Song Search!" << std::endl << std::endl << "------------------------------------------" << std::endl << std::endl;

    
    // while(true) {

    std::cout << "1. Search for song\t2. Insert your own song" << std::endl << "3. Exit" << std::endl << std::endl;
    std::cout << "What would you like to do? (Select from above): ";

    int input = 0;

    std::cin >> input;
    std::cin.ignore();



    // }

    return 0;
}