cmake_minimum_required(VERSION 3.26)
project(Levenshtein)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_HEADERS
    cards.h
    fileOperations.h
    levenshteinDistance.h
)

set(PROJECT_SOURCES
    Main.cpp
    cards.cpp
    fileOperations.cpp
    levenshteinDistance.cpp
)
add_executable(Levenshtein ${PROJECT_SOURCES} ${PROJECT_HEADERS})
