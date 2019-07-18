#include "Sales_data.h"
#include "headers.h"


int main() {
    vector<Sales_data> data_vec{Sales_data("1222-2-33-x"), Sales_data("6666-2-33-x"), Sales_data("1111-2-33-x"), Sales_data("3333-2-33-x")};
    for (auto iter = data_vec.cbegin(); iter != data_vec.end(); iter++) {
        print(cout, *iter) << endl;
    }

    cout << endl;
    sort(data_vec.begin(), data_vec.end(), [](const Sales_data & d1, const Sales_data & d2){ return d1.isbn() < d2.isbn(); });
    for (auto iter = data_vec.cbegin(); iter != data_vec.end(); iter++) {
        print(cout, *iter) << endl;
    }
}