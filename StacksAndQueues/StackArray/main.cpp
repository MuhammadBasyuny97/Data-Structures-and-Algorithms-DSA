#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Stack{
private:
    int length;
    int *data;
    int capacity;
    
public:
   Stack()
    :length{0}, data{nullptr},capacity{2}{
        data = new int (capacity);
    }
    
    void push(int value){
        if(length == capacity){
           int *temp = new int (capacity*2);
           for(int i{0}; i< length; ++i){
               temp[i] = data[i];
           } 
           delete data;
           data = temp;
            
        }
        data[length] = value;
        length++;
    }
 
   void pop(){
       if(empty())
           return;
           
       data[length-1] = 844546;
       length--;
   }
   
   int peek(){
       if(empty()){
           cout << "Empty Stack - No elements\n";
           return -1;
       }
   return data[length -1]; 
   }
   bool empty(){
       return (length == 0);
   }
   int size(){
       return length;
   }
   
   void display(){
       cout << "[";
       if(!empty()){
       for(int i{length-1}; i >= 0; --i)
           cout << data[i] << " ";
       }
       cout << "]\n";
   }
};
int main(){
 Stack s;
    s.push(12);
    s.push(11);
    s.push(13);
    s.push(33);
    s.push(02);
    s.display();

    s.pop();
    s.display();

    s.push(24);
    s.display();

    cout << "Top most element: " << s.peek() << endl;
	return 0;
}
