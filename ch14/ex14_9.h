#ifndef EX_14_2_H
#define EX_14_2_H

#include "headers.h"

struct Sales_data;

class Sales_data {
    friend istream& operator>>(istream& is, Sales_data& d);
    friend ostream& operator<<(ostream& os, const Sales_data& d);

    friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
    // friend Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs);

    friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);
    friend bool operator!=(const Sales_data& lhs, const Sales_data& rhs);

   public:
    Sales_data() = default;
    Sales_data(const string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(const string& s) : bookNo(s) {}
    Sales_data(istream& is);

    const string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    Sales_data& operator+=(const Sales_data& other);
    // Sales_data& operator-=(const Sales_data& other);

   private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data::Sales_data(istream& is) {
    is >> *this;
}

Sales_data& Sales_data::combine(const Sales_data& that) {
    units_sold += that.units_sold;
    revenue += that.revenue;
    return *this;
}

double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    }
    return 0.0;
}

Sales_data& Sales_data::operator+=(const Sales_data& other) {
    if(bookNo != other.isbn()) {
        cout  << "Not transaction of the same kind of book, cannot add!" << endl;
    } else {
        units_sold += other.units_sold;
        revenue += other.revenue;
    }
    return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

istream& operator>>(istream& is, Sales_data& data) {
    double price;
    is >> data.bookNo >> data.units_sold >> price;
    if (is) {
        data.revenue = price * data.units_sold;
    } else {
        data = Sales_data();
    }
    return is;
}

ostream& operator<<(ostream& os, const Sales_data& data) {
    os << data.isbn() << " " << data.units_sold << " " << data.avg_price() << endl;
    return os;
}

#endif