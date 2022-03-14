#include <cstring>  // strcmp
#include <iostream>

int func1(const char* a);
int func2(const char* a);
void func3(const char* a);

int main() {
  int a{8};
  int* pi{&a};

  char** ppc; // arrays of strings, equal to char* ppc[]

  int* ap[7];

  void* pv{pi}; // particular pointer, need to cast before dereference
  // *pv; // we cannot dereference void*
  // ++pv; // we cannot increment. Why? We do not know the size of each element
  int* pi2{static_cast<int*>(pv)}; 

  pv = ppc;
  pv = ap;
  pv = pi;

  pi = nullptr;
  ppc = nullptr;
  // ap = nullptr;  // error, why? Because it is a static array
  ap[0] = nullptr;
  int** bbb;
  bbb = ap;
  pv = nullptr;
  pi2 = 0;  // older codes. gets the nullptr. please don't do it

  // pi = NULL; // please don't do it

  double* da{new double[5]{}};
  delete[] da;  // dangling pointer
  da = nullptr;

  if (pi != nullptr)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi == nullptr)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  if (!pi)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  // strings are special type of char[]
  char word[]{"Hello"};
  char word2[]{'H', 'e', 'l', 'l', 'o', 0};
  if (strcmp(word, word2) == 0)  // word == word2 is
                                 // implementation-dependent (it might
                                 // compare the two pointers, i.e. the
                                 // two addresses of word and word2)
    std::cout << "same\n";
  else
    std::cout << "different\n";

 // Pointer to functions: ret_type (*name) (args1, args2, ...)
  int (*fp)(const char*); // fp can now point only to functions whose return type is int and takes as arguments const char *
  fp = func1; // can be assigned without &

  fp("hello"); // can be dereferenced without *

  fp = &func2;
  fp("world");

  // fp = func3; // error: wrong signature
  auto xx = func3; // xx will be a pointer to function

  xx("auto");

  decltype(&func3) x = func3; // x will be a pointer to functions like func3
  x("decltype");

  return 0;
}

int func1(const char* a) {
  std::cout << "1111: " << a << std::endl;
  return 1;
}

int func2(const char* a) {
  std::cout << "2222: " << a << std::endl;
  return 2;
}

void func3(const char* a) {
  std::cout << "3333: " << a << std::endl;
}
