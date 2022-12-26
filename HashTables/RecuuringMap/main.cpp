#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
 
    int array []{0,4,8,7,2,3,4,6,1};
    
    int array_size = sizeof(array) / sizeof(array[0]);
    cout << array_size << endl;
    map<int , int> m1;
    for(int i{0} ; i < array_size ; ++i){
       if(m1.find(array[i]) != m1.end()){
         cout << array[i] << endl;
         break;
    }
       else
           m1[array[i]] = i;
    }
  
    
	return 0;
}