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


int main() {
    // Disc_quote dq;
}
/*
ex15_17.cpp: In function 'int main()':
ex15_17.cpp:49:16: error: cannot declare variable 'dq' to be of abstract type 'Disc_quote'
     Disc_quote dq;
                ^~
ex15_17.cpp:27:7: note:   because the following virtual functions are pure within 'Disc_quote':
 class Disc_quote : public Quote {
       ^~~~~~~~~~
ex15_17.cpp:34:12: note:        'virtual double Disc_quote::net_price(size_t) const'
     double net_price(const size_t n) const = 0;
            ^~~~~~~~~
 */
