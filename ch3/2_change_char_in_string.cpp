#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "aaaaaaaa";
    cout << str << endl;
    cout << "Without referene: " << endl;
    for (char c : str) {
        c = toupper(c);
    }
    cout << str << endl;

    cout << "With reference: " << endl;
    for (char &c : str) {
        c = toupper(c);
    }
    cout << str << endl;
}