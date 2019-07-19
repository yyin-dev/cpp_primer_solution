#include "headers.h"

void text_transform(ifstream &rule_file, ifstream &text);
string get_transformed(const string &str, const map<string, string> &mapping);
map<string, string> build_map(ifstream &rule_file);

map<string, string> build_map(ifstream &rule_file) {
    map<string, string> mapping;
    string word;
    string value;
    while (rule_file >> word && getline(rule_file, value)) {
        if (value.size() > 1) {
            mapping[word] = value.substr(1);
        }
    }
    return mapping;
}

string get_transformed(const string &str, const map<string, string> &mapping) {
    if (mapping.find(str) != mapping.end()) {
        return (mapping.find(str)->second);
    } 
    return str;
}

void text_transform(ifstream &rule_file, ifstream &text) {
    map<string, string> rule_map = build_map(rule_file);

    string line;
    while (getline(text, line)) {
        istringstream iss(line);
        bool is_first_word = true;
        string word;
        while (iss >> word) {
            string transformed = get_transformed(word, rule_map);
            if (is_first_word) {
                cout << transformed;
                is_first_word = false;
            } else {
                cout << " " << transformed;
            }
        }
        cout << endl;
    }
}

int main() {
    ifstream rule_file("./word_trans_rule.txt");
    ifstream text("./word_trans_input.txt");
    text_transform(rule_file, text);
}