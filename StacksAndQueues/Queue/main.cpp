#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct Node{

    int value;
    Node *next;
  Node(int value_val)
   :value{value_val}, next{nullptr}{}
};

class Queue{
private:
    int length;
    Node *bottom;
    Node *top;
   
public:
   Queue()
    :length{0}, bottom{nullptr}, top{nullptr}{}
    
    void enqueue(int value){
        Node *newNode = new Node (value);
        if(length == 0){
            bottom = newNode;
            top = newNode;
        }
        else{
            top -> next = newNode;
            top = newNode;
        }
        ++length;
    }
    
    void dequeue(){
        if(length == 0){
            cout << "Empty Queue - Please add elements\n";
            return;
        }
        if(length == 1){
            top = nullptr;
        }
        Node *temp = bottom -> next;
        free(bottom);
        bottom = temp;
        --length;
    }
    
    
    int peek(){
        if (length == 0){
            cout << "Empty Queue - please add any elements\n";
            return -1;
        }
        return bottom -> value;
    }
    
    bool isempty(){
        return (length == 0);
    }
    
    int size(){
        return length;
    }
    void display(){
        cout << "[";
        if(!isempty()){
        Node *current = bottom;
        while(current != nullptr){
            cout << current -> value <<" ";
            current = current -> next;
        }
        }
        cout << "]\n";
            
            
    }
    
};
int main(){

   Queue q;
   q.enqueue(10);
   q.enqueue(20);
   q.enqueue(30);
   
   q.display();
   q.dequeue();
   q.display();
    
	return 0;
}
