#include <iostream>
#include <vector>
#include <string>


using namespace std;

int recurring (const vector<int> &vec){
    for(size_t i{0}; i < (vec.size() - 1); ++i){
        for(size_t j{i+1} ; j < vec.size(); ++j){
            if(vec[i] == vec[j])
                return vec[i];
            else if (vec[j] == vec[j+1])
               return vec[j];
        
        }
    }
    cout << "Undefined" << endl;
    return NULL; 
}


int main(){

  vector<int> vec{2,4,5,5,2,1,3,9};
  cout << recurring(vec) << endl;


 
	return 0;
}
