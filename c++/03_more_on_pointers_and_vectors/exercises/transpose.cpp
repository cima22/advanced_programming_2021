#include <iostream>
#include <array>

void print_matrix(auto array, int nrow, int col);

int main(int argc, char* argv[]){

 std::size_t nrow = argc > 1 ? std::stoi(argv[1]) : 10;
 std::size_t ncol = argc > 1 ? std::stoi(argv[2]) : 10;
 std::size_t dim  = nrow * ncol;

 std::array<double,dim> matrix;

 for(unsigned int i = 0; i < nrow; i++)
  for(unsigned int j = 0; i < ncol; j++)
   matrix[i*ncol + j] = i*ncol + j;

 std::cout << matrix;

 return 0;
}
