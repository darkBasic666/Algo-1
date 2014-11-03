#include "sorting.h"
#include <vector>
#include <algorithm>

void swapear(int& a , int& b){
	int aux = a;
	a = b;
	b = aux;
}

bool isAscSorted(const vector<int>& v){
	int i = 0;
	while ( (i < v.size() - 1) && (v.at(i) <= v.at(i + 1)) )
		i++;
	return (i >= v.size() - 1);
}

void randomSort(vector<int>& v){
	while(!isAscSorted(v))
		std::random_shuffle( v.begin(), v.end() );

}

void insertionSort(vector<int>& v){
	int i = 0;
	// Inv : 0<=i <= v.size() &&  mismos(pre(v),v) &&
	// forAll(x ← [0 .. i - 1)) v[x] <=  v[ x + 1] &&
	// forAll(x ← [i .. v.size())) v[x] == pre(v[x])
	while ( i < v.size() ){
		int j = i;
		while((j > 0) && (v.at(j) < v.at(j -1) ) ){
			swapear(v.at(j-1),v.at(j));
			j--;
		}
		i++;
	}
}
void bubbleSort(vector<int>& v){
	bool o = false;
	while (!o){
		o = true;
		for (int i = 0; i < v.size()-1; ++i){
			if (v.at(i) > v.at(i+1)){
				swapear(v.at(i),v.at(i+1));
				o = false;
			}
		}
	}

}
void selectionSort(vector<int>& v){
	int i = 0;
	// Inv : 0<=i <= v.size() &&  mismos(pre(v),v) &&
	// forAll(j ← [0 .. i - 1 )) v[j] <= v[ j + 1] && 
	// forAll(x ← [i .. v.size())) forAll(y ← [0 .. i)) v[x] >= v[y]    
	while ( i < v.size() ){
		swapear(v.at(i),v.at(minId(v,i,v.size())));
		i++;
	}
}
int minId(const vector<int>& v,int d,int h){
	int im = d;
	for (int i = d+1; i < h; ++i){
		if(v.at(im) > v.at(i))
			im = i;
	}
	return im;
}