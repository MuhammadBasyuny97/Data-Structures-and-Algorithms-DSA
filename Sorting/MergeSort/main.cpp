#include <iostream>
#include <vector>
#include <string>


using namespace std;

//template <class T>
vector <int> merge(vector <int>, vector <int> );


//template <typename T>
vector <int> mergeSort(vector <int> &vec){
    size_t length {vec.size()};
    size_t n {length / 2};
    
    if(length == 1)
        return vec;
    vector <int> left;
    vector <int> right;
    for(size_t i{0} ; i < n ; ++i){
        left.push_back(vec[i]);
    }
    for(size_t i{n} ; i < length ; ++i){
        right.push_back(vec[i]);
    }
    
    return vec = merge(mergeSort(left),mergeSort(right));
}

//template <typename T>
vector <int> merge(vector <int> left, vector <int> right){
    size_t lower{left.size()};
    size_t upper {right.size()};
    
    vector <int> result;
    
    
    if(upper == 1){
        result.push_back(left[0]);
        result.push_back(right[0]);
        if(left[0] > right[0])
            swap(result[0] , result[1]);
    }
    else {
    size_t i{0};
    size_t j{0};
    while( i < lower){
        if(left[i] < right[j]){
            result.push_back(left[i]);
            ++i;
        }
        else{
            if(j == upper)
                break;
            result.push_back(right[j]);
            ++j;
        }
    }
    for(i ; i < lower ; ++i ){
        result.push_back(left[i]);
    }
    for(j ; j < upper ; ++j ){
        result.push_back(right[j]);
    }
  }
    
    return result;
}

template <class T>
void display(vector<T> vec){
    cout << "[ ";
    for(auto c: vec)
        cout << c << " ";
    printf("]\n");
}


int main(){
   vector<int> numbers {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
   vector <int> numbers2{10, 9, 8, 7, 6, 5, 5, 4, 4, 3, 3, 2, 1, 1};
   display(numbers);
   mergeSort(numbers);
   display(numbers);
   
   cout<<"Hello World!"<<endl; 
    
	return 0;
}
