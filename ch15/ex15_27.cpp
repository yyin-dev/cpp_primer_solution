#include "headers.h"

///////////////////////////////////////////////////////////////////////
//////////////////               Quote                /////////////////
///////////////////////////////////////////////////////////////////////

class Quote {
   public:
    Quote() = default;
    Quote(const string& bookNo, double unit_price) : bookNo(bookNo), price(unit_price) {}

    Quote(const Quote& other);
    Quote(Quote&& other);

    Quote& operator=(const Quote& rhs);
    Quote& operator=(Quote&& rhs);

    virtual ~Quote() {}

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() const;

   protected:
    double price = 0.0;

   private:
    string bookNo;
};

Quote::Quote(const Quote& other) : price(other.price), bookNo(other.bookNo) {
    cout << "Quote(const Quote&) " << endl;
}

Quote::Quote(Quote&& other) : price(std::move(other.price)), bookNo(std::move(other.bookNo)) {
    cout << "Quote(Quote&&)" << endl;
}

Quote& Quote::operator=(const Quote& rhs) {
    bookNo = rhs.bookNo;
    price = rhs.price;
    cout << "Quote& operator=(const Quote&)" << endl;
    return *this;
}

Quote& Quote::operator=(Quote&& rhs) {
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    cout << "Quote& operator=(Quote&&)" << endl;
    return *this;
}

void Quote::debug() const {
    cout << "[DEBUG] bookNo: " << bookNo << ", price: " << price;
}

///////////////////////////////////////////////////////////////////////
//////////////////              Disc_quote           /////////////////
///////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////
//////////////////              Bulk_quote           /////////////////
///////////////////////////////////////////////////////////////////////

class Bulk_quote : public Disc_quote {
   public:
    Bulk_quote() = default;
    // Bulk_quote(const string& bookNo, const double unit_price,
    //            const size_t min_qty, const double discount)
    //     : Disc_quote(bookNo, unit_price, min_qty, discount){};
    using Disc_quote::Disc_quote;

    Bulk_quote(const Bulk_quote& other);
    Bulk_quote(Bulk_quote&& other);

    Bulk_quote& operator=(const Bulk_quote& rhs);
    Bulk_quote& operator=(Bulk_quote&& rhs);

    double net_price(const size_t n) const override;
};

Bulk_quote::Bulk_quote(const Bulk_quote& other) : Disc_quote(other) {
    cout << "Bulk_quote(const Bulk_quote&)" << endl;
}

Bulk_quote::Bulk_quote(Bulk_quote&& other) : Disc_quote(std::move(other)) {
    cout << "Bulk_quote(Bulk_quote&&)" << endl;
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote& rhs) {
    Disc_quote::operator=(rhs);
    cout << "Bulk_quote& operator=(const Bulk_quote&)" << endl;
    return *this;
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote&& rhs) {
    Disc_quote::operator=(std::move(rhs));
    cout << "Bulk_quote& operator=(Bulk_quote&&)" << endl;
    return *this;
}

double Bulk_quote::net_price(const size_t n) const {
    if (n >= min_qty) {
        return n * price * (1 - discount);
    }

    return n * price;
}

///////////////////////////////////////////////////////////////////////
//////////////////         Limited_Bulk_quote           /////////////////
///////////////////////////////////////////////////////////////////////

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
    // 0. Default constructor
    Bulk_quote use_default_ctor;

    // 1. Use Bulk_quote copy constructor
    Bulk_quote use_copy_ctor(use_default_ctor);
    /*
    Quote(const Quote&)
    Bulk_quote(const Bulk_quote&)
     */

    // 2. Use Bulk_quote move constructor
    Bulk_quote use_move_ctor(std::move(use_default_ctor));
    /*
    Quote(Quote&&)
    Bulk_quote(Bulk_quote&&)
     */

    // 3. Use Bulk_quote copy assignment operator
    Bulk_quote first, second;
    first = second;
    /*
    Quote& operator=(const Quote&)
    Bulk_quote& operator=(const Bulk_quote&)
     */

    // 4. Use Bulk_quote move assignment operator
    second = std::move(first);
    /*
    Quote& operator=(Quote&&)
    Bulk_quote& operator=(Bulk_quote&&)
     */
}
