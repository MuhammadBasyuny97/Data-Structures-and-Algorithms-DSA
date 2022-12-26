#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

void PrintAllPairsofArray(int arr[] , size_t size){
    //cout <<"{ ";
    for (size_t i {0} ; i < size ; ++i){
        for(size_t j{0} ; j < size ; ++j)
            cout <<"[" << arr[i]<<"," << arr[j] << "]";
        cout <<"\n";
    }
   // cout << "}";
}

//===============================================
template <class  T>
void PrintAllNumbersThenAllPairsSums( array<T , 5> arr){
    cout << "these are the numbers: " << endl;
    
    for_each(arr.begin() , arr.end() , [](int x){cout << x << endl;} );

     cout << "and these are their sums: " << endl;
    for(size_t i {0} ; i < arr.size() ; ++i){
        for(size_t j {0} ; j < arr.size() ; ++j)
            cout << arr[i] + arr.at(j) << endl;
}
}

//=======================================================
void breakMyBrowser(int n) {
    int j{0};
  for(int i=0; i<n; i++) {
      cout << j++ << endl;
    breakMyBrowser(n-1);
  }
}
 


int main(){
 
// array <int , 5> arr {1,2,3,4,5};
 //PrintAllNumbersThenAllPairsSums(arr);

breakMyBrowser(10);
	return 0;
}
