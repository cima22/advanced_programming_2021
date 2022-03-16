#include <iostream>
#include <vector>
#include <algorithm>

int main(){
 
 std::vector<double> temps;

 for(std::string line; std::getline(std::cin,line);)
  temps.emplace_back(std::stod(line));

 std::sort(temps.begin(), temps.end());

 std::size_t size = temps.size();

 double median = size % 2 != 0 ? temps[size/2] : (temps[size/2 - 1] + temps[size/2]) / 2;

 double mean = 0;
 for(auto& x : temps)
  mean += x;
 mean = mean / size;

 std::cout << "Mean, Median is: "<< mean << ", " << median << std::endl;

return 0;
}
