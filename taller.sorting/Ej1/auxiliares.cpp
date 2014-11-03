#include "auxiliares.h"

using namespace std;

timeval start,end_time;

void init_time(){
    gettimeofday(&start,NULL);
}

double get_time(){
    gettimeofday(&end_time,NULL);
    return (1000000*(end_time.tv_sec-start.tv_sec)+(end_time.tv_usec-start.tv_usec))/1000000.0;
}

vector<int> readlist(istream& in){
    int N;
    in >> N;
    vector<int> xs(N,0);
    for(int i=0; i<N; i++) in >> xs[i];
    return xs;
}

void writelist(ostream& out, const vector<int>& xs, const double& t){
    out << t << "secs." << endl;
    out << xs.size() << endl;
    for(int i=0; i<xs.size(); i++) out << xs[i] << " ";
}