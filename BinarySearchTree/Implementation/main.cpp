#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>


using namespace std;

struct Node{
    int value;
    Node *right;
    Node *left;
    
    Node(int value_val)
     :value{value_val}, right{nullptr}, left{nullptr}{}
};


class Tree{
private:
    vector <int> v;
      Node *root;
    int totalnodes;
public:  
    
    Tree()
     :root{nullptr}, totalnodes{0}{
     }
     Node *get_root(){return this -> root;}
     
     void insert (int value){
         if(totalnodes == 0){
             root = new Node (value);
             ++totalnodes;
             return;
         }
             
         Node *current = root;
         Node *parent = nullptr;
         
         while( current != nullptr){
             parent = current;
             if(value > current -> value )
                 current = current -> right;
             else if(value < current -> value )
                 current = current -> left;
             else if(value == current -> value )
                return;
         }
         Node *child = new Node (value);
          if(parent -> value < value )
              parent -> right = child;
          else 
              parent -> left = child;
              
        ++totalnodes;
      }
      
      bool search(int value){
          
          if(totalnodes == 0)
              cout << "Empty tree please insert a node\n";
              
          Node *current = root;
          Node *parent = nullptr;
          int height {0};
          
          while(current != nullptr){
              
              if(current -> value < value){
                  parent = current;
                  current = current -> right;
              }
              else if(current -> value > value){
                  parent = current;
                  current = current -> left;
              }
              else if(current -> value == value)
                  break;
             
             ++height;
          }
          if(current  == nullptr) 
              cout << value << " not found on the tree\n";
          else if (current -> value == value ){
              if (current == root)
                 cout << "Node: " << value << " Found at height " << height << " and its root node\n";
              else
                  cout << "Node: " << value << " Found at height " << height << " and its parent is: "
                   << parent -> value << endl;
            return true;
          }
         
        return false;
      }
      
     //==================Easy Search Method=======================
     bool search2(int value){
          if(totalnodes == 0)
              cout << "Empty tree please insert a node\n";
              
         Node *current = root;
          
          while(current != nullptr){
              if(current -> value < value)
                  current = current -> right;
              else if(current -> value > value)
                  current = current -> left;
              else if (current -> value == value)
                      return true;
          }
          return false;
     }
     
     //==========================Delete===================================
     void remove(int value){

         Node *current = root;
         Node *parent = nullptr;
         while(current != nullptr){
             if(value > current -> value){
                 parent = current;
                 current = current -> right;
             }
             else if(value < current -> value){
                 parent = current;
                 current = current -> left;
             }
             else if(value == current -> value){
                 break;
             }
         }
         
     //=======Unfound Node =============
          if (current == nullptr){
             cout << "Not Found\n";
             return;
          }
        
    //==============Removing Node with no child (Last Node == Leaf Node) ============
         else if(current -> right == nullptr && current -> left ==nullptr){
             
             if(value > parent -> value)
                 parent -> right = nullptr;
             else
                 parent -> left = nullptr;
         }
         
         
    //=========Removing Node with a Child==========
         else if (current -> right != nullptr && current -> left == nullptr){
             if(value > parent -> value)
                 parent -> right = current -> right;
             else 
                 parent -> left = current -> right;
         }
         
         else if(current -> right == nullptr && current -> left != nullptr){
           if(value > parent->value)
               parent -> right = current -> left;
           else
               parent -> left = current -> left;
               
       }

    //=======================Removing Node with two Child ========================
         else if (current -> right != nullptr && current -> left != nullptr){
            Node *replacement = current -> right;
            Node *x = nullptr;
            
    //======Removing Node with two Child and right tail========       
           if(replacement -> left == nullptr){
              replacement -> left = current -> left;
              if(value > parent -> value )
               parent -> right = replacement;
              else
               parent -> left = replacement;
             free(current);
            --totalnodes;
            return;
          }
           while( replacement  != nullptr){
               if(replacement -> left == nullptr)
                  break;
                x = replacement;
                replacement = replacement -> left;
                }
               
                if(replacement -> right != nullptr)
                    x -> left = replacement -> right;
       //======== Removing root===============             
              if (value == root -> value)  {                           //Remove root node -Parent == current in this case
                  replacement -> left = root -> left;
                  replacement -> right = root -> right;
                  free(root);
                  root = replacement;
                  --totalnodes;
                  return;
               }     
      //============  Normal Case =================  
               if(value > parent -> value)     
                   parent -> right = replacement;
               else if (value < parent -> value)
                   parent -> left = replacement;
              
                replacement -> left = current -> left;
                replacement -> right = current -> right;
                
            }
            free(current);
            --totalnodes;
            
           
        }
        
   vector<int> BFS(){
     queue<Node*> q;
     vector <int> v;
     q.push(root);
     v.push_back(root -> value);
     while(!q.empty()){
         Node *current{q.front()};
         q.pop();
         if(current -> left ){
             q.push(current -> left);
             v.push_back(current -> left -> value);
         }
          if(current -> right ){
             q.push(current -> right);
             v.push_back(current -> right -> value);
         }

     }
     return v;
 } 
    vector<int> BFSR (queue<Node*>q , vector <int> list){
        Node *current = q.front();
        list.push_back(current -> value);
        if(current -> left)q.push(current -> left);
        if(current -> right) q.push(current -> right);
        q.pop();
        if(q.empty())
            return list;
      return  BFSR(q , list);
    }
     void TraverseInoreder(Node *root, vector<int> &list){
        if(root -> left ){
            TraverseInoreder(root -> left , list);
        }  
        list.push_back(root -> value);
        
        if(root -> right){
             TraverseInoreder(root -> right , list);
        }
    }
    void TraversePreOrder(Node *root, vector<int> &list){
        list.push_back(root -> value);    
        if(root -> left){
            TraversePreOrder(root -> left , list);
        }  
        if(root -> right){
             TraversePreOrder(root -> right , list);
        }
    }
    void TraversePostOrder(Node *root, vector<int> &list){
        if(root -> left){
            TraversePostOrder(root -> left , list);
        }  
        if(root -> right){
             TraversePostOrder(root -> right , list);
        }
        list.push_back(root -> value); 
    }
    vector<int> DFSInOrder2(){
        vector<int> list;
        Node *node = get_root();
        TraverseInoreder(node,list);
        return list;
        
    }
    vector<int> DFSPreOrder(){
        vector<int> list;
        Node *node = get_root();
        TraversePreOrder(node,list);
        return list;
    }
    vector<int> DFSPostOrder(){
        vector<int> list;
        Node *node = get_root();
        TraversePostOrder(node,list);
        return list;
        
    }
    set<int> DFSINorder(set <int> list, stack <Node*> st){
        if(st.empty())
            return list;
        Node *current = st.top();
        list.insert(current -> value);
        if(current -> left != nullptr && (list.insert(current -> left -> value)).second != false ){
             current = current -> left;
              st.push(current);
        }
            
        else if(current -> right != nullptr && (list.insert(current -> right -> value)).second != false ){
            current = current -> right;
            st.push(current);
        }
            
        else
            st.pop();
        
        return DFSINorder(list , st);
    }
};
void display(const vector <int> &v){
        //sort(v.begin(),v.end());
        cout << "[ ";
        
        for(auto elem: v)
            cout << elem << " ";
            
        cout << "]\n"; 
    }
    
void display(const set <int> &list){
        //sort(v.begin(),v.end());
        cout << "[ ";
        
        for(auto elem: list)
            cout << elem << " ";
            
        cout << "]\n"; 
    }
int main(){
Tree tree;
/*          9
        /       \ 
       4          20
      /  \     /      \
     1    6    15       170
           \     \    /   \
           7      18   70   200
   */
     
     
     
tree.insert(9);
tree.insert(4);
tree.insert(6);
tree.insert(20);
tree.insert(170);
tree.insert(15);
tree.insert(1);
tree.insert(200);
tree.insert(70);
tree.insert(18);
tree.insert(7);

//tree.display();
tree.search(20);
tree.search(15);
tree.search(70);
cout << "=======================\n";
//tree.remove(9);
tree.search(20);
tree.search(15);
tree.search(70);
tree.search(9);
tree.search(18);
cout << "=======================\n";
display(tree.BFS());
cout << "=======================\n";
//tree.remove(4);
tree.search(4);
tree.search(7);
tree.search(6);
tree.search(1);
//tree.search(70);
//tree.search(170);
//tree.display();
cout << "=======================\n";
vector <int> v;
 display(tree.BFS());
// JSON.stringify(traverse(tree.root))
cout << "============BFSR===========\n";
queue <Node*> q;
vector <int> list;
q.push(tree.get_root());

display(tree.BFSR(q,list));
cout << "============DFSINOrder1===========\n";
stack<Node*> st;
set<int> s;
st.push(tree.get_root());
display(tree.DFSINorder(s,st));

cout << "============DFSINOrder===========\n";
vector <int> l;
display(tree.DFSInOrder2());
cout << "============DFSPreOrder===========\n";

display(tree.DFSPreOrder());
cout << "============DFSPostOrder===========\n";

display(tree.DFSPostOrder());

	return 0;
}
