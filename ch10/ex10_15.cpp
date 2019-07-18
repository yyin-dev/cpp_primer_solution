#include "headers.h"

int main() {
    const int CONST = 3;

    auto sum = [CONST] (int i) -> int {return i + CONST;};

    cout << sum(10);
}