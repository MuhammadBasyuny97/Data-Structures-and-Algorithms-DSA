#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node(int value_val)
     :value{value_val},next{nullptr}{}
};

class Stack{
private:
    Node *top;
    int length;
public:
 Stack()
  :top{nullptr},length{0}{}
  
  void push(int value){
      Node *newNode = new Node {value};
      if(top == nullptr){
      top = newNode;
      }
      else{
         newNode -> next = top;
          top = newNode;
      }
      length++;
  }
  
  void pop(){
      Node *current = top;
      if(top == nullptr)
          return;
          
     if(top -> next == nullptr){
              free(top);
              top = nullptr;
          }
     else{
              top = top -> next;
              free(current);
          }
           --length;
      } 
     
  
  
  int peak(){
      if(top == nullptr)
          return -1;
      else
          return top -> value;
  }
  
  int size(){
      return length;
  }
  
  void empty(){
      if(top == nullptr)
          return;
      else{
         Node *current = top;
         while(current != nullptr){
             current = top -> next;
             free(top);
             top = current;
             --length;
         }
     }
  }
    void display(){
        Node *current = top;
        cout << "[ ";
       while(current != nullptr){
            cout << current -> value << " ";
            current = current -> next;
        }
        cout << "]\n";
    }
};

int main(){

    
   Stack s;
   s.push(10);
   s.push(20);
   s.push(30);
   s.pop();
  
   cout << s.peak() << endl;
   s.empty();
   cout << s.size() << endl;
   
   cout<<"Hello World!"<<endl; 
   s.display();
    
	return 0;
}
