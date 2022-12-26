#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
template <class T>
void display(vector<T> vec){
    cout << "[ ";
    for(auto c: vec)
        cout << c << " ";
    printf("]\n");
}
int main(){
     
   vector<char> letters {'a','z','d','e','f','b','r'};
   display(letters);
   sort(letters.begin(),letters.end());
   display(letters);
   cout << "==================\n";
   vector<int> basket {2,1,65,34,70,2,10,7,8};
   display(basket);
   sort(basket.begin(),basket.end());
   display(basket);
   
   
   cout << "==================\n";
   cout << "Hello World!"<<endl; 
    
	return 0;
}
