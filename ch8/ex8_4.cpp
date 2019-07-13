#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

void file_words_to_vector(string file_name, vector<string>& v) {
    fstream fs(file_name);
    if (fs) {
        string word;
        while (fs >> word) {
            v.push_back(word);
        }
    } else {
        cerr << "Fail to open" << endl;
    }
}

int main() {
    vector<string> lines;
    file_lines_to_vector("test_input.txt", lines);
    for (string s : lines) {
        cout << s << endl;
    }

    cout << endl;

    vector<string> words;
    file_words_to_vector("test_input.txt", words);
    for (string s : words) {
        cout << s << endl;
    }
}
