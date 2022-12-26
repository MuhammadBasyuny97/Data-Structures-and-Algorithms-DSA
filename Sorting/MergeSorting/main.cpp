#include <iostream>
#include <vector>
#include <string>

//Optimal and efficient merge sort for log(n) == integer (2,4,8,16,32,64,so forth)
using namespace std;
void Left(vector<int> &vec , size_t i , size_t k){
    size_t n {vec.size() /2};
    if( i == n ){
        k *= 2;
        i = 0;
    }
    if(k == n)
        return;
        
    if(k == 1 && vec[i] > vec[i+k])
        swap(vec[i] , vec[i+k]);
    else if (k > 1){
        size_t j{0};
        while (j < k){
            if(vec[i+j] > vec[i+k]){
                swap(vec[i+j] , vec[i+k]);
                 if(vec[i+k] > vec[i+k+1])
                     swap(vec[i+k] , vec[i+k+1]);
            }
            ++j;
        }
    }
    i += 2*k;
    return Left(vec, i , k);
}

void Right(vector<int> &vec , size_t i , size_t k){ //i = vec.size()/2;
    size_t n {vec.size()};
    if( i == n ){
        k *= 2;
        i = n/2;
    }
    if(k == n/2)
        return;
        
    if(k == 1 && vec[i] > vec[i+k])
        swap(vec[i] , vec[i+k]);
    else if (k > 1){
        size_t j{0};
        while (j < k){
            if(vec[i+j] > vec[i+k]){
                swap(vec[i+j] , vec[i+k]);
                 if(vec[i+k] > vec[i+k+1])
                     swap(vec[i+k] , vec[i+k+1]);
            }
            ++j;
        }
    }
    i += 2*k;
    return Right(vec, i , k);
}

void Merge(vector<int> &vec , size_t i , size_t k){
   // size_t n{vec.size()/2};
        size_t j{0};
        size_t t{0};
        while (j < k){
            if(vec[i+j] > vec[i+k]){
                swap(vec[i+j] , vec[i+k]);
                 while(vec[i+k+t] > vec[i+k+t+1] && t < k-1){
                     swap(vec.at(i+k+t) , vec.at(i+k+t+1));
                     ++t;
                 }
            }
            t = 0;
            ++j;
        }
    }


auto MergeSorting(vector<int> &vec){
  size_t n {vec.size()/2};
  Left(vec , 0 , 1);
  Right(vec , n , 1);
  Merge(vec , 0 , n);

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
  vector <int> vec{6,5,3,7,24,700,800,900,2,4,0,1};
  display(vec);
  MergeSorting(vec);
  display(vec);
   cout<<"Hello World!"<<endl; 
    
	return 0;
}