#include <iostream>
#include <vector>
#include <string>


using namespace std;

template <class T>
auto SelectionSort(vector<T> &vec){
  size_t length {vec.size()};
  int smaller{vec[0]};
  int index{0};
   for(size_t i {0} ; i < length; ++i){
       smaller = vec[i];
       for(size_t j {i} ; j < length ; ++j){
           if(vec[j] <= smaller){
             smaller = vec[j];
             index = j;
       }
    }
   if(i != index) 
    swap(vec[i] , vec[index]);
  }
    return vec;
}


template <class T>
void display(vector<T> vec){
    cout << "[ ";
    for(auto c: vec)
        cout << c << " ";
    printf("]\n");
}


int main(){
   vector <int> vec{6,5,3,1,8,7,2,4,74,34,90,121,74,15,0,2,4,7,9,0};
   display(vec);
   SelectionSort(vec);
   display(vec);
   cout<<"Hello World!"<<endl; 
    
	return 0;
}
