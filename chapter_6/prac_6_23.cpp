/***********************************************************************
#   > File Name   : prac_6_23.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-07-14 15:11:00
***********************************************************************/

#include <assert.h>
#include <iostream>
#include <iterator>

void print_1(const char *p) {
  assert(p);
  while (*p != '\0') {
    std::cout << *p++ << std::endl;
  }
}

void print_2(const int *begin, const int *end) {
  assert(begin);
  assert(end);
  while (begin != end) {
    std::cout << *begin++ << std::endl;
  }
}

void print_3(const int ia[], size_t size) {
  for (size_t i = 0; i < size; ++i) {
    std::cout << ia[i] << std::endl;
  }
}

void print_4(const int[]) {

}

void print_5(const int[10]) {

}

int main(int argc, char **argv) {
  int i = 0, j[2] = {0, 1};

  print_1((const char*)j);  // !!
  print_2(std::begin(j), std::end(j));
  print_3(j, std::end(j)-std::begin(j));

  print_4(&i);  // 编译通过
  print_5(&i);  // 编译通过

  return 0;  
}
