#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void cout_words_in_stringstream(istream& is){
    string word;
    while(is >> word){
        cout << word << endl;
    } 
}

void file_lines_to_vector(string file_name, vector<string>& v) {
    fstream fs(file_name);
    if (fs) {
        string line;
        while (getline(fs, line)) {
            v.push_back(line);
        }
    } else {
        cerr << "Fail to open" << endl;
    }
}

int main() {
    string input_file = "transaction_input.txt";
    vector<string> vec;
    file_lines_to_vector(input_file, vec);
    for (string line : vec){
        istringstream iss(line);
        cout_words_in_stringstream(iss);
    }
}