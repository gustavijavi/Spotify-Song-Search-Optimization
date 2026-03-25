cmake_minimum_required(VERSION 3.26)
project(SpotifySongSearch)

set(CMAKE_CXX_STANDARD 17)

add_executable(SpotifySongSearch
        src/Main.cpp
        src/RedBlackTree.cpp
        src/TrieTree.cpp
)

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.0
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests
        Test.cpp
        src/RedBlackTree.cpp
        src/TrieTree.cpp

)
target_include_directories(tests PRIVATE src)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)