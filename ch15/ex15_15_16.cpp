#include "headers.h"

class Quote {
   public:
    Quote() = default;
    Quote(const string& bookNo, double unit_price) : bookNo(bookNo), price(unit_price) {}

    virtual ~Quote() {}

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() const;

   protected:
    double price = 0.0;

   private:
    string bookNo;
};

void Quote::debug() const {
    cout << "[DEBUG] bookNo: " << bookNo << ", price: " << price;
}



class Disc_quote : public Quote {
   public:
    Disc_quote() = default;
    Disc_quote(const string& bookNo, const double unit_price,
               const size_t min_qty, const double discount)
        : Quote(bookNo, unit_price), min_qty(min_qty), discount(discount){};

    double net_price(const size_t n) const = 0;
    void debug() const override;

   protected:
    size_t min_qty;
    double discount;
};

void Disc_quote::debug() const {
    Quote::debug();
    cout << ", min_qty: " << min_qty << ", discount: " << discount;
}



class Bulk_quote : public Disc_quote {
   public:
    Bulk_quote() = default;
    Bulk_quote(const string& bookNo, const double unit_price,
               const size_t min_qty, const double discount)
        : Disc_quote(bookNo, unit_price, min_qty, discount){};

    double net_price(const size_t n) const override;
};

double Bulk_quote::net_price(const size_t n) const {
    if (n >= min_qty) {
        return n * price * (1 - discount);
    }

    return n * price;
}

class Limited_bulk_quote : public Disc_quote {
   public:
    Limited_bulk_quote() = default;
    Limited_bulk_quote(const string& bookNo, const double unit_price,
                       const size_t min_qty, const size_t max_qty, const double discount)
        : Disc_quote(bookNo, unit_price, min_qty, discount), max_qty(max_qty){};

    double net_price(const size_t n) const override;
    void debug() const override;

   private:
    size_t max_qty;
};

double Limited_bulk_quote::net_price(const size_t n) const {
    if (n < min_qty) {
        return n * price;
    } else if (min_qty <= n && n <= max_qty) {
        return n * price * (1 - discount);
    } else {
        return max_qty * price * (1 - discount) + (n - max_qty) * price;
    }
}

void print_total(ostream& os, const Quote& q, const size_t n) {
    cout << "ISBN: " << q.isbn() << " # sold: " << n << ", total due: " << q.net_price(n) << endl;
}

void Limited_bulk_quote::debug() const {
    Disc_quote::debug();
    cout << ", max_qty: " << max_qty;
}

int main() {
    Quote q("XXXX-Y", 2.5);
    print_total(cout, q, 3);

    Bulk_quote bq("YYYY-X", 2.5, 4, 0.3);
    print_total(cout, bq, 4);

    Limited_bulk_quote lbq("XXXX-X", 2.5, 4, 8, 0.3);
    print_total(cout, lbq, 10);  // 2.5 * 8 * 0.7 + 2 * 2.5 = 14 + 5 = 19

    q.debug();
    cout << endl;
    bq.debug();
    cout << endl;
    lbq.debug();
    cout << endl;
}
