#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>

#include "auxiliares.h"
#include "sorting.h"

using namespace std;

int main(int argc, char** argv){
    string infile(argv[1]);
    string outfile(argv[2]);

    ifstream in(infile.c_str());
    vector<int> aList= readlist(in);

    init_time();
    //randomSort(aList); 
    //no correr con test!

    //bubbleSort(aList);
    // insertionSort(aList);
    selectionSort(aList);
    double t= get_time();

    ofstream out(outfile.c_str());
    writelist(out,aList,t);
    out.close();
    
	return 0;
}