#include <iostream>
#include <vector>
#include <string>
#include <set>


using namespace std;
vector <int> MergeSortedArrays1( const vector<int> &array1 , const vector <int> &array2){
    multiset <int> merged_multiset; 
    vector <int> merged_sorted_array;
    
    if(array1.size() == 0)
        return array2;
    else if (array2.size() == 0)
         return array1;
         
    else{
    for(size_t i{0} ; i < array1.size() ; ++i)
        merged_multiset.insert(array1.at(i));
        
    for(size_t i{0} ; i < array2.size() ; ++i)
        merged_multiset.insert(array2.at(i));
    
    for(auto elem: merged_multiset)
        merged_sorted_array.push_back(elem);
        
    return merged_sorted_array;
    }
}
    
vector <int> MergeSortedArrays2( const vector<int> &array1 , const vector <int> &array2){
    multiset <int> merged_multiset; 
    vector <int> merged_sorted_array;
    
    if(array1.size() == 0)
        return array2;
    if (array2.size() == 0)
         return array1;
         
    int n1 =  array1.size();
    int n2 = array2.size();
    int n = (n1 > n2) ?  n1 :  n2;
   
   int i{0};
   while( i < n){
       if(i < n1)
           merged_multiset.insert(array1.at(i));
           
       if(i < n2)
           merged_multiset.insert(array2.at(i));
           
       ++i;
   }
    
    
    for(auto elem: merged_multiset)
        merged_sorted_array.push_back(elem);
        
    return merged_sorted_array;
    }


vector <int> MergeSortedArrays3( const vector<int> &array1 , const vector <int> &array2){
    multiset <int> merged_multiset; 
    vector <int> merged_sorted_array;
    
    if(array1.size() == 0)
        return array2;
    if (array2.size() == 0)
         return array1;
         
    int n1 =  array1.size();
    int n2 = array2.size();
    
    int i {0};
    int j {0};
    
    int ArrayElement1{array1[0]};
    int ArrayElement2{array2[0]};
    
  //vector <int> arr1 {0,2 , 5 , 6} ;
  //vector <int> arr2 {1,3,4};
    
    while((i < n1) || (j < n2)){
        if( (j >= n2) || ArrayElement1 < ArrayElement2){
            merged_sorted_array.push_back(array1[i]);
            ++i;
            ArrayElement1 = array1[i];
        }
        else {
            merged_sorted_array.push_back(array2[j]);
            ++j;
            ArrayElement2 = array2[j];
            
        }
    }
   
    return merged_sorted_array;
    }

void display_array( const vector<int> &vec){
    cout <<"[";
    for(const auto &elem: vec)
        cout << elem <<" ";
    cout << "]";
}


int main(){
  vector <int> arr1 {0,2,3,31 , 60 , 70} ;
  vector <int> arr2 {1,3,4};
  
//  display_array(MergeSortedArrays1(arr1 , arr2));
//  cout << endl;
//  display_array(MergeSortedArrays2(arr1 , arr2));
//  cout << endl;
  display_array(MergeSortedArrays3(arr1 , arr2)); //{0,3,4,4,30,31}
  
   
    
	return 0;
}
