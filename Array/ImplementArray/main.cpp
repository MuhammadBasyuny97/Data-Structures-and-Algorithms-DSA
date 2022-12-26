#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>


using namespace std;

template <class T>
class DynamicArray{
private:
    int length;
    int capacity;
    T *data;
    
  
public:
    DynamicArray()
     :length{0}, capacity{2} {data = new T[capacity] ;}
     
    T at(int i){     //exception handling or bounds checking
    try{
        if(i >= 0 && i <= length-1)
            return data[i];
        else
            throw ("Couldn't access, Out of range\n" );
            
    }
    catch(string &ex){
     cerr << ex ;  
     return 1;
    }
}

~DynamicArray(){delete [] data;}
    
    int size(){
        return length;
    }

    
    
    T *push(const T &item){
        

       if(length == capacity){
           capacity *= 2;
           T *temp  = new T [capacity];
           for(int i {0} ; i < length ; ++i)
               temp[i] = data[i];
            delete []data;
            data = temp;
            
       }
         data[length] = item;
         (this -> length)++;
       return (data + length-1);
        
    }
    
    T *push(const int &i , const T &item){
        
     if(i == capacity)
       push(item);
       
     else
        data[i] = item;
        
    return (data + i);
    
    }
    
    T *insert ( const int &index , const T &item){
        for(int i{length-1} ; i >= index ; --i)
            data[i+1] = data[i];
            
        data [index] = item;
        ++length;
        
        return (data+index);
        
    }   
    
    T pop(){
         T lastItem = data[length-1];
         length--;
         return lastItem;
    }
    void erase (const int &index){
        for(int i{index} ; i < length-1 ; ++i)
            data[i] = data[i+1];
        length--;
    }
    
    ///////////////////////////////////////////
    void  clear(){
        delete data;
        length = 0;
    }
    
     bool empty(){
        return (length == 0 );
    }
    T operator[](const int &i){  //Overloading subscript operator
        return data[i];
    }
    
    
  void print() const{
      cout <<"[ ";
      for(int i {0} ; i < length ; ++i)
          cout << data[i] << " ";
      cout <<"]\n";
  }    
};  
 

int main(){
  DynamicArray<int> arr;
  cout << arr.size() << endl;
  arr.push(15);
  arr.push(20);
  cout << arr.size() << endl;
  arr.insert(1,30);
  cout << arr.at(1) << endl;
  cout << arr.at(2) << endl;
  arr.print();
  arr.erase(1);
  cout << arr.at(1) << endl;
  arr.print();
  
  
  
  
  
  
   //cout<<"Hello World!"<<endl; 
    
	return 0;
}
