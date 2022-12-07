#include <iostream>
#include <vector>
#include <string>


using namespace std;
void swap(int *x ,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
 int Partitioning(int arr[], int low, int high){
    int pivot{high};  //current pivot index
    int i {low}; //index of array element
    
    while(i < pivot){
        if(arr[pivot] < arr[i]){
           if(pivot > i+1){
               swap(&arr[pivot] ,&arr[pivot-1]);
               --pivot;
               swap(&arr[pivot+1] ,& arr[i]);
           } 
           else{
               swap(&arr[pivot] , &arr[i]);
               --pivot;
           }
        }
        else{
           ++i;
       }
    }
    
    return pivot;
}
  
  

 void QuickSort(int arr[] , int low , int high){
    if( low < high){
       int prev_pivot = Partitioning(arr,low,high);
        QuickSort(arr, low , prev_pivot-1);
        QuickSort(arr, prev_pivot+1 ,high);
    }
}
int main(){
  int arr[] { 2,-1,4,7,0};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  for(int i{0}; i< n; ++i){
      cout << arr[i] << " ";
  }
  cout << endl;
  
  QuickSort(arr,0,n-1);
  
  for(int i{0}; i< n; ++i){
      cout << arr[i] << " ";
  }
   cout << endl;
  
   cout<<"Hello World!"<<endl; 
    
	return 0;
}
