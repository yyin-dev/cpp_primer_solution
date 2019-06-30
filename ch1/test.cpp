#include <iostream>
#include "Sales_item.h"
using namespace std;

int main() {
    Sales_item item, currentItem, sum;
    if (cin >> item) {
        int count = 1;
        sum = item;
        while (cin >> currentItem) {
            if (item.isbn() == currentItem.isbn()){
                count++;
                sum += currentItem;
            } else {
                cout << count << " transactions for " << item.isbn() << endl;
                cout << "Sum of transaction(s): " << sum << endl;
                item = currentItem;
                sum = currentItem;
                count = 1;
            }
        }
        // print the last group of transactions
        cout << count << " transactions for " << item.isbn() << endl;
        cout << "Sum of transaction(s): " << sum << endl;
    } else {
        cout << "No input, exit." << endl;
    }
    return 0;
}