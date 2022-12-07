#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct HashNode{
    
    int key;
    int value;
    
    HashNode() = default;
    HashNode(int key_val , int value_val)
     :key{key_val}, value{value_val}{}
   
};

class HashTable {
private:
    HashNode **arr;
    const int array_size {128};
   // int array_size;
public:
    HashTable()
      {
         arr = new HashNode* [array_size];
        for (int i {0}; i < array_size; ++i){
            arr[i] = NULL ;
        }
    }
    int HashFunction(int key){
        return key % array_size;
    }
    
    void InsertElement(int key , int value){
        int h = HashFunction(key);
        while(arr[h] != NULL && arr[h] -> key != key){
            h = HashFunction (h + 1);
        }
        if(arr[h]  == NULL){
              delete arr[h];
              arr[h] = new HashNode(key , value);
        }
    
        
    }
    
    
    int get(int key ){
        int h = HashFunction(key);
        while(arr[h] != NULL && arr[h] -> key != key){
            h = HashFunction (h + 1);
        }
        
        if(arr[h]  != NULL)
              return arr[h] -> value;
        else 
            return -1;
        
        
        }
    
        
    
    int SearchKey (int key){
        int h = HashFunction(key);
        while(arr[h] != NULL && arr[h] -> key != key){
            h = HashFunction(h+1);
        }
        if(arr[h] == NULL)
           return -1;
        else
            return arr[h] -> value;
    } 
    
    void Remove (int key){
        
        int h = HashFunction(key);
        while(arr[h] != NULL){
            if(arr[h] -> key == key){
               break;
            }
            h = HashFunction(h+1);
        }
        if(arr[h] == NULL)
            cout << key << " Not Found " << endl;
        else{
            cout << "Element " <<arr[h] -> key << " is deleted\n";
            delete arr[h];
            
        }
    }
    
    ~HashTable(){
        for(int i {0}; i < array_size; ++i){
            if(arr[i] != NULL)
                delete arr[i]; 
        }
       delete [] arr;
    }
    void display(int key){
        int h =HashFunction(key);
        cout << "Key:" << arr[h] -> key << "  Value:" << arr[h] -> value << endl;
    }
    
    void display(){
        for (int i{0} ; i < array_size; ++i){
            if(arr[i] != NULL)
                cout << "Key:" << arr[i] -> key << "  Value:" << arr[i] -> value << endl;
        }
    }
    
    int FirstRecurringElement (const vector<int> &vec){
        for(size_t i{0}; i < vec.size(); ++i){
            int h = HashFunction(vec[i]);
            while(arr[h] != NULL && vec[i] != arr[h] -> key){
                h =  HashFunction (h + 1);
            }
            if(arr[h] == NULL){
                delete arr[h];
                arr[h] = new HashNode (vec[i] , vec[i]);
            }
        
            else{
                return vec[i];
              
          }
    }
    cout << "Undefined" << endl;
     return -1;
    }
    
    
};

int main(){
  HashTable h;
  
//    h.InsertElement(1,1);
//    h.InsertElement(2,15);
//    h.InsertElement(13,3);
//    h.InsertElement(2,8);  // note then when displayed the value of key->2 should be only 8.
//    h.InsertElement(12,21);
//    

 vector <int> vec{1,0,4,5,2,3,10,12};
 cout <<  h.FirstRecurringElement(vec) << endl;
//   cout <<  h.SearchKey(13) << endl;
//   cout <<  h.get(5) << endl;
    
    
    
    //h.display(2);
   // h.display();
   // h.Remove(13);
    //cout<<h.get(2);
  
  
  
    
	return 0;
}
