// including libraries used
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

// including header files
#include "RedBlackTree.h"
#include "TrieTree.h"

// beginning of program
int main(){

    // initializing trees to be used
    RedBlackTree redBlackTree;
    TrieTree trieTree;

    // open csv file
    std::ifstream file("resources/song_data/cleaned_data.csv");

    // intitialize string for the line to be parsed
    std::string line;

    // get past first line in the csv file
    std::getline(file, line);

    // loop through each line of the csv file to insert into both trees
    while(std::getline(file, line)){
        
        // to parse, we find the brackets that encapsulate the artist names because they may contain commas which makes it difficult to
        // parse with just commas alone
        int leftBrArtistName = line.find('[');
        int rightBrArtistName = line.find(']');

        // parse the song title and artist name list from the bracket locations
        std::string songTitle = line.substr(0, leftBrArtistName - 1);
        std::string artistName = line.substr(leftBrArtistName, rightBrArtistName - leftBrArtistName + 1);

        // find the commas after the brackets to parse the release year and popularity
        int releaseYearComma = line.find(',', rightBrArtistName);
        int popularityComma = line.find(',', releaseYearComma + 1);

        // parse releaseyear and popularity using commas
        std::string releaseYear = line.substr(releaseYearComma + 1, popularityComma - releaseYearComma - 1);
        std::string popularity = line.substr(popularityComma + 1);

        // insert each metadata point into each tree
        redBlackTree.insert(songTitle, artistName, releaseYear, popularity);
        trieTree.insert(songTitle, artistName, releaseYear, popularity);
    }

    // welcome message
    std::cout << std::endl << "Welcome to the Spotify Song Search!" << std::endl;

    // whole program will reiterate until user inputs for an exit
    while(true) {

        // printing options for user and prompting for input
        std::cout << std::endl << "---------------------------------------------------" << std::endl << "1. Search for song\t2. Insert your own song" << std::endl << "3. Exit" << std::endl << "---------------------------------------------------" << std::endl << std::endl;
        std::cout << "What would you like to do? (Select from above): ";

        std::string input = "";

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