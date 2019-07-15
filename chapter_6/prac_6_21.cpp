/***********************************************************************
#   > File Name   : prac_6_21.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-14 14:46:05
***********************************************************************/

#include <assert.h>
#include <iostream>

int func(int i, const int *p) {
  assert(p);

  return (i > *p ? i : *p);
}

int main(int argc, char **argv) {
  int a = 3;
  int b = 5;
  int c = 8;

  std::cout << func(a, &b) << std::endl;
  std::cout << func(b, &c) << std::endl;

  return 0;
}
