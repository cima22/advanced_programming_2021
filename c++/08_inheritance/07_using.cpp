#include <iostream>

// overloading does not work through inheritance

struct foo {
  void f(int x) { std::cout << "int " << x << std::endl; }
};

struct bar : public foo {
  using foo::f;  // brings all foo::f to this scope, and thanks to this overloading works as usual
  void f(char x) { std::cout << "char " << x << std::endl; }
};

int main() {
  bar b;
  b.f(33);
}
