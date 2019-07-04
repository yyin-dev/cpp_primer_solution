#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::noskipws;

int main() {
    char c, previous;
    int vowelCount = 0;
    int spaceCount = 0;
    int tabCount = 0;
    int newlineCount = 0;
    int ffCount = 0;
    int flCount = 0;
    int fiCount = 0;

    while (cin >> noskipws >> c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'o':
            case 'u':
                ++vowelCount;
                break;
            case 'i':
                ++vowelCount;
                if (previous == 'f') {
                    ++fiCount;
                }
                break;
            case ' ':
                ++spaceCount;
                break;
            case '\t':
                ++tabCount;
                break;
            case '\n':
                ++newlineCount;
                break;
            case 'f':
                if (previous == 'f') {
                    ++ffCount;
                }
                break;
            case 'l':
                if (previous == 'f') {
                    ++flCount;
                }
                break;
            default:
                break;
        }
        previous = c;
    }

    cout << "Number of vowels: " << vowelCount << endl;
    cout << "Number of space: " << spaceCount << endl;
    cout << "Number of tab: " << tabCount << endl;
    cout << "Number of newline: " << newlineCount << endl;
    cout << "Number of ff: " << ffCount << endl;
    cout << "Number of fl: " << flCount << endl;
    cout << "Number of fi: " << fiCount << endl;
    return 0;
}