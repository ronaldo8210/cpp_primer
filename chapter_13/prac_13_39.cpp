/***********************************************************************
#   > File Name   : prac_13_39.cpp
#   > Author      : ronaldo
#   > Description : 
#   > Create Time : 2019-08-08 15:21:22
***********************************************************************/
#include <iostream>
#include <memory>
#include <utility>

using namespace std;

class StrVec {
 public:
  StrVec();

  StrVec(const StrVec &s);

  StrVec& operator=(const StrVec& rhs);

  ~StrVec();

  void push_back(const string&);

  size_t size() const {
    return first_free_ - elements_;  
  }

  size_t capacity() const {
    return cap_ - elements_;
  }

  string* begin() const {
    return elements_;  
  }

  string* end() const {
    return first_free_;
  }

 private:
  /* static */ allocator<string> alloc_;

  void check_n_alloc();

  pair<string*, string*> alloc_n_copy(const string*, const string*);

  void free();

  void reallocate();

  string *elements_;
  
  string *first_free_;

  string *cap_;
};

StrVec::StrVec() : elements_(nullptr), first_free_(nullptr), cap_(nullptr) {
    
}

StrVec::StrVec(const StrVec &s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements_ = newdata.first;
  first_free_ = cap_ = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements_ = data.first;
  first_free_ = cap_ = data.second;
  return *this;
}

StrVec::~StrVec() {
  free();
}

void StrVec::push_back(const string &s) {
  check_n_alloc();
  alloc_.construct(first_free_++, s);
}

void StrVec::check_n_alloc() {
  if (size() == capacity()) {
    reallocate();
  }
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
  auto data = alloc_.allocate(e - b);
  return {
    data,
    uninitialized_copy(b, e, data)
  };
}

void StrVec::free() {
  if (elements_) {
    for (auto p = first_free_; p != elements_; ) {
      alloc_.destroy(--p);
    }
    alloc_.deallocate(elements_, cap_ - elements_);
  }
}

void StrVec::reallocate() {
  auto newcapacity = size() ? 2 * size() : 1;
  auto newdata = alloc_.allocate(newcapacity);

  auto dest = newdata;
  auto elem = elements_;
  for (size_t i = 0; i != size(); ++i) {
    alloc_.construct(dest++, std::move(*elem++));
  }
  free();

  elements_ = newdata;
  first_free_ = dest;
  cap_ = elements_ + newcapacity;
}

int main(int argc, char **argv) {


  return 0;
}
