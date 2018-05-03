// BloomFilter.cpp
//William Bollinger
#include "BloomFilter.h"
#include<iostream>
using std::cout;
using std::endl;
//Found a lot of this code scattered around the internet and am attempting to pull it together. 

// constructor for bloomfilter, sets table to all zeros
BloomFilter::BloomFilter() {}

// deconstructor 
BloomFilter::~BloomFilter() {}

// the insert function
void BloomFilter::insert(string s)
{
	int hash = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		hash = ((hash + s.at(i)) << 5) % TABLE_SIZE;
	}
	table[hash] = 1;

	// JSHash from lab10 found in GeneralHashFunctions.cpp
	//table size modulo allows me to use this function for my purposes
	unsigned int hash1 = 1315423911 % TABLE_SIZE;
	for (std::size_t i = 0; i < s.length(); i++)
	{
		hash1 ^= ((hash1 << 5) + s[i] + (hash1 >> 2)) % TABLE_SIZE;
	}
	table[hash1] = 1;

	// SDBMHash 
	unsigned int hash2 = 0;
	for (std::size_t i = 0; i < s.length(); i++)
	{
		hash2 = (s[i] + (hash2 << 6) + (hash2 << 16) - hash2) % TABLE_SIZE;
	}
	table[hash2] = 1;
}

bool BloomFilter::contains(string s) const
{
	bool found = false;
	int hash = 0;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		hash = ((hash + s.at(i)) << 5) % TABLE_SIZE;
	}


	// JSHash 
	unsigned int hash1 = 1315423911 % TABLE_SIZE;
	for (std::size_t i = 0; i < s.length(); i++)
	{
		hash1 ^= ((hash1 << 5) + s[i] + (hash1 >> 2)) % TABLE_SIZE;
	}

	// SDBMHash
	unsigned int hash2 = 0;
	for (std::size_t i = 0; i < s.length(); i++)
	{
		hash2 = (s[i] + (hash2 << 6) + (hash2 << 16) - hash2) % TABLE_SIZE;
	}
	if (table[hash] && table[hash1] && table[hash2])
		found = true;

	return found;
}

//iterates through entire table and prints out the table if element is not zero
void BloomFilter::printTable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i] != 0)
		{
			cout << i << " " << table[i] << endl;
		}

	}
}