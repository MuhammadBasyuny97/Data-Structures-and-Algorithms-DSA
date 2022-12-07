#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <map>
#include <sstream>


using namespace std;


    
    void display(const vector<int>& arr){
        cout << "{ ";
        for(auto elem: arr)
            cout << elem << " ";
        cout << "}\n";
    }
    
 
   
    string freqAlphabets(string s) {
       // string encryption{"12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"};
     //   string decryption{"abcdefghijklmnopqrstuvwxyz"};
        map<string , char>m{
            {"1",'a'}, {"2",'b'},{"3",'c'},{"4",'d'},{"5",'e'},{"6",'f'},{"7",'g'},{"8",'h'},
            {"9",'i'},{"10#",'j'},{"11#",'k'},{"12#",'l'},{"13#" , 'm'},{"14#",'n'},{"15#",'o'},
            {"16#",'p'},{"17#",'q'},{"18#",'r'},{"19#",'s'},{"20#",'t'},{"21#",'u'},{"22#",'v'},
            {"23#",'w'},{"24#",'x'},{"25#",'y'},{"26#",'z'}
        };
        
        for(size_t i{0}; i < s.length() ; ++i){
            ostringstream ss;
            string temp;
            if(s[i+2] =='#'){
                size_t j{i};
                while(j < i + 3){
                  ss << s[i];
                  ++j;
                }
                s[i] = m[ss.str()];
                i = j+1;
                ss.str().clear();
            }
            else{
                ss << s[i];
                s[i] = m[ss.str()];
               ss.str().clear();
        }
       }
        return s;
    }
    void display(const string &s){
        cout << "\"";
        for(auto c: s)
            cout << c;
        cout << "\"\n";
        
    }
    
    string decodeString(string s) {
           string str;
           string sub;
           
        while(s.length() != 0){
            stringstream ss;
            ss << s;
            int k {0};
            ss >> k;
            if(isdigit(s[0])){
                int j{2};
                int len{0};
                while(s[j] != ']'){
                    sub += s[j];
                    len++;
                    ++j;
                }
                s = s.erase(0,len+3);
                while(j < k){
                    str += sub;
                    ++j;
                }
                sub.clear();
               
            }
            
        }
       return str; 
    }
int main(){
string s{};
vector<int> v;
int k{};
s = "[a]2[bc]";

cout << decodeString(s) << endl;
	return 0;
}
