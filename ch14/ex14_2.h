#ifndef EX_14_2_H
#define EX_14_2_H

#include "headers.h"

struct Sales_data;
istream& read(istream& is, Sales_data& data);
// Do not need to overload the read() function to take parameter of ifstream or
// fstream. They inherit from istream and polymorphism applies.

class Sales_data {
    friend Sales_data add(Sales_data& data1, Sales_data& data2);
    friend istream& read(istream& is, Sales_data& data);
    friend ostream& print(ostream& os, const Sales_data& data);

    friend istream& operator>>(istream& is, Sales_data& d);
    friend ostream& operator<<(ostream& os, const Sales_data& d);

   public:
    Sales_data() = default;
    Sales_data(const string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(const string& s) : bookNo(s) {}
    Sales_data(istream& is);

    const string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    Sales_data operator+(const Sales_data& other);      // should return nonreference type
    Sales_data& operator+=(const Sales_data& other);    // should return reference type

   private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// define constructors
Sales_data::Sales_data(istream& is) {
    read(is, *this);
}

// define member function
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

// define non member functions
Sales_data add(Sales_data& data1, Sales_data& data2) {
    Sales_data sum = data1;
    sum.combine(data2);
    return sum;
}

istream& read(istream& is, Sales_data& data) {
    double price;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = price * data.units_sold;
    return is;
}

ostream& print(ostream& os, const Sales_data& data) {
    os << data.isbn() << " " << data.units_sold << " " << data.avg_price() << endl;
    return os;
}

#endif