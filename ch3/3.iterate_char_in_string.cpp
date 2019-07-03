#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "kobe bryant";
    for (decltype(str.size()) i = 0; i < str.size() && !isspace(str[i]); i++){
        str[i] = toupper(str[i]);
    }
    cout << str << endl;

    for (int i = 0; i < str.size(); i++){
        cout << str[i] << " ";
    }
}