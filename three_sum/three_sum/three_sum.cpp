/*
 
 15. 3Sum
 
 https://leetcode.com/problems/3sum/#/description
 
 
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 
 Note: The solution set must not contain duplicate triplets.
 
 For example, given array S = [-1, 0, 1, 2, -1, -4],
 
 A solution set is:
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        
        vector<vector<int>> result;
        
        if (nums.size() < 3){
            return result;
        }
        /*
         
         sort nums,
         
         then check sum and move begin and end indexes
         based on the sum to try and reach a total sum of 0
         
         */
        sort(nums.begin(), nums.end());
        
        for (int i=0; i < nums.size()-2; i++) {
            
            int beg = i+1;
            int end = (int)nums.size()-1;
            
            do {
            
                int sum = nums[i] + nums[beg] + nums[end];
            
                vector<int> curr_combo { nums[i], nums[beg], nums[end] };
            
                if (sum == 0) {
                    
                    /* solution found */
                    result.push_back(curr_combo);
                    
                    /*
                     only consider unique values for beg/end
                     continue incrementing/decrementing if the value is the same
                     */
                    do { beg++; } while ( beg < end and nums[beg-1] == nums[beg] );
                    do { end--; } while ( beg < end and nums[end] == nums[end+1] );
                }
                else if (sum > 0) {
                    do { end--; } while ( beg < end and nums[end] == nums[end+1] );
                }
                else if (sum < 0) {
                    do { beg++; } while ( beg < end and nums[beg-1] == nums[beg] );
                }
                
            } while ( beg < end );
            
            /*
             only consider unique values for i,
             continue incrementing i  until the last instance of repeated value
             */
            while ( nums[i] == nums[i+1] and i < nums.size()-2 ){
                i++;
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    vector<int> numbers { -1, 0, 1, 2, -1, 4 };
    
    vector<vector<int>> ret = solution.threeSum(numbers);
    
    return 0;
}
