#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

#define MAX 10

void dutchify(std::array<int, 10> arr, int pivot);

int main(int argc, char * argv[]){
 
 int pivot = argc > 1 ? std::stoi(argv[1]) : 4;
 std::size_t dim = argc > 2 ? std::stoi(argv[1]) : 10;
 std::array<int, 10> arr;

 std::srand(std::time(nullptr));
 for(unsigned int i = 0; i < dim; i++)
  arr[i] = std::rand() % MAX;

 for(auto& x : arr)
  std::cout << x << " ";
 std::cout << std::endl;


 return 0;
}

void dutchify(std::array<int, 10> arr, int pivot){
 for(unsigned int i = 0; i < array.size(); i++){
  if(arr[i] > pivot)
   for(int j = i + 1; j < arr.size(); j++)
    
 }
}
