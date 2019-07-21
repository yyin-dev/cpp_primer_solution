#include "headers.h"

int main() {
    unique_ptr<string> ups1(new string("Kobe"));
    // unique_ptr<string> ups2(ups1);
    // unique_ptr<string> ups3 = ups1;
}