#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>


using namespace std;
    int BinarySearch(vector <int> arr, int begin, int n, int item){
        int answer{0};
    if(n == 0)
        return -1;
    else if (n == 1 ){
        if(item == arr[begin])
         answer =  arr[begin];
        else
          return -1;
    }
    else{
      int lastindex = n + begin -1;
      if(item == arr[begin])
        answer =  arr[begin];
      else if(item == arr[lastindex])
        answer = arr[lastindex];
      else{
        int middle = (n/2 -1) + begin;
        if(item > arr[middle])
            BinarySearch(arr, middle+1 , n/2 , item);
        else if(item == arr[middle])
            answer = arr[middle];
        else 
            BinarySearch(arr, begin , n/2  , item);
    }
   }
        return answer;
}
    
 int search(vector<int> arr ,  int item){
    int n = arr.size();
    int index {0};
    return index = BinarySearch(arr, 0 , n , item);
}
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> s;
        
        if(nums1.size() > nums2.size()){
         for(size_t i{0} ; i < nums2.size(); ++i){
           int elem {search(nums1 , nums2[i])};
           if(elem != 2000)
               s.insert(elem);
      }
        }
       if(nums1.size() <= nums2.size()){
         for(size_t i{0} ; i < nums1.size(); ++i){
             int elem {search(nums2 , nums1[i])};
             if(elem != 2000)
               s.insert(elem);
        }
      }
      s.erase(0);
      auto it1 = s.begin();
        while(it1 != s.end()){
            result.push_back(*it1);
            ++it1;
        }
        return result;
    }
 void display(const vector<int> &vec){
         cout << "[ ";
         for (auto elem : vec)
            cout << elem << " ";
         cout << "]\n";
    }
int main(){
   vector <int> nums1{9,4,9,8,4};
   vector <int> nums2{4,9,5};
   display(nums1);
   display(nums2);
   vector <int> result =  intersection(nums1 , nums2);
   
   display(result);
   cout<<"Hello World!"<<endl; 
    
	return 0;
}
