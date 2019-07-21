#include "headers.h"

int main() {
    char* sum = new char[string("hello").length() + string("world").length()];
    for (int i = 0; i < (string("hello") + string("world")).length(); i++) {
        sum[i] = (i > string("hello").length() - 1 ) ? string("world")[i - string("hello").length()] : string("hello")[i];
        cout << sum[i];
    }
    delete [] sum;
}
