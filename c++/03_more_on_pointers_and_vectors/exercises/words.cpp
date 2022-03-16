#include <iostream>
#include <vector>

int main(){

 std::string word;
 std::vector<std::string> words;

 while(std::cin >> word)
  words.emplace_back(word);

 for(unsigned int i = 0; i < words.size(); i++)
  for(unsigned int j = i + 1; j < words.size(); j++)
   if(words[j] == words[i]){
    words.erase(words.begin() + j);
    j--;
   }

 for(auto& x : words)
  std::cout << x << std::endl;

return 0;
}
