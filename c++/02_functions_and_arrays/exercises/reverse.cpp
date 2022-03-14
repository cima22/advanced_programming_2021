#include <iostream>

template <std::size_t S, typename T>
T* store(){
 T* arr = new T[S];
 for(int i = 0; i < S; i++)
  std::cin >> arr[i];
 return arr;
}

template <std::size_t S, typename T>
void rev_print(const T* arr){
 for(int i = S - 1; i >= 0; i--)
  std::cout << arr[i] << "\n";
 std::cout << std::endl;
}

int main(){

 std::cout << "Int array of size 5:\n";
 int * int_arr = store<5,int>();
 std::cout << std::endl;
 rev_print<5>(int_arr);

 std::cout << "Double array of size 4:\n";
 double * double_array = store<4,double>();
 std::cout << std::endl;
 rev_print<4>(double_array);

 delete[] int_arr;
 delete[] double_array;

 return 0;
}
