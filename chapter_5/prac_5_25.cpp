/***********************************************************************
#   > File Name   : prac_5_25.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-15 16:52:15
***********************************************************************/

#include <iostream>
#include <stdexcept>

double func(int m, int n) {
  if (0 == n) {
    throw std::runtime_error("dividend must not be zero!!");
  }

  return static_cast<double>(m) / n;
}

int main(int argc, char **argv) {
  try {
    std::cout << func(2, 0) << std::endl;
  } catch (std::runtime_error e) {
    std::cout << "exception: " << e.what() << std::endl;
  }

  return 0;  
}
