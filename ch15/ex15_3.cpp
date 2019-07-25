#include "headers.h"

class Quote {
   public:
    Quote() = default;
    Quote(const string& bookNo, double unit_price) : bookNo(bookNo), price(unit_price) {}

    virtual ~Quote() {}

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }

   protected:
    double price = 0.0;

   private:
    string bookNo;
};

void print_total(ostream& os, const Quote& q, const size_t n) {
    cout << "ISBN: " << q.isbn() << " # sold: " << n << ", total due: " << q.net_price(n) << endl;
}

int main() {
    Quote q("XXXX-Y", 2.5);
    print_total(cout, q, 3);
}
