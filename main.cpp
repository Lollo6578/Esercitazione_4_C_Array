#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "src/Utils.hpp"

using namespace std;

int main()
{
    string nome_file_input = "./data.txt";
    double S = 0;
    unsigned int n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double V = 0;
    if (!Extract_Data(nome_file_input, S, n, w, r))
    {
        cerr << "errore nella lettura del file" << endl;
        return -1;
    }
    
    

    V = Final_Portfolio_Value(S, n, w, r);
    string nome_file_output = "./result.txt";   
    if (!Write_Output(nome_file_output, S, n, w, r, V))
    {
        cerr << " errore nella scrittura dei risultati" << endl;
        return -1;
    }
    
    delete[] w;
    delete[] r;
    return 0;
}

