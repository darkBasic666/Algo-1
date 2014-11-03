#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <algorithm>

using std::vector;

void randomSort(vector<int>&);

void bubbleSort(vector<int>&);
void insertionSort(vector<int>&);
void selectionSort(vector<int>&);
void swapear(int& ,int& );
int minId(const vector<int>&,int,int);
bool isAscSorted(const vector<int>&);

#endif  // SORTING_H