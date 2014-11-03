#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <algorithm>

#include "auxiliares.h"

using namespace std;

int main(int argc, char** argv){
    string infile(argv[1]);
    string outfile(argv[2]);

    ifstream in(infile.c_str());
    vector<string> aList= readlist(in);

    init_time();

    // Ejercicio 3
    vector<string> sortedList = sinRepetidos(sort(aList));


    double t= get_time();

    ofstream out(outfile.c_str());
    writelist(out,sortedList,t);
    out.close();

	return 0;
}
vector<string> sinRepetidos(vector<string> &v){
    vector<string> sr ;
    sr.push_back(v.at(0));
    for (int i = 0; i < v.size()- 1; ++i){
        if(v.at(i) > v.at(i + 1))
            sr.push_back(v.at(i+1));
    }
}
vector<string> sort(vector<string> &v){
    bool o = false;
    while (!o){
        o = true;
        for (int i = 0; i < v.size()-1; ++i){
            if (v.at(i) > v.at(i+1)){
                string aux = v.at(i);
                v.at(i) = v.at(i +1 );
                v.at(i +1 ) = aux;
                o = false;
            }
        }
    }
}

