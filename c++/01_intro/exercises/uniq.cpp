#include <iostream>
#include <string>
#include <vector>

int main(){

 std::vector<std::string> input;
 std::string prec;
 std::string output = "";
 int counter = 1;

 std::getline(std::cin,prec);
 input.push_back(prec);

 for(std::string line; std::getline(std::cin,line);){
  input.push_back(line);
  if(prec == line){
   ++counter;
  }
  else{
     output += "(" + std::to_string(counter) + ") " + prec + "\n";
     counter = 1;
     prec = line;
  }
 }

 output += "(" + std::to_string(counter) + ") " + prec;

 std::cout << "input is:\n";
 for(auto& x : input)
  std::cout << x << "\n";

 std::cout << "output is:\n" << output << std::endl;
 return 0;
}
