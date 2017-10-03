/*
 
 576. Out of Boundary Paths
 
 https://leetcode.com/problems/out-of-boundary-paths/description/
 
 There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.
 
 Example 1:
 Input:m = 2, n = 2, N = 2, i = 0, j = 0
 Output: 6
 Explanation:
 
 Example 2:
 Input:m = 1, n = 3, N = 3, i = 0, j = 1
 Output: 12
 Explanation:
 
 Note:
 Once you move the ball out of boundary, you cannot move it back.
 The length and height of the grid is in range [1,50].
 N is in range [0,50].
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int _memo[51][51][51]={0};
    bool isOnGrid(const int& m, const int& n, const int& i, const int& j){
        return 0<=i&&i<m && 0<=j&&j<n;
    }

public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (!N)
            return _memo[N][i][j]=!isOnGrid(m,n,i,j);
        int paths=0;
        vector<vector<int>> moves {{i-1,j},{i,j+1},{i+1,j},{i,j-1}};
        for (auto& move : moves){
            if (isOnGrid(m,n,move[0],move[1])){
                paths+=_memo[N][move[0]][move[1]] ? _memo[N][move[0]][move[1]]
                : findPaths(m,n,N-1,move[0],move[1]) % 1000000007;
            } else {
                ++paths;
            }
        }
        return _memo[N][i][j]=paths;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    cout << solution.findPaths(7,6,13,0,2) << endl;
    
    
    
    return 0;
}





