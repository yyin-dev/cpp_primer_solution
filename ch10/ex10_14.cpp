#include "headers.h"

int main() {
    auto lambda_sum = [](int i1, int i2){return i1+i2;};

    cout << lambda_sum(1, 2);
}