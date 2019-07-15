/***********************************************************************
#   > File Name   : prac_14_2.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-14 20:09:02
***********************************************************************/

#include <iostream>
#include <string>

class Sales_data {
 friend std::ostream& operator<<(std::ostream &os, const Sales_data &item);

 public:
  Sales_data(std::string book_no, unsigned int units_sold, double revenue) : 
      book_no_(book_no), units_sold_(units_sold), revenue_(revenue) {

  }

  Sales_data& operator=(const Sales_data &rhs) {
    book_no_ = rhs.book_no_;
    units_sold_ = rhs.units_sold_;
    revenue_ = rhs.revenue_;
    return *this;
  }

  Sales_data& operator+=(const Sales_data &rhs) {
    units_sold_ += rhs.units_sold_;
    revenue_ += rhs.revenue_;
    return *this;
  }

 private:
  std::string book_no_;
  unsigned int units_sold_ = 0;
  double revenue_ = 0.0;
};

std::ostream& operator<<(std::ostream &os, const Sales_data &item) {
  os << item.book_no_ << " " << item.units_sold_ << " " << item.revenue_;  
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum += rhs;
  return sum;
}

int main(int argc, char **argv) {
  Sales_data sd_1("book_1", 5, 20.0);
  Sales_data sd_2("book_2", 10, 50.0);

  std::cout << sd_1 << std::endl;

  Sales_data sd_3 = sd_1 + sd_2;
  std::cout << sd_3 << std::endl;

  return 0;
}
