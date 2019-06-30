#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

int main() {
    cout << "Enter data for 2 transactions: " << endl;
    Sales_data data1, data2;
    double price;
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo) {
        int total_units_sold = data1.units_sold + data2.units_sold;
        if ( total_units_sold > 0 ){
            double avg_price = (data1.revenue + data2.revenue) / total_units_sold;
            cout << "Result: " << data1.bookNo << " " << total_units_sold << " " << avg_price << endl;
        } else {
            cout << "Zero units sold!" << endl;
        }
        return 0;
    } else {
        cout << "Different ISBN!";
        return -1;
    }
}