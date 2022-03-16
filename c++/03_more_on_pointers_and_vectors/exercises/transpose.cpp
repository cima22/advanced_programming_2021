#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>

void print_matrix(std::vector<double>& mat, int nrow, int ncol);

void transpose(std::vector<double>& mat, int nrow, int ncol);

int main(int argc, char* argv[]){

 std::size_t nrow = argc > 1 ? std::stoi(argv[1]) : 10;
 std::size_t ncol = argc > 1 ? std::stoi(argv[2]) : 10;
 std::size_t dim  = nrow * ncol;

 std::vector<double> matrix(dim,0);

 for(unsigned int i = 0; i < nrow; i++)
  for(unsigned int j = 0; j < ncol; j++)
   matrix[i*ncol + j] = i*ncol + j;

 print_matrix(matrix, nrow, ncol);
 std::cout << std::endl;
 transpose(matrix, nrow, ncol);
 std::cout << std::endl;
 print_matrix(matrix, ncol, nrow);

 return 0;
}

void print_matrix(std::vector<double>& mat, int nrow, int ncol){
 for(unsigned int i = 0; i < nrow; i++){
  for(unsigned int j = 0; j < ncol; j++)
   std::cout << std::setw(3) << mat[i*ncol + j];
  std::cout << std::endl;
 }
}

void transpose(std::vector<double>& mat, int nrow, int ncol){
 std::vector<double> dst;
 for(unsigned int j = 0; j < ncol; j++)
  for(unsigned int i = 0; i < nrow; i++)
   dst.push_back(mat[i * ncol + j]);
   //std::swap(mat[i * ncol + j], mat[j * ncol + i]);
 mat = dst;
}
