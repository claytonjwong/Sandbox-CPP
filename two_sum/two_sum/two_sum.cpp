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
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    /* Brute force O(N^2) */
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> result = {-1,-1};
//        
//        for (int i=0; i < nums.size()-1; i++ ){
//            for (int j=i+1; j < nums.size(); j++){
//                if (nums[i]+nums[j]==target){
//                    result = {i, j};
//                    break;
//                }
//            }
//        }
//        
//        return result;
//    }
    
    vector<int> twoSum(vector<int>& nums, int target){
        
        vector<int> result;
        
        unordered_map<int, int> lookup; // key=num val=index of num
        
        for (int i=0; i < nums.size(); i++){
            
            int num = nums[i];
            int compliment = target - num; // derived from target = num + compliment
            
            if ( lookup.find(compliment) != lookup.end() ){ // lookup compliement
                
                result.push_back(i); // index of num
                result.push_back(lookup[compliment]); // index of compliment
                break;
            }
            
            lookup[num] = i; // add num into the hash if corresponding compliment is NOT found
        }
        
        return result;
    }
    
};


int main(int argc, const char * argv[]) {
    
    
    Solution solution;
    
    vector<int> nums = { 3, 3 };
    int target = 6;
    
    vector<int> result = solution.twoSum(nums, target);
    cout << "[0,1] == [" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}
