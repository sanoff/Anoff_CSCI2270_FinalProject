#include<iostream>
#include<string>
#include<fstream>

#include"HashTable.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


int main(int argc, char* argv[])
{
	HashTable* hash = new HashTable();

	std::ifstream in_file;
    in_file.open(argv[1]);
	if (in_file.is_open())
	{
		int year;
		string title, buffer;
		while (!in_file.eof())
		{
			getline(in_file, buffer, ',');
			getline(in_file, buffer, ',');
			title = buffer;
			getline(in_file, buffer, ',');
			year = stoi(buffer);
			getline(in_file, buffer);

			hash->insertMovie(title, year);
		}
	}
	else
	{

	}

	int select = 0;

	while (select != 8)
	{

		cout << "======Main Menu======" << endl
			<< "1. Insert movie" << endl
			<< "2. Delete movie" << endl
			<< "3. Find movie" << endl
			<< "4. Print table contents" << endl
			<< "5. Search for a movie" << endl
			<< "6. Check for a full hash table" << endl
			//<< "5. Copy a file's contents" << endl
			<< "7. Order movies by year" << endl
			<< "8. Quit" << endl;

		cin >> select;

		if (select == 1)	//Insert Movie
		{
			std::string title;
			int year;
			cout << "Enter title:" << endl;
			cin.ignore(1000, '\n');
			getline(cin, title);
			cout << "Enter year:" << endl;
			cin >> year;
			hash->insertMovie(title, year);
		}

		if (select == 2)	//Delete Movie
		{
			std::string title;
			cout << "Enter title:" << endl;
			cin.ignore(1000, '\n');
			getline(cin, title);
				Movie* found_movie = hash->findMovie(title);
			if (found_movie == nullptr)
				cout << "Movie not found." << endl; //testing to see if the movie exists to prevent seg faults.
			else
                hash->deleteMovie(title);
		}

		if (select == 3)	//Find Movie
		{
			std::string title;
			cout << "Enter title:" << endl;
			cin.ignore(1000, '\n');
			getline(cin, title);
			Movie* found_movie = hash->findMovie(title);
			if (found_movie == nullptr)
				cout << "not found" << endl;
			else
				cout << found_movie->index << ":" << found_movie->title << ":" << found_movie->year << endl;
		}

		if (select == 4)	//Print Table of Contents
		{
			hash->printInventory();
		}
		/*if(select == 5)
        {
            string filename;
            cout << "What file would you like to read in?" << endl;
            cin >> filename;
            hash->addfile(filename);
        }
        */
        if  (select == 5)
        {
            string title;
            cout << "What does the movie you're looking for start with?" << endl;
            cin >> title;
            hash->searchMovie(title);
        }
        if(select == 6)
        {
            hash->isFull();
        }
        if(select == 7)
        {
            vector <Movie*> years = hash->printYears();

            hash->printYears(years);
        }
		if (select == 8)	//Quit
			cout << "Goodbye!" << endl;
		if (select > 8)
			cout << "---That was not an option.---\n\n";
	}

	return 0;
}
