#include<iostream>
#include<fstream>
#include<vector>
#include"HashTable.h"

HashTable::HashTable()
{
	size = 0;
	hashTable = new Movie*[H_TABLE_SIZE];
	for (int i = 0; i < H_TABLE_SIZE; i++)
		hashTable[i] = nullptr;
}

HashTable::HashTable(int& table_size)
{
	size = 0;
	hashTable = new Movie*[table_size];
	for (int i = 0; i < table_size; i++)
		hashTable[i] = nullptr;
}

HashTable::~HashTable()
{
	delete[]hashTable;
}

/*void HashTable::printInventory()
{
	if (size == 0)	//nothing in dood-ma-bob
	{
		std::cout << "empty" << std::endl;	//I'm only tolerating a print in this function because it is a print function.
		return;
	}
	for (int i = 0; i < H_TABLE_SIZE; i++)
	{
		if (hashTable[i] == nullptr)
			continue;	//skip rest
		std::cout << hashTable[i]->title << ":" << hashTable[i]->year << std::endl;
		if (hashTable[i]->next != nullptr)
		{
			Movie* temp = hashTable[i]->next;
			while (temp != nullptr)
			{
				std::cout << temp->title << ":" << temp->year << std::endl;
				temp = temp->next;
			}
		}
	}
}
*/
void HashTable::printInventory()
{

    for(int i = 0; i < 10; i++)
    {
        std::vector<Movie*> collisions; //Creates a vector for sorting
        if(hashTable[i]->year != NULL)
        {
            Movie * temp = hashTable[i];
            while(temp != NULL)
            {
                collisions.push_back(temp);
                temp = temp->next;
            }
            sortMovie(collisions); //sorts dem movies.
        }
        if(hashTable[i]->title == "")
        {
            std::cout << "The table is empty." << std::endl;
            return;
        }
    }
}
//Additional functionality wanted:
//Precondition: Will input the hash table, create a new one that has double the indexes and uses a hash sum function with double the mod value.
//Post-condition: will output a filled Hash table with double the index.
Movie * HashTable::sizeDouble()
{

}
//Prototype: std::vector <Movie*> printYears();
//Pre-condition: There is no pre-condition for this method, when called, it will simply output the movies ordered by date instead of by year.
//Post-condition: No actual changes are made to the hash table here, it simply is a void function that provides couts, and uses the vector functionality to do this.
std::vector <Movie*> HashTable::printYears()
{
std::string title;
std::vector <Movie*> years; 
int year;
Movie* temp; //Holds the head so the list is not affected
int maxYear = 3000; //Temp variable for comparisons in the iterations.
for(int i = 0; i < 10; i++)
{
    temp = hashTable[i];
    while(hashTable[i]->next != NULL)
    {
        years.push_back(hashTable[i]);
        hashTable[i] = hashTable[i]->next;
    }
    years.push_back(hashTable[i]);
    hashTable[i] = temp;
}

return years; //Gives back years to plug into the overloaded function
}
//Prototype: void printYears(std::vector <Movie*> years);
//Pre-Condition: Must first run through the initial printyears function, which automatically calls this one by returning the 
//The vector parameter. Will fail if the list is empty.
//Post condition: The list itself is not affected, but the movies are output ordered by years.
void HashTable::printYears(std::vector <Movie*> years)
{


for(int k = 0; k < years.size(); k++)
{
    Movie * temp; //Holds the years variable and sets it to true for later on so that movies are not output multiple times.
    int maxYears = 3000;
    std::string tempTitle; //Holds the title to output later.
    int  counter = 0;
    int index;

    for(int i = 0; i < years.size(); i++)
    {
        if(!years[i]->found)
        {
            if(years[i]->year <= maxYears)
            {
                index = counter;
                maxYears = years[i]->year;
                tempTitle = years[i]->title;
                temp = years[i];
            }
        }
        counter++;
    }
            temp->found = true; //If it's the youngest, this variable is set to true so that it is not used again.
     std::cout << tempTitle << ":" << maxYears << std::endl;

}
    for(int l = 0; l < years.size(); l++)
    {
        years[l]->found = false; //Resets the array so that the found is false for everything so that the function can be rerun.
    }
}
//Prototype: bool isFull();
//Pre-Condition - this method checks the hash table to see if all of the indexes are full, and furthermore, if the hash table can be expanded.
//Post condition - Undecided, but functionality may be added in the allows the hash table to be doubled in size and for the hash sum function to also use a mod double the size so that
//The new indexes in the array can be filled. Otherwise, this new functionality doesn't do anything to the array.
bool HashTable::isFull()
{
int spaceChecker = 0;
for(int i = 0; i < 10; i++)
{
    if(hashTable[i] == nullptr || hashTable[i]->title == "")
    {
        spaceChecker++; //Counts the number of nulls in the array.
    }
}
if (spaceChecker == 0) //If there aren't any spaces available.
{
    std::cout << "The hash table is full" << std::endl;
    return true;
}
std::cout << "The hash table has " << spaceChecker << " spaces remaining in the array." << std::endl;
return false;
}
///Prototype: bool isFull();
//Pre-Condition - This movie has to exist in the array, or else the search will fail. The user must input a string for the program to search for. The program only works
//If the search condition is at the beginning of the movie title. For instance, Shaw will return Shawshank redemption, but Redemption will not.
//Post-condition - No actual changes are made to the array here - a temporary variable is allocated to prevent the terms in the table from actually moving.
void HashTable::searchMovie(std::string title)
{
std::string searchedFor; //The movie that is to be returned.
std::string tempCheck; //Checks for this variable
Movie*temp; //A temp variable used to cycle through the linked list.
int year;
int length = title.length();
//std::cout << (hashTable[1]->title).substr(0,length) << title << std::endl;
for(int i = 0; i < 10; i++)
{
    if((hashTable[i]->title).substr(0, length) != title)
    {
    temp = hashTable[i]; //resets this at the beginning and end of every iteration of a linked list.
        while(hashTable[i]->next != NULL)
        {
            hashTable[i] = hashTable[i]->next;
            if((hashTable[i]->title).substr(0,length) == title) //In the situation the movie is in the list.
            {
                searchedFor = hashTable[i]->title;
                year = hashTable[i]->year;
                std::cout << "Were you looking for " << searchedFor << " made in " << year << "?" << std::endl;
                return;
            }

        }
    }
    else if((hashTable[i]->title).substr(0,length) == title) //Otherwise if it's in the array looks for it.
    {
        searchedFor = hashTable[i]->title;
        year = hashTable[i]->year;
        std::cout << "Were you looking for " << searchedFor << " made in " << year << "?" << std::endl;
        return;
    }
    hashTable[i] = temp;
}
std::cout << "Movie_not_found.exe" << std::endl; //Because of the two returns, this only occurs if the movie is not found.
}
//Prototype: bool isFull();
//An alternative sorting algorithm that sorts movies by using vectors.
//Precondition: The array must already be built with at least n number of values to sort them into an array, but this method 
//Is automatically called when the movies are sorted. 
//post-condition: The values in the array are spit back out using a vector in an attempt to alphabetize them, however
//The actual linked list is not affected.
void HashTable::sortMovie(std::vector<Movie*> collisions)
{
    bool boolFlag = true;
    int intD = collisions.size();
    Movie* wordTemp;
    while(boolFlag || (intD < 1))
    {
        boolFlag = false;
        intD = (intD + 1)/2;
        for(int i = 0; i < (collisions.size()-intD); i++)
        {
            if(collisions[i + intD]->title.compare(collisions[i]->title) < 0)
            {
                wordTemp = collisions[i + intD];
                collisions[i+intD] = collisions[i];
                collisions[i] = wordTemp;
                boolFlag = true;
            }
        }
    }
    int m;
    for(int x = 0; x<collisions.size(); x++)
    {
        m = get_hash_key(collisions[x]->title);
        std::cout << collisions[x]->title << ":" << collisions[x]->year << std::endl;
    }
}
//Prototype: 	void insertMovie(std::string&, int&);	
//Pre condition: There aren't any preconditions for this, the user simply has to input a year (int) and a title (string), and a movie will
//Be input into the Hash table. Additional functionality has been added so it can be sorted into a vector later on. Will break if
//Variable types are incorrect.
//Post condition: The data input by the user is hashed and added to the hash table.
void HashTable::insertMovie(std::string& in_title, int& in_year)
{
	int key = get_hash_key(in_title); //Hashes for the key
	if (hashTable[key] != nullptr)
		collision_resolution(in_title, in_year, key); //If it goes into one of the linked lists.
	else
	{
		Movie* temp = new Movie(in_title, in_year, key); //Otherwise creates a new index in the array.
		hashTable[key] = temp;
	}
	size++;
}
//Pre-Condition: this file must exist in the directory in which you are searching, but the file can be read in to the library like any normal infile, except from the main menu.
/*void HashTable::addfile(ifstream& in_file)
{
    in_file.open(in_file);
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
	in_file.close();
}
*/
//Prototype: 	void insertMovie(std::string&, int&);	
//Precondition for Delete movie: Movie is a valid string and exists in the hash table. If the movie is not a valid string, not found will be output.
//PostCondition: This function prompts the user for a movie name which then has its memory cleared up in the hash table if it exists there. 
//The user will have to readd the movie to be able to call it again.
void HashTable::deleteMovie(std::string& in_title)
{

	int key = get_hash_key(in_title);
	if(in_title == "all")
    {
        for(int i = 0; i < 10; i++)
        {
            hashTable[i]->title = "";
            hashTable[i]->year = 0;
        }
        std::cout << "Table has been cleared." << std::endl; // Clears out the entirety of the table.
        return;
    }

	if (hashTable[key]->title == in_title && hashTable[key]->next == nullptr) //If it's the only entry at that point.
	{
		delete hashTable[key];
		hashTable[key] = nullptr;
		size--;
		return;
	}

	Movie* it = hashTable[key];
	Movie* prev = it; //New pointers for the linked list at collisions.
	Movie* del = nullptr;

	while (del == nullptr) //Deals with the linked list situation.
	{
		if (it->title == in_title)
		{
			del = it;
			prev->next = del->next;
			delete del;
			size--;
			return;
		}
		prev = it;
		it = it->next;
	}

	size--;
}
//Pre-Condition: This method is called automatically when inserts and print inventories are called to resolve the algorithms. They require a string,
//title, and key all pointed to.
//Post-condition: This method will create linked lists at the indexes that have collisions.
void HashTable::collision_resolution(std::string& in_title, int& in_year, int& key)
{
	Movie* new_movie = new Movie(in_title, in_year, key);
	Movie* it = hashTable[key];
	Movie* prev = it;
	if (new_movie->title.compare(hashTable[key]->title) < 0)	//if it is before the first entry...
	{
		new_movie->next = hashTable[key];
		hashTable[key]= new_movie;
		return;
	}
	it = it->next;
	while (it != nullptr)
	{
		if (new_movie->title.compare(it->title) < 0)
		{
			new_movie->next = it;
			prev->next = new_movie;
			return;
		}
		prev = it;
		it = it->next;
	}
	prev->next = new_movie;	//if it has not returned yet, make it the last of the chain
}
//Prototype: void insertMovie(std::string&, int&);	
//Pre-condition: User has to input a valid string name for the title, and the movie has to exist within the array.
//Post condition - Nothing happens, a cout is simply returned to the user with the data of the movie.
Movie* HashTable::findMovie(std::string& in_title)
{
	int key = get_hash_key(in_title);
									//case 1
	if (hashTable[key] == nullptr)	//if there is no movie in the index, nothing there, return nullptr for main() to handle
		return nullptr;
	Movie* ans = hashTable[key];	//else handle case 2 & 3
	if (hashTable[key]->title != in_title)
		while ((ans != nullptr) && (ans->title != in_title))	//also takes care of the case where the index is taken, but the movie does not exist
			ans = ans->next;

	return ans;	//at this point, ans either holds the answer the function call came for, or nullptr, which is the default case for not found
}

//Returns the size of the hash table - getter function.
unsigned int HashTable::get_size()
{
	return size;
}
//Simply checks if the hash table is empty or nah - Getter function.
bool HashTable::is_empty()
{
	if (size > 0)
		return false;
	return true;
}
//Creates a hash sum, called in many different functions.
//Prototype: int get_hash_key(std::string&);
//Pre-condition: Has to be a valid title or this program will not work.
//Postcondition: Not called directly, but this hashsum causes the movie to be placed in the array.
int HashTable::get_hash_key(std::string& in_title)
{
	int sum = 0;
	for (std::string::iterator it = in_title.begin(); it != in_title.end(); it++)
		sum += *it;	//sum ASCII

	return (sum % H_TABLE_SIZE);
}
