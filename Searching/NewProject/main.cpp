#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <queue>

using namespace std;
 class BST{
public:
     int val;
     BST *left;
     BST *right;
     
     BST()
      :val{0},left{nullptr}, right{nullptr}{}
      BST(int val)
      :val{val}, left{nullptr}, right{nullptr}{}
      BST(int val, BST *left)
       :val{val}, left{left},right{nullptr}{}
      BST(int val,BST *left, BST *right)
        :val{val}, left{left},right{right}{}
      
 };
 
 queue<int> BFS(BST *root){
     queue<int> q_val;
     queue <BST*> q_BST;
     q_BST.push(root);
     q_val.push(root -> val);
     while(!q_BST.empty()){
         size_t q_size{q_BST.size()};
         for(size_t i{0}; i < q_BST.size(); ++i){
             BST *BST{q_BST.front()};
             q_BST.push((BST) -> left);
             q_BST.push((BST) -> right);
             q_val.push((BST) -> left -> val);
             q_val.push((BST) -> right -> val);
             q_BST.pop();
         }
     }
     return q_val;
 }  
 
int main(){

    cout << INT_MAX << endl;
    cout << INT32_MAX << endl;
    cout << INT32_MIN << endl;
    cout << INT_MIN << endl;
 
    
	return 0;
}
