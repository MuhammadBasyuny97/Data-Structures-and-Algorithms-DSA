#include <iostream>
#include <vector>
#include <string>


using namespace std;
int counter{0};
string inception(){
   cout << counter << endl;
   if(counter > 3)
     return "done!";
   ++counter;
   return inception(); 
}


int main(){
   inception();
   cout<<"Hello World!"<<endl; 
    
	return 0;
}
