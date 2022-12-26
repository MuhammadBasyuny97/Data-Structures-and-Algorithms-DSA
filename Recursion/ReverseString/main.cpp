#include <iostream>
#include <vector>
#include <string>


using namespace std;

 string ReverseIterative(string str){
    int n = str.size() - 1;
    for(int i{0}; i <= n/2; ++i){
        char c = str[i];
        str[i] = str[n-i];
        str[n-i] = c;
    }
    return str;
}

 string ReverseRecursive(string str, string reverse_str ){
     reverse_str.push_back(str[str.size() -1 ]);
     str.pop_back();
     if(str.empty())
         return reverse_str;
     return ReverseRecursive(str,reverse_str);
     
 }
 
int main(){
   string str;
   cout<< ReverseIterative("Hello World!") << endl; 
   cout << ReverseRecursive("Hello World!", str) << endl;
	return 0;
}
