#include <iostream>
#include <vector>
#include <string>


using namespace std;

long long findFactorialRecursive(int n){   Big-O   O(n)   because of [recursive function called itself n times]
     
     if(n == 1)
        return 1;
     if(n == 2)
        return 2;
        
    return n * findFactorialRecursive(n-1);
}

long long findFactorialIterative(int n){  Big-O   O(n)
     int result {1};
     if(n == 2)
         return 2;   // Or answer = 2
     while(n >= 2){
         result *= n;
         --n;
     }
     return result;
}

long long findFactorialIterative2(int n){   
     int result {1};
     while(n >= 1){
         result *= n;
         --n;
     }
     return result;
}

int main(){
   cout << findFactorialRecursive(1) << endl;
   cout << findFactorialRecursive(6) << endl;
   cout << findFactorialIterative(5) << endl;
   cout << findFactorialIterative2(5) << endl;
   cout<<"Hello World!"<<endl; 
    
	return 0;
}
