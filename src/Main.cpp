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

    // welcome message
    std::cout << std::endl << "Welcome to the Spotify Song Search!" << std::endl;

    // whole program will reiterate until user inputs for an exit
    while(true) {

        // printing options for user and prompting for input
        std::cout << std::endl << "---------------------------------------------------" << std::endl << "1. Search for song\t2. Insert your own song" << std::endl << "3. Exit" << std::endl << "---------------------------------------------------" << std::endl << std::endl;
        std::cout << "What would you like to do? (Select from above): ";

        string input = "";

        // grabbing input from user
        std::getline(std::cin, input);

        std::cout << std::endl;

        // if else statements for each option, chosen based off of what user picks
        if(input == "1"){
            std::cout << "This is where search will happen" << std::endl;
        } else if(input == "2"){
            std::cout << "This is where user insertion will happen" << std::endl;
        } else if(input == "3"){
            break;
        } else {
            std::cout << "Invalid response, try again" << std::endl;
        }


    }

    return 0;
}