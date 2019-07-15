/***********************************************************************
#   > File Name   : prac_10_14.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-06-19 16:21:58
***********************************************************************/

#include <iostream>

int main(int argc, char **argv) {
  auto f = [] (int a, int b) -> int {
    return a + b;  
  };

  std::cout << f(2, 3) << std::endl;
  return 0;
}
