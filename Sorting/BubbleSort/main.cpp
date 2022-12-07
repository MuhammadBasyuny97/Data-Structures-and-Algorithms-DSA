#include <iostream>
#include <vector>
#include <string>


using namespace std;
//======MyApproach(More efficiently than for loop Approach )=====
template <class T>
auto Sort(vector<T> &vec){
    int counter{1};
    int outer_loops{0};
    while(counter != 0){  //if counter is 0 that's mean the if condition is always false and the vector is sorted so the loop terminated
        counter = 0;
        auto current = vec.begin();
        auto next = (current + 1);
      while(next != vec.end()){
          if(*current > *next){  //if vector is sorted then if condition is always false and counter is 0 and loop terminated
              swap(*current, *next);
              ++counter;
          } 
         current = next;
         next = (current + 1); 
    }
    ++outer_loops;
    }
    return vec;
}

//==========Another Approach ===============
template <class T>
auto Sort2(vector<T> &vec){
  int length{vec.size()};
   for(int i {0} ; i < length; ++i){
       for(int j{0}; j < length -1; ++j){
           if(vec[j] > vec[j+1]){
           //swap items
           T temp = vec[j];
           vec[j] = vec[j+1];
           vec[j+1] = temp;
       }
    } 
  }
    return vec;
}

//===================================
template <class T>
int Sort3(vector<T> &vec){
    int counter{1};
    int outer_loops{0};
    while(counter != 0){  //if counter is 0 that's mean the if condition is always false and the vector is sorted so the loop terminated
        counter = 0;
        auto current = vec.begin();
        auto next = (current + 1);
      while(next != vec.end()){
          if(*current > *next){  //if vector is sorted then if condition is always false and counter is 0 and loop terminated
              swap(*current, *next);
              ++counter;
          } 
         current = next;
         next = (current + 1); 
    }
    ++outer_loops;
    }
    return outer_loops;
}

//=====================
template <class T>
int Sort4(vector<T> &vec){
  int length{vec.size()};
   for(int i {0} ; i < length; ++i){
       for(int j{0}; j < length -1; ++j){
           if(vec[j] > vec[j+1]){
           //swap items
           T temp = vec[j];
           vec[j] = vec[j+1];
           vec[j+1] = temp;
       }
    } 
  }
    return (length -1) ;
}



template <class T>
void display(vector<T> vec){
    cout << "[ ";
    for(auto c: vec)
        cout << c << " ";
    printf("]\n");
}

int main(){
  vector <int> vec{6,5,3,1,8,7,2,4,74,34,90,121,74,15,0,2,4,7,9};
  display(vec);
  cout << "Number of Outer For loops is: " << Sort4(vec) << endl;
  display(vec);
  cout << "Number of Outer While loops is: " << Sort3(vec) << endl;
  display(vec);
   cout << "Hello World!"<<endl; 
    
	return 0;
}
