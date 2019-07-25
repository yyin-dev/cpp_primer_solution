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

class Bulk_quote : public Quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(const string& bookNo, const double unit_price,
               const size_t min_qty, const double discount)
        : Quote(bookNo, unit_price), min_qty(min_qty), discount(discount){};

    double net_price(const size_t n) const override;

   private:
    size_t min_qty;
    double discount;
};

double Bulk_quote::net_price(const size_t n) const {
    if (n >= min_qty) {
        return n * price * (1 - discount);
    }

    return n * price;
}

void print_total(ostream& os, const Quote& q, const size_t n) {
    cout << "ISBN: " << q.isbn() << " # sold: " << n << ", total due: " << q.net_price(n) << endl;
}

int main() {
    Quote q("XXXX-Y", 2.5);
    print_total(cout, q, 3);
    Bulk_quote bq("YYYY-X", 2.5, 4, 0.3);
    print_total(cout, bq, 4);
}
