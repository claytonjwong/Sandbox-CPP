/*
 
 1. Two Sum
 
 https://leetcode.com/problems/two-sum/#/description
 
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 
 You may assume that each input would have exactly one solution, and you may not use the same element twice.
 
 Example:
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = {-1,-1};
        
        for (int i=0; i < nums.size()-1; i++ ){
            for (int j=i+1; j < nums.size(); j++){
                if (nums[i]+nums[j]==target){
                    result = {i, j};
                    break;
                }
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    
    
    Solution solution;
    
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    
    vector<int> result = solution.twoSum(nums, target);
    cout << "[0,1] == [" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}
