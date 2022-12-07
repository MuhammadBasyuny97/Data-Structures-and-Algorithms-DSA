#include <iostream>
#include <vector>
#include <string>


using namespace std;

unsigned long long FibonacciRecursive(unsigned long long n){ O(n)
   if(n <= 1)
     return n; 
   
   return FibonacciRecursive(n-1) + FibonacciRecursive(n-2);  
}

unsigned long long FibonacciIterative(unsigned long long n){   O(n)
   if(n <= 1)
       return n;
   unsigned long long answer{0};
   unsigned long long prev{1};
   unsigned long long prev_prev{0};
   
   for (unsigned long long i{2}; i <= n; ++i){
       answer = prev + prev_prev;
       prev_prev = prev;
       prev = answer;
   }
    return answer;
}

unsigned long long FibonacciIterative2(unsigned long long n){   O(n)
  vector<unsigned long long > sequence{0,1};

  for(unsigned long long i{2}; i <= n ; ++i){
      sequence.push_back(sequence[i-1] + sequence[i-2]);
  }
  return sequence[n];
}
int main(){

    cout << FibonacciRecursive(5) << endl;
    cout << FibonacciIterative(5) << endl;
    cout << FibonacciIterative2(1) << endl;
    
	return 0;
}
