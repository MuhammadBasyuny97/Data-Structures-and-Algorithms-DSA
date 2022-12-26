#include <iostream>
#include <vector>
#include <string>


using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        for(size_t i{0} ; i < nums.size() ; ++i){
            for(size_t j{i+1} ; j < nums.size() ; ++j){
                if(nums[i] + nums[j] == target){
                    indices.push_back(i);
                    indices.push_back(j);
                   return indices;
                }
            }
        }
    }
    
 vector<int> twoSum2(vector<int>& nums, int target) {
        vector<int> indices;
        int size = nums.size();
        for(size_t i{0} ; i < size ; ++i){
            
                if(nums[i] + nums[size-1] == target){
                    indices.push_back(i);
                    indices.push_back(size-1);
                   return indices;
                }
            }
        }
    
    void display(const vector<int>& nums ){
        cout <<"[ " << nums[0] <<", " << nums[1] <<"]\n";
    }
int main(){
  vector <int> nums{2,7,9,15};
  int target{11};
  display(twoSum2(nums , target));
  
   cout<<"Hello World!"<<endl; 
    
	return 0;
}
