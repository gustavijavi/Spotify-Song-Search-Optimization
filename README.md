<h1> COP3530 - Project 2 </h1> 

<ins> **Spotify Song Search Optimization using a Red-Black and a Trie Tree** </ins>

This project, created by Javier Coll-Roman, Matthew Kilroy, and Jayesh Agarwal, delves into the efficiencies of the search functions for both Red-Black and Trie trees. Through insertion of 100k+ datapoints into both tree structures, we see the time it takes to search for any song inputted by the user as well as give the capability for the user to add their own song as well.

Once you run our program, you'll be brought through an intuitive design that asks you to choose from menu options to either **search**, **insert**, or **exit**: 
- **Search:** If you choose to **search**, input any song you like, it may just be in the dataset! If it isn't, try searching for a song that you know is more popular from artists such as Michael Jackson, Katy Perry, Frank Sinatra, etc. After a successful search, useful metadata for the song will be outputted including the artist(s), release year, and popularity of the song on a scale from 0 to 100.
- **Insert:** Our insert option allows you to add your own song into the mix of our data where you'll be able to add a song title, artist name(s), release year, and popularity score. After inserting, try searching for it! It'll most definitely pop up unless your song title overlaps with an already existing song (try making it unique).
- **Exit:** Once all is said and done, go ahead and choose the option to exit to fully close the program.

<br>

<h2> Table of Contents </h2>

- [Getting Started](#getting-started)
- [Creating and Running Main Executable](#creating-and-running-main-executable)
- [Final Remarks](#final-remarks)

## Getting Started

To download this project to try for yourself, you must have git installed to do so. Download git [here](https://git-scm.com).

In the terminal, within your preferred compiler for C++ programs, set the working directory to wherever you'd like the program in your computer.

```
cd (filepath here)
```
Example:
```
cd "/Users/javiercoll-roman/Documents/DSA"
```

Then, clone the repository using
```
git clone https://github.com/gustavijavi/Spotify-Song-Search-Optimization.git
```

<br>

## Creating and Running Main Executable

**This project requires g++ to compile.**

- **Mac:** Install Xcode Command Line Tools by running `xcode-select --install` in your terminal.
- **Linux:** Run `sudo apt install g++`
- **Windows:** Install MinGW

You will not need to install or download any datasets as it is already provided within the resources folder.

Make sure that your working directory is set to the repository you just cloned. Do not move the working directory to the source folder or the resources folder.

Within your terminal, now enter (C++17 is required for this project)
```
g++ -std=c++17 -o main src/Main.cpp src/RedBlackTree.cpp src/TrieTree.cpp
```

To run the program, enter
```
./main
```

<br>

## Final Remarks

**Congratulations!**

You now have our program running on your system. Feel free to look through our code and see just how it utilizes each tree and checks the time taken to search within each tree as well.

Credits:
- Javier Coll-Roman (Main.cpp, README.md) - [GitHub Profile](https://github.com/gustavijavi)
- Matthew Kilroy (TrieTree.h, TrieTree.cpp) - [GitHub Profile](https://github.com/mbkilroy83)
- Jayesh Agarwal (RedBlackTree.h, RedBlackTree.cpp) - [GitHub Profile](https://github.com/jayesh100100)
