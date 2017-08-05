/*
 
 322. Coin Change
 
 https://leetcode.com/problems/coin-change/description/
 
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 
 Example 1:
 coins = [1, 2, 5], amount = 11
 return 3 (11 = 5 + 5 + 1)
 
 Example 2:
 coins = [2], amount = 3
 return -1.
 
 Note:
 You may assume that you have an infinite number of each kind of coin.
 
 
 */



#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>



using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if (amount == 0){
            return 0;
        }
        
        // go through each amount from 0 to amount
        // and find the smallest amount of coins for each amount
        vector<int> amt;
        for (int curr_amt=0; curr_amt <= amount; curr_amt++){
            
            int min_coin_cnt = INT_MAX;
            
            for (auto coin : coins){
                
                int coin_cnt = INT_MAX;
                
                if (coin == curr_amt){
                    // one solution, this coin
                    coin_cnt = 1;
                }
                
                // index is the index of the previous solution without this coin
                int index = (int)amt.size() - coin;
                if (index > 0 && amt[index] > -1){
                    
                    // prev solution +1 (this coin)
                    coin_cnt = 1 + amt[index];
                }
                
                // exit inner loop here since the
                // biggest coin combo that fits is found
                if (coin_cnt < min_coin_cnt) {
                    min_coin_cnt = coin_cnt;
                }

            }
            
            // add coin count for this current amount,
            // -1 means there is no coin combo for that amount
            if (min_coin_cnt == INT_MAX){
                min_coin_cnt = -1;
            }
            amt.push_back(min_coin_cnt);
        }
        
        return amt[amt.size()-1];
    }
};


int main(int argc, const char * argv[]) {

    
    Solution solution;
    vector<int> coins { 1, 2};
    cout << solution.coinChange(coins, 3) << endl;
    
    
    return 0;
}






