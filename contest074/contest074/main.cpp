/*
 
  https://leetcode.com/contest/weekly-contest-74/
 
 Rank           Name             Score      Finish Time     Q1 (7)    Q2 (7)    Q3 (7)    Q4 (7)
 770 / 2675     claytonjwong     7          0:42:28         0:32:28  2
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

/*
class Solution {
public:
    bool validTicTacToe(vector<string>& b) {
        int cx=cnt(b,'X'),co=cnt(b,'O');
        bool wx=win(b,'X'),wo=win(b,'O');
        if (wx && wo) return false;
        if (wx) return cx==co+1
        if (wo) return cx==co;
        return cx==co+1 || cx==co;
    }
private:
    int cnt(vector<string>& b, char c){
        int res=0;
        for (auto& s: b) res+=count(s.begin(),s.end(),c);
        return res;
    }
    bool win(vector<string>& b, char c){
        for (int i=0; i<3; ++i) if (b[i][0]==c && b[i][1]==c && b[i][2]==c) return true;
        for (int j=0; j<3; ++j) if (b[0][j]==c && b[1][j]==c && b[2][j]==c) return true;
        return (b[0][0]==c && b[1][1]==c && b[2][2]==c)
            || (b[2][0]==c && b[1][1]==c && b[0][2]==c);
    }
};
 */



//AC
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int cnt=0,lessThanLeft=0,lessThanOrEqToRight=0;
        for (auto n: A){
 
            if (n<L)
                ++lessThanLeft;
            else
                lessThanLeft=0;
            
            if (n<=R)
                ++lessThanOrEqToRight;
            else
                lessThanOrEqToRight=0;
            
            cnt+=lessThanOrEqToRight-lessThanLeft;
        }
        return cnt;
    }
};


/*
// AC
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int cnt=0,i=0,j=0;
        for (auto n: A){
            i=(n<L) ? i+1 : 0;
            j=(n<=R) ? j+1 : 0;
            cnt+=j-i;
        }
        return cnt;
    }
};



class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int cnt=0,i=0,j=0;
        for (auto n: A) cnt+=( ++j*=(n<=R) ) - ( ++i*=(n<L) );
        return cnt;
    }
};
*/

    


int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    vector<string> v{
        "XOX",
        " X ",
        "   ",
    };
    cout << s.validTicTacToe(v) << endl;
    */
    
    Solution s;
    
    //vector<int> v{2,9,2,5,6}; int L=2,R=8;
    //vector<int> v{2, 1, 4, 3}; int L=2,R=3;
    vector<int> v{73,55,36,5,55,14,9,7,72,52}; int L=32,R=69;
    // output 18
    // expected 22
    cout << s.numSubarrayBoundedMax(v, L, R) << endl;
    
    
    return 0;
}




