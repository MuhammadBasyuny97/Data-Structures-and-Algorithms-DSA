#include <iostream>
#include <vector>
#include <string>



using namespace std;
template <class T>
auto Sort(vector<T> &vec){
    for(size_t i{0}; i < vec.size() -1; ++i){
        if(vec[i] > vec [i+1]){
            swap(vec[i] , vec [i+1]);
            
            for(size_t j{i}; j > 0; --j){
                if(vec[j] < vec[j-1])
                    swap(vec[j] , vec[j-1]);
            }
        }
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
  vector <int> vec{6,5,3,7,2,4,0,1};
  display(vec);
  Sort(vec);
  display(vec);
   cout<<"Hello World!"<<endl; 
    
	return 0;
}
