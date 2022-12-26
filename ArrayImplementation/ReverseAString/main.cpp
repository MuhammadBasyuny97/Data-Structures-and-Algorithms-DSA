#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>


using namespace std;

class Mystring{
 private:
   char *str;
   
   friend ostream &operator<< (ostream &os , const Mystring &my_string );
   friend istream &operator>> (istream &is , Mystring &my_string );
public:
Mystring()
 :str{nullptr}{
     str = new char[1];
     *str = '\0';
}
Mystring(const char *s)
 :str{nullptr}{
     if (s == nullptr){
         str = new char[1];
         *str = '\0';
     }
     else{
         str = new char [(std::strlen(s) +1)];
         strcpy(str, s);
        }

 }
 ~Mystring() noexcept{}
 
 char* get_str() const{ return str;}
 
 size_t size(){
     return strlen(str);
 }
 char &operator[](const int &i){
     return str[i];
 }

};
 
 ostream &operator<< (ostream &os , const Mystring &my_string ){
     os << my_string.get_str();
     return os;
 }
 
 istream &operator>> (istream &is , Mystring &my_string ){
     cin.getline(my_string.get_str() , 1000 , '\n');
     return is;
 }

Mystring reverse_string( Mystring &my_string){
    size_t str_size = my_string.size();
    Mystring new_str;
    for(size_t i {0} ; i < str_size/2 ;++i){ //5
        char c  {my_string[i]};
        my_string[i] = my_string[str_size - 1 - i];
        my_string[str_size - 1- i] = c;
    }
        
    return my_string;
}

string reverse_string1 (string &str) {
    reverse(str.begin() , str.end());
    return str;
   }

string reverse_string2 (string &str) {
    size_t TotalChars {str.size() -1}; 
    for (size_t i {0}; i < TotalChars/2 ; ++i)
        swap(str[i] , str[TotalChars-i]);
   
   return str;
   }
   
   string reverse_string3 (string &str) {
    string str2;
    size_t TotalChars {str.size() -1}; 
    for (int i {TotalChars}; i >= 0 ; --i){
        //str2 += str[i];
        str2.push_back(str[i]);
    }
    
   str = str2;
   return str;
   }
int main(){
    
    string str;
    getline(cin , str);
    
    string str2 {str};
    cout << str << endl;
   // 
   reverse_string3(str);
    cout << str << endl;
    cout << str2 << endl;
    
    cout << "==========Another Solution==================\n";
   
   
    
    
    
    
    
    
	return 0;
}
