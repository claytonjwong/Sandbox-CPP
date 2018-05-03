/*
 
 https://leetcode.com/contest/leetcode-weekly-contest-50
 
 Rank           Name            Score   Finish Time     Q1 (3)      Q2 (6)      Q3 (7)      Q4 (9)
 211 / 2713     claytonjwong    16      0:55:40         0:11:59    0:25:09  2   0:40:40  1
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

/*
class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size()<2) return true;
        return go(s,0,(int)s.size()-1,true);
    }
private:
    bool go(const string& s, int i, int j, bool first){
        while (i<j && s[i]==s[j]){ ++i; --j; };
        return (i>=j) ? true : first ? go(s,i+1,j,false) || go(s,i,j-1,false) : false;
    }
};

 */

/*
class MapSum {
public:
 
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        bool found=K.find(key)!=K.end();
        K.insert(key);
        for (int i=1; i<=(int)key.size(); ++i){
            if (found)
                M[key.substr(0,i)]=val;
            else
                M[key.substr(0,i)]+=val;
        }
    }
    
    int sum(string prefix) {
        return M[prefix];
    }
private:
    unordered_map<string,int> M;
    unordered_set<string> K;
};
 
 */

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

/*
class Solution {
public:
    bool checkValidString(string s) {
        return go(s,(int)s.size(),0,0);
    }
private:
    bool go(const string& s, int N, int i, int open){
        while (i < N && s[i]!='*'){
            if (s[i]=='(')
                ++open;
            else {
                if (--open < 0)
                    return false;
            }
            ++i;
        }
        if (i==N){
            return open==0;
        } else {
            return go(s,N,i+1,open) || go(s,N,i+1,open+1) || go(s,N,i+1,open-1);
        }
    }
};
*/

// ran out of time
/*
class Solution {
public:
    bool judgePoint24(vector<int>& A) {
        return go(A,1,0.0);
    }
private:
    vector<char> ops={'+','-','*','/'};
    bool go(const vector<int>& A, int i, double ans){
      while (i < A.size()){
          for (auto op: ops)
              if (go(A,i+1,doit(ans,op,A[i]);
          ++i;
      }
      return ans==24.0;
    }
    double doit(double ans, char c, int next){
        switch(c){
            case '+': return ans+next;
            case '-': return ans-next;
            case '*': return ans*next;
            case '/': return ans/next;
        }
        return 0.0;
    }
};
*/


int main(int argc, const char * argv[]) {

    /*
    Solution s;
    string str="abbcca";
    cout << s.validPalindrome(str) << endl;
*/
    /*
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
    */
    
    /*
    MapSum ms;
    ms.insert("apple",3);
    cout << ms.sum("apple") << endl;
    ms.insert("app",2);
    cout << ms.sum("ap") << endl;
    */
    
    /*
     Input:
     ["MapSum", "insert", "sum", "insert", "sum"]
     [[], ["aa",3], ["a"], ["aa",2], ["a"]]
     Output:
     [null,null,3,null,5]
     Expected:
     [null,null,3,null,2]
     */
    
    /*
    MapSum ms;
    ms.insert("aa",3);
    cout << ms.sum("a") << endl;
    ms.insert("aa",2);
    cout << ms.sum("a") << endl;
*/
    
  /*
    Solution s;
    string str="(*)";
    cout << s.checkValidString(str) << endl;
    */
    
    
    
    
    
    return 0;
}


