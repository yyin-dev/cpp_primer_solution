#include "headers.h"

int main() {
    vector<string> lines;
    map<string, vector<int>> word2lineNums;

    ifstream ifs("./ex12_28_input.txt");
    string line;
    while (getline(ifs, line)) {
        if (line.length() > 50) {
            line = line.substr(0, 50);
        }

        istringstream iss(line);
        string word;
        while (iss >> word) {
            word2lineNums[word].push_back(lines.size());
        }

        lines.push_back(line);
    }
    
    do {
        string input;
        cout << "Enter the word for query, or enter 'q' to exit: ";
        if (cin >> input && input.length() > 0 && input != "q") {
            map<int, string> lineNum2text;

            for (auto lineNum : word2lineNums[input]) {
                lineNum2text[lineNum] = lines[lineNum];
            }

            size_t freq = lineNum2text.size();
            cout << input << " occurs " << freq << (freq > 1 ? " times" : " time") << endl;
            for (const pair<int, string>& p : lineNum2text) {
                cout << "\t(line " << p.first << ") " << (p.second.length() > 50 ? p.second.substr(0, 50) : p.second) << endl;
            }
        } else {
            cout << "Exit." << endl;
            break;
        }
    } while(true);
}