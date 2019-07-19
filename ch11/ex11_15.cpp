#include "headers.h"
#include "Sales_data.h"

bool compareIsbn(const Sales_data &d1, const Sales_data & d2){
    return d1.isbn() < d2.isbn();
}

int main() {
    multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);

    multiset<Sales_data, decltype(compareIsbn) *>::const_iterator iter = bookstore.begin();
}