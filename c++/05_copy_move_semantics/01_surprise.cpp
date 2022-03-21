#include <iostream>

struct X {
  char member;
};

int main() {
  X x1;                 // default ctor -- Built-in types are left un-initialized
  X x2{x1};             // copy ctor
  X x3{std::move(x2)};  // move ctor
  X x4{};               // default ctor calling {} to each member, built-in tpyes initialized to default values
  x4 = x3;              // copy assignment
  X x5;                 // default ctor
  x5 = std::move(x4);   // move assignment
  std::cout << x5.member << std::endl;  // what do you expect??
  return 0;
}
