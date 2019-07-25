#include "headers.h"

///////////////////////////////////////////////////////////////////////
//////////////////               Quote                /////////////////
///////////////////////////////////////////////////////////////////////

class Quote {
   public:
    Quote() = default;
    Quote(const string& bookNo, double unit_price)
        : bookNo(bookNo), price(unit_price) {}

    Quote(const Quote& other);
    Quote(Quote&& other);

    Quote& operator=(const Quote& rhs);
    Quote& operator=(Quote&& rhs);

    virtual ~Quote() {}

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() const;
    virtual Quote* clone() const&;
    virtual Quote* clone() &&;

   protected:
    double price = 0.0;

   private:
    string bookNo;
};

Quote::Quote(const Quote& other) : price(other.price), bookNo(other.bookNo) {
    // cout << "Quote(const Quote&) " << endl;
}

Quote::Quote(Quote&& other)
    : price(std::move(other.price)), bookNo(std::move(other.bookNo)) {
    // cout << "Quote(Quote&&)" << endl;
}

Quote& Quote::operator=(const Quote& rhs) {
    bookNo = rhs.bookNo;
    price = rhs.price;
    // cout << "Quote& operator=(const Quote&)" << endl;
    return *this;
}

Quote& Quote::operator=(Quote&& rhs) {
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    // cout << "Quote& operator=(Quote&&)" << endl;
    return *this;
}

void Quote::debug() const {
    cout << "[DEBUG] bookNo: " << bookNo << ", price: " << price;
}

Quote* Quote::clone() const& {
    return new Quote(*this);
}

Quote* Quote::clone() && {
    return new Quote(std::move(*this));
    // With the && specifier, *this is already a rvalue.
    // Then why need another std::move()?
    // Without the std::move(), copy constructor would be involved. However,
    // we actually want to involve the move constructor.
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
    Bulk_quote* clone() const&;
    Bulk_quote* clone() &&;
};

Bulk_quote::Bulk_quote(const Bulk_quote& other) : Disc_quote(other) {
    // cout << "Bulk_quote(const Bulk_quote&)" << endl;
}

Bulk_quote::Bulk_quote(Bulk_quote&& other) : Disc_quote(std::move(other)) {
    // cout << "Bulk_quote(Bulk_quote&&)" << endl;
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote& rhs) {
    Disc_quote::operator=(rhs);
    // cout << "Bulk_quote& operator=(const Bulk_quote&)" << endl;
    return *this;
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote&& rhs) {
    Disc_quote::operator=(std::move(rhs));
    // cout << "Bulk_quote& operator=(Bulk_quote&&)" << endl;
    return *this;
}

double Bulk_quote::net_price(const size_t n) const {
    if (n >= min_qty) {
        return n * price * (1 - discount);
    }

    return n * price;
}

Bulk_quote* Bulk_quote::clone() const& {
    return new Bulk_quote(*this);
}

Bulk_quote* Bulk_quote::clone() && {
    return new Bulk_quote(std::move(*this));
}

double print_total(ostream& os, const Quote& q, const size_t n) {
    cout << "ISBN: " << q.isbn() << " # sold: " << n
         << ", total due: " << q.net_price(n) << endl;
    return q.net_price(n);
}

///////////////////////////////////////////////////////////////////////
//////////////////              Basket               /////////////////
///////////////////////////////////////////////////////////////////////

class Basket {
   public:
    Basket() = default;
    void add_item(const Quote& q);
    void add_item(Quote&& q);
    double total_receipt();

   private:
    static bool comp(const shared_ptr<Quote> lhs, const shared_ptr<Quote> rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    multiset<shared_ptr<Quote>, decltype(comp)*> items{comp};
};

void Basket::add_item(const Quote& q) {
    items.insert(shared_ptr<Quote>(q.clone()));
}

void Basket::add_item(Quote&& q) {
    items.insert(shared_ptr<Quote>((std::move(q)).clone()));
}

double Basket::total_receipt() {
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        sum += print_total(cout, **iter, items.count(*iter));
    }
    cout << "Total receipt: " << sum;
    return sum;
}

int main() {
    Basket basket;
    for (int i = 0; i < 10; i++) {
        basket.add_item(Quote("AAA", 20));
    }
    for (int i = 0; i < 10; i++) {
        basket.add_item(Bulk_quote("BBB", 10, 5, 0.5));
    }
    for (int i = 0; i < 10; i++) {
        basket.add_item(Quote("CCC", 10));
    }
    for (int i = 0; i < 10; i++) {
        basket.add_item(Bulk_quote("DDD", 20, 5, 0.5));
    }

    basket.total_receipt();
}
