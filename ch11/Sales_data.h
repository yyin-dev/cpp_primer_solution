#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <fstream>
#include <string>

struct Sales_data;
std::istream& read(std::istream& is, Sales_data& data);
// Do not need to overload the read() function to take parameter of std::ifstream or std::fstream.
// They inherit from std::istream and polymorphism applies. 

class Sales_data {
    friend Sales_data add(Sales_data& data1, Sales_data& data2);
    friend std::istream& read(std::istream& is, Sales_data& data);
    friend std::ostream& print(std::ostream& os, const Sales_data & data);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

   public:
    Sales_data() = default;
    Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(const std::string& s) : bookNo(s) {}
    Sales_data(std::istream& is);

    const std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
};

// define constructors
Sales_data::Sales_data(std::istream& is) {
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

std::istream& read(std::istream& is, Sales_data& data) {
    double price;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = price * data.units_sold;
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& data) {
    os << data.isbn() << " " << data.units_sold << " " << data.avg_price() << std::endl;
    return os;
}

#endif