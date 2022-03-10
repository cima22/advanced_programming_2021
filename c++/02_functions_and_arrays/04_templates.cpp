#include <iostream>

template <int N, typename T>  // templates must be known at compile time
T dwim(const T a, const T b); //declaration

int main() {
  int a{5}, b{7};
  double c{3.332}, d{7.7};
  float e{23.4}, f{3.34e2};
  char g{'0'}, h{'6'};

 constexpr int ce {3};

  std::cout << dwim<ce>(a, b) << '\n'
            << dwim<3>(c, d) << '\n'
            << dwim<3>(e, f) << '\n'
            << dwim<3>(g, h) << std::endl;
  return 0;
}

template <int N, typename T>
T dwim(const T a, const T b) {
  return a + b + N;
}
