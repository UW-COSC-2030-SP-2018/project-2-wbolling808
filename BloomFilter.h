#pragma once
#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#define TABLE_SIZE 8285

#include<string>
using std::string;

class BloomFilter
{
public:
	BloomFilter();
	~BloomFilter();

	void insert(string s);
	bool contains(string s) const;
	void printTable();

private:
	int table[TABLE_SIZE] = { 0 };
};

#endif