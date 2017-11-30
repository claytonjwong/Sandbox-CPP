//
//  main.cpp
//  contest_55
//
//  Created by CLAYTON WONG on 10/21/17.
//  Copyright © 2017 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int res=0;
        unordered_map<char,int> dic{};
        for (int c='a'; c <= 'z'; ++c){
            dic[c]=0;
        }
        for (auto &&c: s1){
            ++dic[c];
        }
        for (auto &&c: s2){
            --dic[c];
        }
        typedef typename unordered_map<char,int>::iterator itr;
        for (itr i=dic.begin(); i!=dic.end(); ++i){
            res+=(int)i->first*abs(i->second);
        }
        return res;
    }
};
 */

/*
class Solution{
public:
    int maxProfit(vector<int>& prices, int fee) {
        int k = (int)prices.size()-1;
        vector<long> sells(1+k, 0), buys(1+k, (long)INT_MIN);
        for (auto &&price: prices) {
            for(int i=k; i>0; --i) {
                sells[i] = max(sells[i], price + buys[i] - fee);
                buys[i] = max(buys[i], sells[i-1] - price);
            }
        }
        return (int)*max_element(sells.begin(), sells.end());
    }
};
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0, sz=(int)nums.size();
        for (int i=0; i<sz-1; ++i){
            if (nums[i]>=k) continue;
            ++cnt;
            long prod=nums[i];
            for (int j=i+1; j<sz; ++j){
                prod*=nums[j];
                if (prod<k)
                    ++cnt;
                else
                    break;
            }
        }
        return nums[sz-1] >= k ? cnt : cnt+1;
    }
};

int main() {
    vector<int> arr1 = {1, 3, 7, 5, 10, 3}; int fee1 = 3;
//    vector<int> arr2 = {9,8,7,1,2}; int fee2 = 3;
//    vector<int> arr3 = {1,4,6,2,8,3,10,14}; int fee3 = 3; //4 trans --> 10, 3 trans --> 2+3+8, 2 trans --> 4+8=12, 1 tran --> 10

    Solution solution;
    
    vector<int> nums{10,5,2,6};
    cout << solution.numSubarrayProductLessThanK(nums, 100) << endl;
    
    return 0;
}
