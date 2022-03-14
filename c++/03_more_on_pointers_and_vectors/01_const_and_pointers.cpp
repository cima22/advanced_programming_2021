#include <iostream>

template <typename T>
void print_sentinel(const T* a, const std::size_t l);

int main() {
  int a{8}, b{7};
  int* pi{&a};

  const int* pc{&a}; // read from right to left: pc points to a constant int
  // *pc = 7; 	// error
  a = 15;  // I can obviously change a, because it is not declared as constant

  int* const cp{&a}; // reding right to left: cp is a constant pointer to int
  a = b;
  *cp = 33;
  // cp = &b;   // error; cp is constant and cannot be changed

  const int* const cpc{&a}; // const pointer to int const

  // *cpc = 0;  // error
  // cpc = &n;  // error
  a = 99;

  int aa[4]{}; // all elements set to 0
  print_sentinel(aa, 4);

  return 0;
}

template <typename T>
void print_sentinel(const T* a, const std::size_t l) {
  const T* const end{a + l}; // the sentinel; it points to the cell after the last element of a
  for (; a != end; ++a)
    std::cout << *a << std::endl;
}
