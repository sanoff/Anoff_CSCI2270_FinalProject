#include<iostream>
#include<fstream>

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

void HashTable::printInventory()
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
		if (hashTable[i]->next != nullptr)	//I wanted to do this after the initial cout because I don't want to allocate from the heap in the majority of cases.
		{
			Movie* temp = hashTable[i]->next;
			while (temp != nullptr)			//traverse the linked list
			{
				std::cout << temp->title << ":" << temp->year << std::endl;
				temp = temp->next;
			}
		}
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
//Precondition for Delete movie: Movie is a valid string and exists in the hash table.
//This function prompts the user for a movie name which then has its memory cleared up in the hash table if it exists there.
void HashTable::deleteMovie(std::string& in_title)
{

	int key = get_hash_key(in_title);

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

	while (del == nullptr)
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
