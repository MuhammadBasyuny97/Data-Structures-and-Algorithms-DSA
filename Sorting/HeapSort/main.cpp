#include <iostream>
#include <vector>
#include <string>
#include <cmath>


using namespace std;
void Heapify(int arr[] , int n , int i){
   // double p {round(i/2) - 1};
    int l{2*i + 1} ;
    int r{2*i + 2} ; 
    int max {i};
        
        if(l < n && arr[l] > arr[max])
            max = l;
        if(r < n && arr[r] > arr[max])
           max = r;
        if(i != max){
           swap(arr[i], arr[max]);
           Heapify(arr, n , max);
    }
}

void BuildHeapify(int arr[] , int n ){
    for(int i{n/2 -1}; i >= 0; --i)
        Heapify(arr , n , i);
}
void HeapSort(int arr[] , int n){
    BuildHeapify(arr,n);
    
    for(int i{n-1} ;i >= 0; --i){
        swap(arr[i] , arr[0]);
        Heapify(arr , i ,0);
    }
}
int main(){
  int arr[]{2,4,6,8,15,1,34,8};
  HeapSort(arr,8);
  int n = sizeof(arr) / sizeof(arr[0]);
  
   for(int i{0}; i< n; ++i){
      cout << arr[i] << " ";
  }
   cout << endl;
   cout<<"Hello World!"<<endl; 
    
	return 0;
}
