/*
 
 201. Bitwise AND of Numbers Range
 
 https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/
 
 Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 
 For example, given the range [5, 7], you should return 4.
 
 
 */

 
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        int result=0;
        unordered_map<int,bool> bits;
        
        for (int i=0; i < 32 && n >= (1 << i); i++){
            bits[i]=true;
            for (int j=m;j<=n;j++){
                if (! (j & (1<<i)) ){
                    bits[i]=false;
                    j=n;
                }
            }
            if (bits[i]){
                result |= (1 << i);
            }
        }

        return result;
    }
};





int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    int result = solution.rangeBitwiseAnd(1,1);
    
    cout << "result: " << result << endl;
    
    
    return 0;
}
