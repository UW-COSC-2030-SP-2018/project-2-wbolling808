//William Bollinger
#include "RandomUtilities.h"
#include "SortingAlgo.h"
#include "HashFunction.h"
#include "BloomFilter.h"
//main code will go here 
#include <iostream>
#include <vector>
//#include<algorithm>// for getNums
using::vector;
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
	vector<int> checkVal = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	vector<int> inputTest = { 15,12,13,11,9,10,7,8,14,6,5,3,4,2,1,16,17,18,19,20 };
	vector<int> inputTest2 = inputTest;
	int vectorSize;
	int minVal;
	int maxVal;
	// Testing QuickSort and Binsearch
	cout << "------------------- Some short tests ------------------------------\n";
	QuickSort(inputTest);
	if (inputTest == checkVal) {
		sorted = true;
		cout << "Quick sort is funtional : " << sorted<<"\n";
	}
	else {
		cout << "Quick sort is not funtional: " << sorted<<"\n";
	}
	int indexVal = binSearch(inputTest, 12);
	if (checkVal[indexVal] == 12) {
		found == true;
		cout << "binSearch can find 12 at index: " << indexVal<<"\n";
	}
	else {
		cout << "binSearch can't find 12; lost at index : " << indexVal<<"\n";
	}
	//making sure sorted is set to false at the start of next test
	sorted = false;
	//Testing mergeSort
	vector <int> tempTest=mergeSort(inputTest2);
	if (tempTest == checkVal) {
		sorted = true;
		cout << "Merge sort is funtional: " << sorted<<"\n";
	}
	else {
		cout << "Merge sort is not funtional: " << sorted<<"\n";
		//quick print to show how not sorted it is
		for (int n : tempTest) 
			cout << n << " ";
		cout << "\n \n";
	}
	//end of testing of binsearch quicksort and 
	
	cout << "-----------------------Variable Vector Size ------------------------------------"<<endl;
	cout << "vector will be used to fill BloomFilter Hashmap" << endl << endl;
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
	cout << "Vector of Variable Size sorted with QuickSort: \n";
	print(temp);
	cout << "\n \n \n";
	cout << "The Vector of Variable Size Hashed with DJB Hash: \n";
	print(tempHashed);
	cout << "\n";
	// Hashing Vectors of variable size end

	//BloomFilter Stuff
	BloomFilter testBloom;
	
	for (int i = 0; i < temp.size() - 1; i++) {
		testBloom.insert(std::to_string(temp[i]));
	}
	cout << "------------------------Printing Table------------------------ \n";
	testBloom.printTable();
	//Vectors of different sizes and with random numbers for testing. 
	system("pause");
};