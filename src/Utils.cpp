#include <iostream>
#include <fstream>
#include <string>
#include "Utils.hpp"
#include <iomanip>

using namespace std;
bool Extract_Data(const string& file_name, double& S,unsigned int& n, double*& w, double*& r) {
    ifstream file(file_name);
    string g;
    size_t pos;
    getline(file, g);
    S = stod(g.erase(0, 2));
    getline(file, g);
    n = stoi(g.erase(0, 2));
    getline(file, g);
    w = new double[n];
    r = new double[n];
    for (unsigned int i = 0; i < n; i++) {
        getline(file, g);
        pos = g.find(";");
        r[i] = stod(g.substr(pos +1 , g.length() - 1));
        g.erase(pos, g.length() - 1);
        w[i] = stod(g);
    }
    file.close();
    return true;
}

double Final_Portfolio_Value(const double& S, const unsigned int& n, const double* const& w, const double* const& r) {
        double V;
        for (unsigned int i = 0; i < n; i++) {
            V += S * w[i] * (r[i] + 1);
        }
        return V;
    }
bool  Write_Output(const string& file_name, const double& S, const unsigned int& n, const double* const& w, const double* const& r, const double& V)
    { 
    
        ofstream outfile;
        outfile.open(file_name);
    
        
        outfile << fixed << setprecision(2) ;
        outfile << "S = "<< S  <<", n = " << n << endl;
        outfile << defaultfloat << setprecision(6);   
        outfile << "w = [ " ;
        for (unsigned int i = 0; i < n; i++){
            outfile << w[i] << " ";
        }
        outfile << "]" << endl;
        outfile << "r = [ " ;
        for (unsigned int i = 0; i < n; i++){
            outfile << r[i] << " ";
        }
        outfile << "]" << endl;
    
        outfile << "Rate of return of the portfolio: " << (V-S)/S << endl;
    
        outfile << fixed << setprecision(2) << "V: "<< V << endl;
    
        outfile.close();
    
        return true;
    }
    
