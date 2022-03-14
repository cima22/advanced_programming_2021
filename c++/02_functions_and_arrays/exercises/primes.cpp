#include <iostream>
#include <vector>

#define N 100

bool is_prime(const int num);

int main(int argc, char* argv[]){

 std::vector<int> primes;

 for(int num = 2; num < N; num++)
  if(is_prime(num))
   primes.push_back(num);

 for(int& x : primes)
  std::cout << x << "\n";

 return 0;
}

bool is_prime(const int num){
 for(int i = 2; i <= num/2; i++)
  if(num % i == 0) return false;
 return true;
}
