//William Bollinger
#include "RandomUtilities.h"
#include "SortingAlgo.h"
#include "HashFunction.h"
//main code will go here 
#include <iostream>
#include <vector>
#include<algorithm>
using::vector;
using::cin;
using::cout;
using namespace::std;

vector<int> getNums(size_t listSize, int minNum, int maxNum)
{
	vector<int> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randInt(minNum, maxNum));
	}
	return theList;
}

void print(const vector<int>& invec)
{
	for (int i = 0; i < invec.size(); i++)
	{
		cout << invec[i] << "  ";
	}
}

int main() {
	vector<int> temp;
	vector<int> tempHashed;
	int vectorSize;
	int minVal;
	int maxVal;
	cout << "Enter the desired size of the vector: ";
	cin >> vectorSize;
	if (cin.fail()) {
		cout << "Enter the desired size as an INTEGER: ";
	}
	do {
		cout << "Enter the Min Val of the data set: ";
		cin >> minVal;
		if (cin.fail()) {
			cout << "Enter the minVal as an INTEGER: ";
			cin >> minVal;
		}
		cout << "Enter the Max Val of the data set: ";
		cin >> maxVal;
		if (cin.fail()) {
			cout << "Enter the maxVal as an INTEGER: ";
			cin >> maxVal;
		}
		if (minVal > maxVal) {
			cout << "it would seem your min is larger than your max, lets try again. \n"; 
		}
	} while (minVal > maxVal); 
	temp = getNums(vectorSize, minVal, maxVal);
	QuickSort(temp);
	for (int i = 0; i < vectorSize; i++) {
		tempHashed.push_back(DJBHash(std::to_string(temp[i])));
	}
	print(temp);
	cout << "\n \n \n";
	print(tempHashed);
	cout << "\n";
	system("pause");
};