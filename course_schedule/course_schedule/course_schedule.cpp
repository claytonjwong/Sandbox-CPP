/*
 
 207. Course Schedule
 
 https://leetcode.com/problems/course-schedule/description/
 
 There are a total of n courses you have to take, labeled from 0 to n - 1.
 
 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 
 Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 
 For example:
 
 2, [[1,0]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 
 2, [[1,0],[0,1]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int N, vector<pair<int, int>>& preqs) {
        return false;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    int N=3; vector<pair<int,int>> vp { {1,0}, {2,1}, {0,2} };
    
    cout << s.canFinish(N, vp) << endl;
    
    return 0;
}




