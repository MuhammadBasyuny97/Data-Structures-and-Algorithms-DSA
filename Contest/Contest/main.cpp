#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>


using namespace std;
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int answer{0};
        int max{0};

       while(grid[0].size() != 0){ 
        for(size_t i{0}; i < grid.size(); ++i){
           auto row_max = max_element(grid[i].begin() , grid[i].end());
            if(*row_max > max)
                max = *row_max;
            grid[i].erase(row_max);
        }
        answer += max;
        max = 0;
       }
        return answer;
        
    }
   
       
    int longestSquareStreak(vector<int>& nums) {
       vector<int> streak;
      for(size_t i{0}; i < nums.size(); ++i){
          auto it1 = find (nums.begin(), nums.end(), pow(nums[i] , 2));
          auto it2 = find (nums.begin(), nums.end(), sqrt(nums[i]));
          if(it1 != nums.end() || it2 != nums.end()){
              streak.push_back(nums[i]);
          }       
      }  
        if(streak.size() <= 1)
            return -1;
        sort(streak.begin(),streak.end());
        if(streak.size() == 2 && streak[0] == sqrt(streak[1]) )
            return 2;
        int seq {-1};
        for(size_t j{0}; j < streak.size(); ++j){
            if(j == 0 && streak[0] == sqrt(streak[1])  )
                seq += 3;
            else if(streak[j-1] == sqrt(streak[j]) && streak[j+1] == pow(streak[j] , 2) ){
                    seq += 1;
            } 
            else if(seq == -1 && streak[j] == sqrt(streak[j+1]))
                seq += 3;
            else
                break;
        }
        return seq;
    }
int main(){
 vector <int> nums{4,3,6,16,8,2};
  cout << longestSquareStreak(nums) << endl;
   
   cout<<"Hello World!"<<endl; 
    
	return 0;
}
