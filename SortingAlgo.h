#pragma once
//William Bollinger Project 2 sort algorithms
#ifndef SortingAlgo_H
#define SortingAlgo_H


#include<vector>
#include<algorithm>
#include<iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
//Quick Sort pulled from lab07
template<class FwdIt, class Compare = std::less<>>
void QuickSortImpl(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
	auto const N = std::distance(first, last);
	if (N <= 1) return;
	auto const pivot = *std::next(first, N / 2);
	auto const middle1 = std::partition(first, last, [=](auto const& elem) {
		return cmp(elem, pivot);
	});
	auto const middle2 = std::partition(middle1, last, [=](auto const& elem) {
		return !cmp(pivot, elem);
	});
	QuickSortImpl(first, middle1, cmp);
	QuickSortImpl(middle2, last, cmp);
}

//quick sort recursion
void QuickSort(vector<int>& vec1)
{
	QuickSortImpl(vec1.begin(), vec1.end());
}
//Binary search  Nathan epstein 
//https://gist.github.com/NathanEpstein/9f5872c6452ba15cde9d
//get the index of a target integer from a sorted vector


//int binSearch(const vector<int>& sorted, const int target) {
//	const int mid = (sorted.size() / 2);
//
//	if (sorted[mid] == target) {
//		//return if it matches
//		return mid;
//	}
//	else if (sorted[mid] > target) {
//		//search left
//		const vector<int> left(sorted.begin(), sorted.begin() + mid);
//		return binSearch(left, target);
//	}
//	else {
//		//search right
//		const vector<int> right(sorted.begin() + mid, sorted.end());
//		return (mid + binSearch(right, target));
//	}
//either returns val or -1
int binSearch(vector<int> input, int key, int left, int right)
{
	if (right >= left)
	{
		int middle = (left + right) / 2;
		if (input[middle] == key) return middle;
		if (input[middle] > key) return binSearch(input, key, left, middle - 1);
		return binSearch(input, key, middle + 1, right);
	}
	return -1;
}
// end of binarysearch


//Merge & Merge Sort Nathan epstein 
//https://gist.github.com/NathanEpstein/9f5872c6452ba15cde9d
//MERGE SORT IMPLEMENTATION
// merge function
vector<int> merge(vector<int> left, vector<int> right) {
	int leftCount = 0;
	int rightCount = 0;

	vector<int> results;

	bool useLeft;
	for (int i = 0; i<left.size() + right.size(); i++) {
		if (leftCount<left.size()) {
			if (rightCount<right.size()) {
				useLeft = (left[leftCount] < right[rightCount]);
			}
			else {
				useLeft = true;
			}
		}
		else {
			useLeft = false;
		}

		if (useLeft) {
			results.push_back(left[leftCount]);
			if (leftCount < left.size()) {
				leftCount++;
			}
		}
		else {
			results.push_back(right[rightCount]);
			if (rightCount<right.size()) {
				rightCount++;
			}
		}
	}
	return results;
}

// merge sort function
vector<int> mergeSort(vector<int> arr) {
	if (arr.size() <= 1) {
		return arr;
	}
	int len = floor(arr.size() / 2);
	vector<int> left(arr.begin(), arr.begin() + len);
	vector<int> right(arr.begin() + len, arr.end());

	return merge(mergeSort(left), mergeSort(right));
}//emd of merge sort
#endif // !SortingAlgo_H