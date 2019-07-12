#ifndef EX7_2_H
#define EX7_2_H

#include <iostream>
#include <string>

struct Sales_data {
    // You can put the definition of member functions before
    // the definition of data members. The reason is that
    // compiler would compile the member declarations
    // before processing the function bodies.

    // memeber functions
    const std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const {  
        // const here is necessary for it to be called in print().
        // https://stackoverflow.com/questions/56980750/call-non-const-function-on-a-const-object
        // Deeper logic: 
        // C++ does compilation check and thus it cannot know what operation
        // you actually performed. So it does the checking by looking at the 
        // constness of your functions and objects. So even though the non-const
        // function does not mofidy the data of the object, compiler cannot 
        // prevent you from doing so(actually it does not know whether your code does so),
        // so it just stop you from calling a non-const function on a const object. 
        
        if (units_sold) {
            return revenue / units_sold;
        }
        return 0.0;
    }

    // data members
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// define member function
Sales_data& Sales_data::combine(const Sales_data& that) {
    units_sold += that.units_sold;
    revenue += that.revenue;
    return *this;
}

// define non member functions
Sales_data& add(Sales_data& data1, Sales_data& data2) {
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