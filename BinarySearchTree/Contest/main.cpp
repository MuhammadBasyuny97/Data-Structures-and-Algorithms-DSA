#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <numeric>
#include <map>


using namespace std;


int answerslow{0};
int answerfast{0};
long fibonacciSlow(long n){
    answerslow++;
       if(n < 2)
         return n;
    
    return fibonacciSlow(n - 1) + fibonacciSlow (n - 2);
} 
      
long fibonacci(int n){
    static map<int , long> cache;
    answerfast++;
   if(cache[n])
       return cache[n];
   else {
       if(n < 2)
        return n;
       else{
        cache[n] = (fibonacci(n - 1) + fibonacci (n - 2));
        return cache[n];
          }
       }
}
int main(){
cout << fibonacciSlow(7) << endl;
cout << answerslow << endl;
cout << "============\n";
cout << fibonacci(7) << endl;
cout << answerfast << endl;


    
	return 0;
}
