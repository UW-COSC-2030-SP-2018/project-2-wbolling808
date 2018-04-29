#pragma once
//William Bollinger Project 2 sort algorithms
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
void QuickSort(vector<double>& vec1)
{
	QuickSortImpl(vec1.begin(), vec1.end());
}
//Binary search  Nathan epstein 
//https://gist.github.com/NathanEpstein/9f5872c6452ba15cde9d
//get the index of a target integer from a sorted vector
int binSearch(const vector<int>& sorted, const int target) {
	const int mid = floor(sorted.size() / 2);

	if (sorted[mid] == target) {
		//return if it matches
		return mid;
	}
	else if (sorted[mid] > target) {
		//search left
		const vector<int> left(sorted.begin(), sorted.begin() + mid);
		return binSearch(left, target);
	}
	else {
		//search right
		const vector<int> right(sorted.begin() + mid, sorted.end());
		return (mid + binSearch(right, target));
	}
}


//Merge & Merge Sort Nathan epstein 
//https://gist.github.com/NathanEpstein/9f5872c6452ba15cde9d
//MERGE SORT IMPLEMENTATION
// merge function
vector<double> merge(vector<double> left, vector<double> right) {
	int leftCount = 0;
	int rightCount = 0;

	vector<double> results;

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
vector<double> mergeSort(vector<double> arr) {
	if (arr.size() <= 1) {
		return arr;
	}
	int len = floor(arr.size() / 2);
	vector<double> left(arr.begin(), arr.begin() + len);
	vector<double> right(arr.begin() + len, arr.end());

	return merge(mergeSort(left), mergeSort(right));
}