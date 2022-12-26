#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

template<class T1 ,class T2>
 class my_pair {
public:
     T1 first;
     T2 second;
};

template<>
class my_pair <string , int> {
public:
     string first;
     int second;
};
 


class HashTable{
private: 
    int size{};
    my_pair<string , int> **data {nullptr};
   static int index;
   
public:
 HashTable(int size_val)
  :size{size_val} {
      *data = new my_pair<string , int> [size]; 
  }
    int Hash (string key){
    return size % key.length();
    
    }
    void set(string key , int value){
    *(*data + Hash(key)) = my_pair <string,int> {key ,value};
    }
      int get(string key){
      return *(*data + Hash(key)).second; 
    }
//     operator[]= (const string &key , const int &value){
//         Hash()
//         data[Hash(key)] = value ;
//    }
    
};
//static int index = {0};

int main(){
 HashTable hash {15};
 hash.set("grapes" , 15);
 cout <<  hash.get("grapes") << endl;
 
   cout<<"Hello World!"<<endl; 
    
	return 0;
}
