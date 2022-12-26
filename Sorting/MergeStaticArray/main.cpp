#include <iostream>
#include <vector>
#include <string>


using namespace std;
 void merge(int arr[] , int low , int high);
 
 void mergeArray(int arr[] , int low ,int mid, int high){
   // int n = sizeof(arr) / sizeof(arr[0]);
    
   // int mid = low +(high -1) / 2;
    int size1{mid - low + 1 };
    int size2{high - mid };
    
    int left[size1] , right[size2];
    
    for(int i{0} ; i < size1; ++i){
        left[i] = arr[low + i];
    }
    for(int j{0} ; j < size2; ++j){
        right[j] = arr[mid +1 + j];
    }
    
    int i{0};
    int j{0};
    int k{low};
    
    while(i < size1 && j < size2){
        if(left[i] < right [j]){
            arr[k] = left[i];
            ++i;
       }
        else{
            arr[k] = right[j];
            ++j;
       }
       ++k;
    }
    
    while(i < size1 ){
            arr[k] = left[i];
            ++i;
            ++k;
       }
    while(j < size2 ){
            arr[k] = right[j];
            ++j;
            ++k;
       }
 }

void merge(int arr[] , int low , int high ){
   
   if(low < high){
       int mid = low +(high -low) / 2;
       merge(arr , low , mid);
       merge(arr , mid+1 , high);
       mergeArray(arr, low, mid,high);
   }
   
   
}
int main(){
    int arr[] = {30,20,40,5,90,80,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << n << endl;
    merge(arr, 0, n-1);

    cout<<"Sorted Array is: "<<endl;
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<"  ";
    }
  
    
	return 0;
}
