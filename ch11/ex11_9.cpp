#include "headers.h"

void print(map<string, list<int>> m){
    for (auto &p: m){
        cout << "[Word] " << p.first << ": ";
        for(auto &l: p.second){
            cout << l << ", ";
        }
        cout << endl;
    }
}

int main() {
    map<string, list<int>> possible_lines;
    possible_lines["cruel"] = {1, 10, 20};
    possible_lines["love"] = {5, 2, 0};
    print(possible_lines);
}
