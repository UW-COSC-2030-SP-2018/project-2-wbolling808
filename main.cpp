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
	bool sorted = false;
	bool found = false;
	vector<int> checkVal = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	vector<int> inputTest = { 15,12,13,11,9,10,7,8,14,6,5,3,4,2,1 };
	vector<int> inputTest2 = { 15,12,13,11,9,10,7,8,14,6,5,3,4,2,1 };
	int vectorSize;
	int minVal;
	int maxVal;
	// Testing QuickSort and Binsearch
	QuickSort(inputTest);
	if (inputTest == checkVal) {
		sorted = true;
		cout << "Quick sort is funtional : " << sorted<<"\n";
	}
	else {
		cout << "Quick sort is not funtional: " << sorted<<"\n";
	}
	int tempVal = binSearch(inputTest, 12, 0 , (inputTest.size()-1));
	if (tempVal == 12) {
		found == true;
		cout << "binSearch can find: " << found<<"\n";
	}
	else {
		cout << "binSearch can't find: " << found<<"\n";
	}
	//making sure sorted is set to false at the start of next test
	sorted = false;
	//Testing mergeSort
	mergeSort(inputTest2);
	if (inputTest2 == checkVal) {
		sorted = true;
		cout << "Merge sort is funtional: " << sorted<<"\n";
	}
	else {
		cout << "Merge sort is not funtional: " << sorted<<"\n";
	}
	//end of tests

	//Vectors of different sizes and with random numbers for testing. 

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