#include <iostream>
#include <vector>
#include <string>


using namespace std;

 void addEdge(vector<int> arr[] , int d , int s){
    arr[d].push_back(s);
}

 void printGraph(vector<int> arr[] , int vertices){
     for(int i{0}; i < vertices ; ++i){
         cout << i << "--> ";
        for(auto elem: arr[i] )
            cout << elem << " ";
        printf("\n");
     }
 }
int main(){
  int v{5};
  vector<int> adj[v];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);
	printGraph(adj, v);
  
    
	return 0;
}
