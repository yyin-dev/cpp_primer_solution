#ifndef EX7_41_H
#define EX7_41_H

#include <iostream>
#include <string>

struct Sales_data;
std::istream& read(std::istream& is, Sales_data& data);

class Sales_data {
    friend Sales_data add(Sales_data& data1, Sales_data& data2);
    friend std::istream& read(std::istream& is, Sales_data& data);
    friend std::ostream& print(std::ostream& os, const Sales_data& data);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

   public:
    // constructors
    Sales_data() : Sales_data("", 0, 0) { std::cout << "Takes 0 args called" << std::endl; };
    Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) { std::cout << "Takes 3 args called" << std::endl; }
    Sales_data(const std::string& s) : Sales_data(s, 0, 0) { std::cout << "Takes string called" << std::endl; }
    Sales_data(std::istream& is) : Sales_data() {
        std::cout << "Takes istream called" << std::endl;
        read(is, *this);
    }

    const std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
};

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
    os << data.isbn() << " " << data.units_sold << " " << data.avg_price();
    return os;
}

#endif