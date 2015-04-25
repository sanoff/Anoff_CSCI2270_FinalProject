#ifndef HASHTABLE_H
#define HASHTABLE_H
#define H_TABLE_SIZE 10
#include<string>
#include<vector>

struct Movie
{
    std::string title;
    int year;
	int index;
    Movie* next;

    Movie()
	{
		title = " ";
		year = -1;
		index = -1;
		next = nullptr;
	};

    Movie(std::string& in_title, int& in_year)
    {
        title = in_title;
        year = in_year;
		index = -1;
		next = nullptr;
	};

	Movie(std::string& in_title, int& in_year, int& in_index)
	{
		title = in_title;
		year = in_year;
		index = in_index;
		next = nullptr;
	};

};

class HashTable
{
public:
	HashTable();
	HashTable(int&);
	~HashTable();

	void printInventory(); // Has been modified to also allow for the new sorting algorithm
	void insertMovie(std::string&, int&);					//title, year // Modified for the infile
	void deleteMovie(std::string&);							//title // Modified for the new sorting algorithm
	void collision_resolution(std::string&, int&, int&);	//title, year, key //Linked list is converted into a vector for the new print.
	Movie* findMovie(std::string&);							//title //Has changed functionality for the search function.
	//void addfile(ifstream& in_file); //This function is a method initiated at the beginning of the program.
	void sortMovie(std::vector<Movie*> collisions);
	Movie* sizeDouble();
	void searchMovie(std::string title);
	void printYears();
	bool isFull();
	unsigned int get_size();
	bool is_empty();

private:
	int get_hash_key(std::string&);
	int size;
	Movie** hashTable;

};

#endif // HASHTABLE_H
