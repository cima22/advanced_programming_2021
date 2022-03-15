#include <iostream>
#include <vector>
#include <limits>

int main(){

 unsigned int num;
 
 std::cout << "Insert number: ";
 
 while(!(std::cin >> num)){
  std::cout << "Insert an integer number > 0 please: ";
  std::cin.clear();
  std::cin.ignore(sizeof(num));
 }

 std::vector<unsigned int> numbers(num + 1,0);

 for(unsigned int i = 2; i < num + 1; i++)
  numbers[i] = i;

 for(unsigned int i = 2; i <= num/2; i++)
  for(unsigned int m = 2; m * i <= num; m++)
   if(numbers[m * i] > 0)
     numbers[m * i] = 0;

 for(auto& x : numbers)
	if(x > 0) std::cout << x << "\n";
 return 0;
}
