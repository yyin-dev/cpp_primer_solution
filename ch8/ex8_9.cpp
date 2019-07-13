#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string players = "Kobe Lebron Westbrook";
    istringstream iss(players);

    string word;
    while(iss >> word){
        cout << word << endl;
    } 
}