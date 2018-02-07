//
//  main.cpp
//  contest070
//
//  Created by CLAYTON WONG on 2/3/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    bool canTransform(string s, string target) {
        unordered_set<string> v;
        queue<string> q;
        q.push(s);
        while(!q.empty()){
            auto curr=q.front(); q.pop();
            if (curr==target) return true;
            for (int i=1; i<s.size(); ++i){
                if (canSwap(s[i-1],s[i])){
                    string next=curr;
                    swap(next[i-1],next[i]);
                    if (!v.count(next)){
                        q.push(next);
                    }
                }
            }
        }
        return false;
    }
private:
    bool canSwap(char a, char b){
        return ((a=='X' && (b=='L' || b=='R')) || (canSwap(b,a)));
    }
                    
};
*/

/*
 
 
 
 */
class Solution {
public:
    int kthGrammar(int N, int K) {
        return __builtin_popcount(K-1)%2;
    }
};

// 434,991,989
// 434991989

int main(int argc, const char * argv[]) {
    
    
    
    Solution s;
    int k;
    while(true){
        cout << "k: "; cin >> k;
        cout << s.kthGrammar(0, k) << endl;
    }
    
    
    
    return 0;
}







