#include <iostream>
#include <vector>
#include <string>


using namespace std;

 void reverse(){  //Using Singly Linked List
        if(Node::length <= 1)
            return;
        Node *first = head;
        Node *second = first -> next;
        head = tail;
        tail = first;
        
        while(second != nullptr){
            Node *temp;
            temp = second -> next;
            second -> next = first;
            first = second;
            second = temp;
        }
        tail -> next = nullptr;
    }
    
    
    void reverse1(){  // Using Doubly Linked List
        if(length == 0)
            return;
        Node *Current = tail;
        tail = head;
        head = Current;
        Node *prev_current = Current -> prev;
        
        for(int i{length -1}; i > 0 ; --i){
            Node *prev_prev = prev_current -> prev;
            Current -> next = prev_current;
            prev_current -> prev = Current;
            Current = prev_current;
            prev_current = prev_prev;
        }
        tail -> next = nullptr;
        head -> prev = nullptr;s
    }
int main(){

   cout<<"Hello World!"<<endl; 
    
	return 0;
}
