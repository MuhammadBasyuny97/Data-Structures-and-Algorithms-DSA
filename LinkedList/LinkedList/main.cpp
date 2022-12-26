#include <iostream>
#include <vector>
#include <string>
#include <exception>



using namespace std;

class Out_Of_Range :public exception {
    public:
    Out_Of_Range()noexcept = default ;
    ~Out_Of_Range() = default;
    
   virtual const char* what() const noexcept override{
       return "Out of Range";
   }
    
};


struct Node {
    int item;
    Node *next;
    static int length;
    
public:
    Node(int item_val)
     :item{item_val}, next{nullptr}{
           ++length;
         }
         
    
 
};

 int Node::length = 0;
 
class MyLinkedList{
    
public:
    Node *head;
    Node *tail;
    MyLinkedList()
     :head{nullptr}, tail{nullptr}{}
     
     void push_front (int item){
         Node *vtx = new Node(item);
         vtx -> next = head;
         
         if(head == nullptr){
             head = vtx;
             tail = head;
         }
         else
             head = vtx;
         
     }
     
     void push_back (int item){
         Node *vtx =  new Node (item);
         if(head == nullptr){
             head = vtx;
             tail = vtx;
         }
         tail -> next = vtx;
         tail = vtx;
         
     }
     
     void insert(int index , int item ){
         if(index == 0)
             push_front(item);
             
         else if(index >= Node::length)
             push_back(item);
             
         else{
            Node *temp_index = head -> next;
            Node *temp = nullptr;
            Node *temp_back = head;
            
            int i{1};
            while(i != index){
                temp_back = temp_index;
                temp_index = temp_index -> next;
                ++i;
            }
            
            temp = new Node(item);
            temp -> next = temp_index;
            temp_back -> next = temp;
            
        }
     }
     
     void remove_element(int index ){
         if(index == 0)
             pop_front();
             
         else if(index == Node::length-1)
             pop_back();
         
         else if (index == Node::length){
             cout << "Can't find element, out of bounds element\n";
         }
             
         else{
            Node *temp_index = head -> next;

            Node *temp_back = head;
            
            int i{1};
            while(i != index){
                temp_back = temp_index;
                temp_index = temp_index -> next;
                ++i;
            }
            
            temp_back -> next = temp_index -> next;
             delete temp_index;
             --Node::length;
        }
     }
     
     void pop_front(){
        if(head == nullptr)
            return;
        else{
         Node *temp = head -> next;
         delete head;
         head = temp;
         --Node::length;
        }
     }
     
     void pop_back(){
         if(tail == nullptr && head == nullptr)
             return;
         else{
             Node *temp = head;
             while( temp != nullptr){
                 tail = temp;
                 temp = temp -> next;
                 if(temp -> next == nullptr)
                     break;
             }
             delete temp;
             tail -> next = nullptr;
             --Node::length;
            
         }
     }
     
     int at(int index){
       
         try{ 
         if (index >= Node::length)
             throw Out_Of_Range();
                
         else {
            Node *temp_index = head;
            int i{0};
            while(i != index && index < Node::length){
                temp_index = temp_index -> next;
                ++i;
            }
           return (temp_index -> item);
        }
         }
         catch (const Out_Of_Range &ex){
              cerr << ex.what() << endl;
              return -1;
          }
        
         }
         
     int find(int item)   {
         Node *temp = head;
         int i{0};
         while(temp -> item != item ){
             if(temp -> next == nullptr)
                 break;
            temp = temp -> next;
             ++i;
         }
         
         if(temp -> item == item)
             return i;
             
         cout << "Not Found - Out of Range" << endl;
         return -1;
     }
    void display(){
        Node *temp = head;
        for(int i{0}; i < Node::length; ++i){
            cout << temp -> item <<" ---> ";
            temp = temp -> next;
        }
        cout <<"NULL\n";
    } 
    Node *lookup(int index){
        Node *Current = head;
        for(int i{0} ; i < index; ++i){
            Current = Current -> next;
        }
            
        return Current;
    }
         
    void reverse1(){
        if(Node::length == 0)
            return;
        else{
            Node *current = tail;
            tail = head;
            head = current;
            
            Node *prev_current =nullptr;
            for(int i{Node::length -1 }; i > 1; --i){
                prev_current = lookup(i-1);
                current -> next = prev_current;
                current = prev_current;
            }
            tail -> next = nullptr;
        }
    } 
    
    void reverse(){
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
     
     int size(){
         return Node::length;
     }
     
     
     
};

//int main(){
// 
//    MyLinkedList linked;
//    linked.push_front(10);
////    linked.push_front(15);
////    cout << (linked.head) ->item << endl;
////    linked.pop_front();
////    cout << (linked.head) ->item << endl;
//    linked.push_back(20);
//    cout << linked.size() << endl;
//   // linked.pop_back();
//    cout << (linked.head) -> item << endl;
//    cout << (linked.tail) -> item << endl;
//    linked.pop_back();
//    cout << (linked.head) -> item << endl;
//    cout << (linked.tail) -> item << endl;
//    
//    cout << linked.size() << endl;
//    
//    linked.insert(1, 15);
//    cout << linked.size() << endl;
//    cout << (linked.head) -> item << endl;
//    cout << (linked.tail) -> item << endl;
//    linked.insert(1, 30);
//    
//    cout << linked.size() << endl;
//    linked.delete_item(2);
//    cout << (linked.head) -> item << endl;
//    cout << (linked.tail) -> item << endl;
//    cout << linked.size() << endl;
//    
//    cout << linked.at(1) << endl;
//    cout << linked.at(0) << endl;
//    cout << linked.at(2) << endl;
//    
//    linked.display();
//    
//    cout << linked.find(50) << endl;
//    
//
//    
//    
//    
//    
//  // cout<<"Hello World!"<<endl; 
//    
//	return 0;
//}

//==================================================================

int main()
{
    MyLinkedList l;
    // appending elements
    cout << "Appending Node:" << endl;
    l.push_back(2);
    l.push_back(4);
    l.push_back(6);
    l.push_back(8);
    l.push_back(10);

    // displaying elements
    l.display();

    cout << "Inserting Node:" << endl;

    l.insert(2, 3);
    l.display();
    l.insert(0, 1);
    l.display();

    cout << "Delete Node:" << endl;
    l.remove_element(3);
    l.remove_element(0);
    l.remove_element(4);

    l.display();
//
//    cout << "Get Node: 2" << endl;
//    cout << l.find(2) << endl;
//
//    cout << "Find Node 8:" << endl;
//    cout << l.find(8) << endl;
//cout << l.lookup(2) -> item << endl;
    l.reverse();
    l.display();

    return 0;
}