//
// Created by alex on 05/06/22.
//
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
    while ( getline (myfile,line) )
    {
    cout << line << '\n';
    }
    myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}