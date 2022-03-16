#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

#define MAX 10

void dutchify(std::array<int, 10>& arr, int pivot);

int main(int argc, char * argv[]){
 
 int pivot = argc > 1 ? std::stoi(argv[1]) : 4;
 std::size_t dim = argc > 2 ? std::stoi(argv[1]) : 10;
 std::array<int, 10> arr;

 std::srand(std::time(nullptr));
 for(unsigned int i = 0; i < dim; i++)
  arr[i] = std::rand() % MAX;

 std::cout << "Pivot: " << pivot << std::endl;

 for(auto& x : arr)
  std::cout << x << " ";
 std::cout << std::endl;

 dutchify(arr, 4);

 for(auto& x : arr)
  std::cout << x << " ";
 std::cout << std::endl;

 return 0;
}

void dutchify(std::array<int, 10>& arr, int pivot){
 unsigned int low = 0;
 unsigned int mid = 0;
 unsigned int high = arr.size() - 1;
 
 while(mid <= high){
  if(arr[mid] < pivot){
   std::swap(arr[mid++],arr[low++]);
   continue;
  }
  
  if(arr[mid] == pivot){
   mid++;
   continue;
  }
 
   std::swap(arr[mid],arr[high--]);
 }
  
}
