#include "ex7_27.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Screen sc = Screen(5, 5, 'X');
    sc.move(4, 0).set('#').display(cout);
    cout << endl;
    sc.display(cout);
}
