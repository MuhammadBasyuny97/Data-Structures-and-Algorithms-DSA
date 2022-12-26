#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string LongestWord( string sen) {
  vector<string> array_of_strings;
  string temp;
  size_t i{0};
  size_t arr_size{sen.size()};
  
  while( i < arr_size){ 
    
    char c = sen.at(i);
    if(!ispunct(c) && !isspace(c))
        temp.push_back(c);
    else if(isspace(c)){
      array_of_strings.push_back(temp);
      temp.clear();
    }
    
    if(i == arr_size-1)
      array_of_strings.push_back(temp);
    
    ++i;
  }
  
  i = 1;
  string max = array_of_strings[0];
  size_t string_list_size = array_of_strings.size();
  while( i < string_list_size){
    if(max.size() < array_of_strings[i].size()){
      max =  array_of_strings[i];
    }
    ++i;
  }
  sen = max;
  // code goes here  
  return sen;

}

int main() { 
   
  // keep this function call here
  string sen {"fun&!! time"};
  cout << LongestWord(sen) << endl;
  
  return 0;
    
}