#pragma once
#include <iostream>

using namespace std;
bool Extract_Data(const string& file_name, double& S, unsigned int& n, double*& w, double*& r);


double Final_Portfolio_Value(const double& S, const unsigned int& n, const double* const& w, const double* const& r);



bool Write_Output(const string& file_name, const double& S, const unsigned int& n, const double* const& w, const double* const& r, const double& V);


