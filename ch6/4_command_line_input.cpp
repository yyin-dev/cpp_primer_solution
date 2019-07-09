#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

void recursivePrint(const vector<string> & v, vector<string>::iterator beg, vector<string>::iterator end){
    if (beg == end){
        return;
    } else {
        cout << *beg << " ";
        recursivePrint(v, ++beg, end);
    }
}

int main(int argc, char **argv) {
    vector<string> v = {"Kobe", "Leborn", "Lenord", "Nash", "Harden"};
    recursivePrint(v, v.begin(), v.end());
}
