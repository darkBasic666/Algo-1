#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <iostream>
#include <string>
#include <vector>
#include <sys/time.h>

using std::vector;
using std::string;
using std::istream;
using std::ostream;

void   init_time();
double get_time();

vector<int> readlist(istream&);
void writelist(ostream&,const vector<int>&,const double&);

vector<string> instancesFrom(const string&);

#endif  // AUXILIARES_H