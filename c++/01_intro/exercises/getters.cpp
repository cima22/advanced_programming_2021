#include <iostream>

void get_int();

void get_double();

int main(){
 
 get_int();

 get_double();

 return 0;
}

void get_int(){
 std::cout << "get_int" << std::endl;
 int i;
 while(std::cin >> i)
  std::cout << i << std::endl;

}

void get_double(){
 std::cin.clear();
 std::cin.ignore();
 std::cout << "get_double" << std::endl;
 double d;
 while(std::cin >> d)
  std::cout << d << std::endl;
}
