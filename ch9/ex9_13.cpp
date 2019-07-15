#include "headers.h"

int main() {
    list<int> list_int{1, 2, 3};
    vector<int> v_int(list_int.begin(), list_int.end());
    vector<double> v_double1(list_int.begin(), list_int.end());
    vector<double> v_double2(v_int.begin(), v_int.end());
}