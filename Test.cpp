#include <fstream>
#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include "TrieTree.h"
#include "RedBlackTree.h"
#include "catch2/internal/catch_stdstreams.hpp"
using namespace std;

TEST_CASE("Test 1 - Trie", "[flag]"){
	TrieTree trieTree;
	vector<string> songs;

	// open csv file
	std::ifstream file("../resources/song_data/cleaned_data.csv");

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
		songs.push_back(songTitle);
		std::string artistName = line.substr(leftBrArtistName + 2, rightBrArtistName - leftBrArtistName - 2);

		// find the commas after the brackets to parse the release year and popularity
		int releaseYearComma = line.find(',', rightBrArtistName);
		int popularityComma = line.find(',', releaseYearComma + 1);

		// parse releaseyear and popularity using commas
		std::string releaseYear = line.substr(releaseYearComma + 1, popularityComma - releaseYearComma - 1);
		std::string popularity = line.substr(popularityComma + 1);

		// insert each metadata point into each tree
		trieTree.insert(songTitle, artistName, releaseYear, popularity);
	}

	Metadata* result = nullptr;
	bool success = false;
	chrono::duration<long long, ratio<1,1000000>> highTime{};
	for (int i = 0; i < songs.size(); i++)
	{
		auto start = chrono::steady_clock::now();
		result = trieTree.search(songs[i]);
		auto finish = chrono::steady_clock::now();
		auto elapsedTimeTrie = chrono::duration_cast<std::chrono::microseconds>(finish - start);
		if (elapsedTimeTrie > highTime)
			highTime = elapsedTimeTrie;

		if (result == nullptr)
		{
			cout << i << ": " << songs[i] << endl;
			success = false;
			break;
		}
		success = true;
	}
	cout << highTime.count() << "microseconds" << endl;
 	REQUIRE(success == true);
 }