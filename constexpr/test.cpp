#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

constexpr int get_constexpr() { return 42; }

constexpr size_t multiply(size_t cnt) {
    return get_constexpr() * cnt;
}

constexpr int get_two() { return 2; }
constexpr int get_double(int n) { return get_two() * n; }

int main() {
    constexpr int ce_i = get_double(2);
    int i = 2;
    int j = get_double(i);
    return 0;
}
