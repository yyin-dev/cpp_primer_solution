#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cout << "Note that the moment you open a file with 'out' mode"
        << ", even if you just open it and then close it" 
        << ", all the content in it is discard. ";
    ofstream os("test_input.txt");
    os.close();
}
