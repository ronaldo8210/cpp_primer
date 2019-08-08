/***********************************************************************
#   > File Name   : prac_12_2.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-08-07 18:04:55
***********************************************************************/
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// 非线程安全
class StrBlob {
 public:
  typedef vector<string>::size_type size_type;

  StrBlob();

  StrBlob(initializer_list<string> il);

  ~StrBlob() {
    cout << "destructor" << endl;
  }

  size_type size() {
    return data_->size();
  }

  bool empty() {
    return data_->empty();
  }

  void push_back(const string &str) {
    data_->push_back(str);
  }

  void pop_back();

  string& front();

  string& back();

 private:
  void check(size_type i, const string &msg) const;

  shared_ptr<vector<string>> data_;
};

StrBlob::StrBlob() : data_(make_shared<vector<string>>()) {

}

StrBlob::StrBlob(initializer_list<string> il) : data_(make_shared<vector<string>>(il)) {

}

void StrBlob::pop_back() {
  check(0, "empty StrBlob");
  return data_->pop_back();
}

string& StrBlob::front() {
  check(0, "empty StrBlob");
  return data_->front();
}

string& StrBlob::back() {
  check(0, "empty StrBlob");
  return data_->back();
}

void StrBlob::check(size_type i, const string &msg) const {
  if (i >= data_->size()) {
    throw out_of_range(msg);
  }
}

int main(int argc, char **argv) {
  StrBlob A({"a", "b", "c"});
  StrBlob B(A);

  return 0;  
}
