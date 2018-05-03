#pragma once
//William Bollinger
#ifndef HashFunction_H
#define HashFunction_H
#include <string>
//pulled from lab 10 and called one of the most effecient ever published
// at http://www.partow.net/programming/hashfunctions/#RSHashFunction
unsigned int DJBHash(const std::string& str)
{
	unsigned int hash = 5381;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash = ((hash << 5) + hash) + str[i];
	}

	return hash;
}
/* End Of DJB Hash Function */

#endif // !HashFunction_H
