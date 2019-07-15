#include "headers.h"

int main() {
    vector<int> v1;
    vector<int> v2{1, 2, 3};
    vector<int> v3(3, 0);
    vector<int> v4(3);
    vector<int> v5(v2);
    vector<int> v6(v2.begin(), v2.end() - 1);
}