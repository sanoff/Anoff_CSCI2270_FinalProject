#include<iostream>
#include<string>
#include<fstream>

#include"HashTable.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(int argc, char* argv[])
{
	HashTable* hash = new HashTable();

	std::ifstream in_file;	//might actually be useless.
    in_file.open(argv[1]);
	if (in_file.is_open())
	{
		int year;
		string title, buffer;
		while (!in_file.eof())
		{
			getline(in_file, buffer, ',');	//rating - ditch
			getline(in_file, buffer, ',');
			title = buffer;
			getline(in_file, buffer, ',');
			year = stoi(buffer);
			getline(in_file, buffer);		//quantity - ditch

			hash->insertMovie(title, year);
		}
	}
	else
	{
		//nothing for now.
	}

	int select = 0;

	while (select < 5)
	{

		cout << "======Main Menu======" << endl
			<< "1. Insert movie" << endl
			<< "2. Delete movie" << endl
			<< "3. Find movie" << endl
			<< "4. Print table contents" << endl
			//<< "5. Copy a file's contents" << endl
			<< "5. Quit" << endl;

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

		if (select == 5)	//Quit
			cout << "Goodbye!" << endl;
		if (select > 5)
			cout << "---That was not an option.---\n\n";
	}

	return 0;
}
