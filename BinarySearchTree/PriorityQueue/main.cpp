#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Node{
public:
    int value;
    int priority;
    Node *next;
    
    Node(int value_val, int priority_val)
      :value{value_val},priority{priority_val},next{nullptr}{}
};

class my_priority_queue{
private:
    Node *first;
    
public:
    my_priority_queue()
     :first{nullptr}{}
     
     void enqueue(int value , int priority){
         Node *newNode = new Node(value , priority);
         if(first == nullptr || priority < first -> priority){
             newNode -> next = first;
             first = newNode;
             return;
         }
         
         Node *temp = first;
         
         while(temp -> next != nullptr && priority >= temp -> priority){
             temp = temp -> next;
         }
        
             newNode -> next = temp -> next;
             temp -> next = newNode;
         }
        
     
     void pop(){    //remove the front o(1)
         if(first == nullptr){
             cout << "Empty Queue!/n";
             return;
         }
         else {
           Node *temp = first;
            first = first -> next;
            free(temp);
         }
     }
     
     void dequeue(){   //remove the highest priority element on the queue
        if(first == nullptr){
             cout << "Empty Queue!/n";
             return;
         } 
         Node *temp = first;
           while(temp -> next -> next != nullptr){
               temp = temp -> next;
           }
            free(temp -> next);
            temp -> next = nullptr;
    }
       
     
    
    void display(){
        Node *temp = first;
        while(temp != nullptr){
            cout << temp -> priority <<" " << temp -> value <<"\t";
            temp = temp -> next;
        }
         cout <<"\n";
    }
};
int main(){

     my_priority_queue p;
    p.enqueue(10, 3);
    p.enqueue(20, 2);
    p.enqueue(40, 1);
    p.enqueue(50, 4);
    
    p.display();
    //p.pop();
    p.dequeue();
    p.display();
	return 0;
}
