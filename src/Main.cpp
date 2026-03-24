// including libraries used
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

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
        int leftBrArtistName = line.find("['");
        int rightBrArtistName = line.find("']");

        // in case of a weird artist name in the data set, skip it
        if(leftBrArtistName == std::string::npos || rightBrArtistName == std::string::npos){
            continue;
        }

        // parse the song title and artist name list from the bracket locations
        std::string songTitle = line.substr(0, leftBrArtistName - 1);
        std::string artistName = line.substr(leftBrArtistName + 2, rightBrArtistName - leftBrArtistName - 2);

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

    // setting times for the thread to sleep for to make text easier to read
    auto longPauseTime = std::chrono::milliseconds(1500);
    auto shortPauseTime = std::chrono::milliseconds(750);

    // welcome message
    std::cout << std::endl << "Welcome to the Spotify Song Search!" << std::endl;
    std::this_thread::sleep_for(longPauseTime);

    // whole program will reiterate until user inputs for an exit
    while(true) {

        // printing options for user and prompting for input with pause times to make it easier to read
        std::cout << std::endl << "---------------------------------------------------" << std::endl; 
        std::this_thread::sleep_for(shortPauseTime);
        std::cout << "1. Search for song\t2. Insert your own song" << std::endl;
        std::this_thread::sleep_for(shortPauseTime);
        std::cout << "3. Exit" << std::endl;
        std::this_thread::sleep_for(shortPauseTime);
        std::cout << "---------------------------------------------------" << std::endl << std::endl;
        std::this_thread::sleep_for(shortPauseTime);
        std::cout << "What would you like to do? (Select from above): ";

        std::string input = "";

        // grabbing input from user
        std::getline(std::cin, input);

        std::cout << std::endl;

        // if else statements for each option, chosen based off of what user picks
        if(input == "1"){

            while(true) {

                std::this_thread::sleep_for(shortPauseTime);

                // Prompting the user for the song title and how to quit from searching
                std::cout << "(Enter 'menu' to go back to the menu)" << std::endl;
                std::cout << "Enter song title: ";
                std::getline(std::cin, input);

                if(input == "menu"){
                    break;
                }

                std::cout << std::endl;

                // Finding the time it takes to search for the song within the Red Black Tree
                auto start = std::chrono::steady_clock::now();
                Metadata* resultRB = redBlackTree.search(input);
                auto finish = std::chrono::steady_clock::now();
                auto elapsedTimeRB = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
                
                // Finding the time it takes to search for the song within the Trie Tree
                start = std::chrono::steady_clock::now();
                Metadata* resultTrie = trieTree.search(input);
                finish = std::chrono::steady_clock::now();
                auto elapsedTimeTrie = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);

                
                // If either of the trees return a nullptr, it will print to the user that the song was not found.
                if(resultRB != nullptr && resultTrie != nullptr){
                    std::this_thread::sleep_for(shortPauseTime);

                    // print elapsed time for each tree in the terminal
                    std::cout << "Red Black Tree: Found in " << elapsedTimeRB.count() << " microseconds" << std::endl;
                    std::this_thread::sleep_for(shortPauseTime);

                    std::cout << "Trie Tree: Found in " << elapsedTimeTrie.count() << " microseconds" << std::endl;
                    std::this_thread::sleep_for(shortPauseTime);

                    // give metadata from the song that was searched for
                    std::cout << "Artist(s): " << resultTrie->_artistName << " | Release Year: " << resultTrie->_releaseYear << " | Popularity Score: " << resultTrie->_popularity << std::endl << std::endl;
                    std::this_thread::sleep_for(shortPauseTime);
                    std::cout << "Press Enter to continue...";
                    std::cin.get();
                    std::cout << std::endl;
                } else {
                    std::cout << "Song not found, please try again" << std::endl << std::endl;
                }
            }

        } else if(input == "2"){

            std::this_thread::sleep_for(shortPauseTime);
            
            std::string songTitleInsert = "";
            std::string artistNameInsert = "";
            std::string releaseYearInsert = "";
            std::string popularityInsert = "";

            // Prompting the user for the song title to insert
            std::cout << "Enter song title: ";
            std::getline(std::cin, songTitleInsert);

            std::this_thread::sleep_for(shortPauseTime);

            // Prompting the user for the artist names(s) to insert
            std::cout << "Enter artist name(s) for song: ";
            std::getline(std::cin, artistNameInsert);

            std::this_thread::sleep_for(shortPauseTime);

            // Prompting the user for the release year to insert
            std::cout << "Enter release year of song: ";
            std::getline(std::cin, releaseYearInsert);

            std::this_thread::sleep_for(shortPauseTime);

            // Prompting the user for the popularity of the song to insert
            std::cout << "Enter song popularity (0-100): ";
            std::getline(std::cin, popularityInsert);
            std::cout << std::endl;

            redBlackTree.insert(songTitleInsert, artistNameInsert, releaseYearInsert, popularityInsert);
            trieTree.insert(songTitleInsert, artistNameInsert, releaseYearInsert, popularityInsert);

            std::this_thread::sleep_for(shortPauseTime);

            std::cout << "Song successfully inserted into both the Red Black and Trie Tree!" << std::endl;


        } else if(input == "3"){
            break;
        } else {
            std::cout << "Invalid response, try again" << std::endl;
        }
    }

    return 0;
}