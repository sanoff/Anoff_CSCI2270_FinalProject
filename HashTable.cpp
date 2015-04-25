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
        std::vector<Movie*> collisions;
        if(hashTable[i]->year != NULL)
        {
            Movie * temp = hashTable[i];
            while(temp != NULL)
            {
                collisions.push_back(temp);
                temp = temp->next;
            }
            sortMovie(collisions);
        }
        if(hashTable[i]->title == "")
        {
            std::cout << "The table is empty." << std::endl;
            return;
        }
    }
}
Movie * HashTable::sizeDouble()
{

}

void HashTable::printYears()
{

}
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
//Pre-Condition - This movie has to exist in the array, or else the search will fail. The user must input a string for the program to search for. The program only works
//If the search condition is at the beginning of the movie title. For instance, Shaw will return Shawshank redemption, but Redemption will not.
//Post-condition - No actual changes are made to the array here.
void HashTable::searchMovie(std::string title)
{
std::string searchedFor;
Movie ** tempTable = hashTable;
std::cout << hashTable[1]->title[0] <<hashTable[1]->title[1] <<  std::endl;
int year;
int length = title.length();
for(int i = 0; i < 10; i++)
{

}
std::cout << "Were you looking for " << searchedFor << " made in " << year << "?" << std::endl;
}
//An alternative sorting algorithm that sorts movies by using vectors.
//Precondition: The array must already be built with at least n number of values to sort them into an array.
//post-condition: The values in the array are spit back out using a vector in an attempt to alphabetize them.
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
//Pre condition: There aren't any preconditions for this, the user simply has to input a year and a title.
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
//Precondition for Delete movie: Movie is a valid string and exists in the hash table.
//This function prompts the user for a movie name which then has its memory cleared up in the hash table if it exists there.
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
//Pre-condition: User has to input a valid string name for the title, and the movie has to exist within the array.
//Post condition - Nothing happens, a cout is simply returned to the user.
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

unsigned int HashTable::get_size()
{
	return size;
}

bool HashTable::is_empty()
{
	if (size > 0)
		return false;
	return true;
}

int HashTable::get_hash_key(std::string& in_title)
{
	int sum = 0;
	for (std::string::iterator it = in_title.begin(); it != in_title.end(); it++)
		sum += *it;	//sum ASCII

	return (sum % H_TABLE_SIZE);
}
