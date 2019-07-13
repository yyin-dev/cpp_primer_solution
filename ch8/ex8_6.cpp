#include "ex8_6.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
    string input_file = "transaction_input.txt";
    string output_file = "summary.txt";
    ifstream ifs(input_file);
    ofstream ofs(output_file, ofstream::app);  // change append or overwrite
    Sales_data total;
    if (read(ifs, total)) {
        Sales_data data;
        while (read(ifs, data)) {
            if (data.isbn() == total.isbn()) {
                total.combine(data);
            } else {
                print(ofs, total);
                total = data;
            }
        }
        print(ofs, total);
    } else {
        cerr << "No transaction to process." << endl;
    }

    ifs.close();
    ofs.close();
}