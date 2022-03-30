#include <iostream>

template <typename T>
struct Base {
  void foo() const { std::cout << "base foo" << std::endl; }
};

template <typename T>
struct Derived : public Base<T> {
  void bar() const { this->foo(); } // if the parent class is templated, we have to use this-> to access the functions of the parent class.
};

int main() {
  Derived<int> d;
  d.bar();
}
