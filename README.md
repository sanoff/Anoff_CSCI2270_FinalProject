# Anoff_CSCI2270_FinalProject
This is my final project for Data Structures - CSCI 2270.
Phase 1:

Project Goals:
This project seeks to expand upon the HashTable class created in Assignment 9 with additional functionality and methods. First, it will attempt to give another option on the menu, organize by year. This will change the original printinventory so that the movies hashed are listed by year, instead of alphabetically by title. Additionally, this program will have read-in functionality, meaning that the user will be able to choose an option from the main menu that will allow them to read in the information of the movies that they'd like to see from a file and organize it into a hash table, instead of solely being able to insert each movie individually. Additionally, this program will attempt to utilize a new search feature from the main menu. This search feature will look for phrases / sequences of letters throughout the list within the titles of movies and return to the user movie names and information that have similar character sequences. For instance, if the user were to type Shaw, the computer would return Shawshank Redemption as a possible search result. Additionally, the user will be able to use this same search feature to look for a movie by year, which will then return a list of movies with the make the same year as input by the user. Other additional methods will be used, including one that, once all of the NULLS in the additional array are filled, the Hash table will be rebuilt with double the number of indexes prior, and thus the methods will change accordingly to account for the new size of the array. Essentially, this project will consist of the original methods of the program with updates and greatly heightened efficiency and functionality, providing a more realistic and practical implementation of a Hash table in C++.

How to Run:
This program will have the same format that past assignments have had: It will be a compilation of the standard libraries with a few additional ones later on, and will be composed of a header file with all of the class prototype, a driver file, and a helper file that will have all of the class method definitions. Additionally, for the infile, the user can choose to compile this project with a text file of a format similar to Assignment5Movies.txt, and it will automatically create a sorted hash table. If all of the files are run together as a project (with or without a text file to read in) this program will work correctly.

System requirements:
This program is intended to be compatible with all of the different types of operating systems.
The files must be run together or else the dependencies will cause them not to work.
Project Dependencies:
This program uses code from vector, the standard library, and stringstream. An infile with this program is optional, and either way the program will function correctly.

Contributors:

Known bugs / issues: the only known "bug" here is that when read in, the names for the movies are not alphabetically sorted: However, the sorting algorithm does work for inserts, and all of the other functions work correctly.

Teammates: None.

Phase 2: Filenames
Driver File: Assignment9.cpp
Header File: HashTable.h
Class definition file: HashTable.cpp
