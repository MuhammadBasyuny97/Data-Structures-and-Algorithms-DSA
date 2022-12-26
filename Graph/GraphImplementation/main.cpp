#include <iostream>
#include <vector>
#include <string>
#include <vector>




using namespace std;

//Implement Undirected Unweighted Graph
const int size = 128;
class Graph{
private:
    int nodes_nums;
  // vector<int> nodes{};
    vector<int> adjacent_list[size];
public:
 Graph()
  :nodes_nums{0},adjacent_list{}{}
  
  void addVertex(int node){
      adjacent_list[node] = {};
      ++nodes_nums;
  }
  void addEdge(int node1, int node2){
      adjacent_list[node1].push_back(node2);  // If only directed graph
      adjacent_list[node2].push_back(node1); //Because of the graph is undirected
      
  }
  
  int size(){
      return nodes_nums;
  }
  
  void display(){
    for(int i {0}; i < nodes_nums ; ++i){
        cout << i << " --> ";
      for(auto elem: adjacent_list[i])
        cout << elem << " ";
     printf("\n");
    }
      
  }
};
int main(){
    Graph myGraph;
myGraph.addVertex(0);
myGraph.addVertex(1);
myGraph.addVertex(2);
myGraph.addVertex(3);
myGraph.addVertex(4);
myGraph.addVertex(5);
myGraph.addVertex(6);
myGraph.addEdge(3, 1); 
myGraph.addEdge(3, 4); 
myGraph.addEdge(4, 2); 
myGraph.addEdge(4, 5); 
myGraph.addEdge(1, 2); 
myGraph.addEdge(1, 0); 
myGraph.addEdge(0, 2); 
myGraph.addEdge(6, 5);

myGraph.display(); 

cout << myGraph.size() << endl;
   cout<<"Hello World!"<<endl; 
    
	return 0;
    
}
