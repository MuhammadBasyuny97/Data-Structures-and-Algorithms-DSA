#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct Node{
    int item;
    Node *next;   //reference to next node
    Node *prev;   //reference to previous node 
    
    Node(int item_val)
     :item{item_val}, next{nullptr}, prev{nullptr}{}
};

class DoublyLinkedList{
public:
    Node *head;
    Node *tail;
    int length;
    
public:  
    DoublyLinkedList()
    :head{nullptr},tail{nullptr}, length{0}{}
    
    
    void Preappend(int item){
        Node *newNode = new Node(item);
        newNode -> next = head;
        
        if(length == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            head -> prev = newNode;
            head = newNode;
        }
        ++length;
    }
    
    void append (int item){
        Node *newNode = new Node (item);
        newNode -> prev = tail;
        
        if(length == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        length++;
    }
    
    void pop_back(){
        Node *temp_node = tail -> prev;
        if(length == 0)
            return;
        else{
            free(tail);
            tail = temp_node;
            tail -> next = nullptr;
            --length;
        }
    }
    
    void pop_front(){
        if(length == 0 )
            return;
        else{
            head = head -> next;
            free(head -> prev);
            head -> prev = nullptr;
        }
        --length;
    }
    
    Node* traverse (int index){
        Node *traversal = head;
        int i{0};
        while(i != index){
            traversal = traversal -> next;
            ++i;
        }
        return traversal;
    }
    
    void insert(int index , int item){
        if (index < 0){
            cout << "Negative Index, Please Enter valid index\n";
            return;
        }
        else if(index == 0){
            Preappend(item);
            return;
        }
        else if (index >= length){
            append(item);
            return;
        }
            
        else{
            Node *NewNode = new Node(item);
            Node *Current = traverse(index);
            
            NewNode -> next = Current;
            NewNode -> prev = Current -> prev;
            Current -> prev -> next = NewNode;
            Current -> prev = NewNode;
        }
        ++length;
    }
    
    void remove (int index){
        if(index == 0)
            pop_front();
        else if (index >= length)
            pop_back();
        else if (index < 0 || index >= length){
            cout << "Cannot delete: out of bounds element\n";
            return;
        }
        else{
          Node *Current = traverse(index);
          Current -> prev -> next = Current -> next; 
          Current -> next -> prev = Current -> prev;
          free(Current);
          --length;
        }
    }
    
    int at(int index){
        if(index == 0)
            return head -> item;
        else if(index == length-1)
            return tail -> item;
        else if(index > 0 && index < length)
            return(traverse(index) -> item);
        else{
            cout << "Not Found element, Enter valid index\n";
            return -1;
        }
    }
    
    int find(int item){
        int i{0};
         Node *Current = head;
        if(head -> item == item)
            return 0;
        else if (tail -> item == item)
            return (length-1);
        
        else{
            
           
            while(Current -> item != item){
                if(Current -> next == nullptr){
                    cout << "Not Found\n";
                    return -1;
                }
                Current = Current -> next;
                ++i;
            }
              
        }  
                return i;
    }
    
    void display(){
        Node *Current = head;
        for(int i {0}; i < length; ++i){
            cout << Current -> item <<"-->";
            Current = Current -> next;
        }
        cout << "NULL\n";
    }
    
    void reverselist(){
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
        head -> prev = nullptr;
    }
    
    
    
    
};

//================================================================
//int main(){
//    DoublyLinkedList dl;
//    dl.Preappend(10);
//    cout << dl.head -> item << endl;
//    dl.append(15);
//    cout << dl.tail -> item << endl;
//   // dl.pop_front();
//    dl.insert(1 , 12);
//    cout << dl.tail -> prev-> item << endl;
//    dl.removeNode(1);
//    cout << dl.tail -> prev-> item << endl;
//    cout << "===============" << endl;
//    cout << dl.at(0) << endl;
//    cout << dl.at(1) << endl;
//    cout << dl.find(18) <<endl;
//    dl.display();
//    dl.insert(1,12);
//    dl.insert(2,28);
//    dl.append(34);
//    dl.Preappend(27);
//    dl.display();
//    dl.reverselist();
//    dl.display();
//   cout << "==================\n"; 
//   cout<<"Hello World!"<<endl; 
//    
//	return 0;
//}


//============================================


int main() {
    DoublyLinkedList d;
    d.append(2);
    d.append(1);
    d.append(3);
    d.append(4);
    d.append(5);

    d.Preappend(99);
    d.Preappend(200); //200->99->2->1->3->4->5 # should be an output.

    d.insert(1, 1000);
    d.insert(0, 5000);

    d.display();

    d.remove(3);
    d.display();

    d.reverselist();
    d.display();

    d.remove(5);
    d.display();

    return 0;
}