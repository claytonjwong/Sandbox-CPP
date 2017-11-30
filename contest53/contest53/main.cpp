//
//  main.cpp
//  contest53
//
//  Created by CLAYTON WONG on 10/7/17.
//  Copyright © 2017 Clayton Wong. All rights reserved.
//

#include <iostream>

#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <regex>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n){
            if ((n&1)==((n&2)>>1)) return false;
            n>>=1;
        }
        return true;
    }
};


class Solution1 {
public:
    bool hasAlternatingBits(int n) {
        n+=(n>>1)+1;
        return (n&(n-1))==0;
    }
};



class Solution2 {
public:
    bool hasAlternatingBits(int n) {
        return regex_match(bitset<32>(n).to_string(),regex("(0)*(10)*1{0,1}"));
    }
};
 


class Solution3 {
public:
    bool hasAlternatingBits(int n) {
        bool last=(n&1);
        return n==0 ? false : helper(n,!last);
    }
    
    bool helper(int n, bool last){
        return n==0 ? last==true : (n&1)==last ? false : helper(n>>1,!last);
    }
    
};

 
class Solution4 {
public:
    bool hasAlternatingBits(int n) {
        if (n==0) return false;
        bool last=n&1;
        while(n>>=1 > 0){
            if ((n&1)==last) return false;
            last=!last;
        }
        return true;
    }
};

/*
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        if (stickers.empty() || target.empty()) return 0;
        map<char,int> map{};
        for (auto& ch : target){
            if (map.find(ch)==map.end()) { map[ch]=1; }
            else                         { ++map[ch]; }
        }
        vector<set<char>> sets{};
        for (auto& s : stickers){
            set<char> chars{};
            for (auto& ch : s){
                chars.insert(ch);
            }
            sets.push_back(chars);
        }
        
        set<char> max_sun{};
        do{
            for (auto& s : sets){
                vector<pair<char,int>> sun{};
                set_union(s.begin(), s.end(), map.begin(), map.end(), sun.begin());
//                if (sun.size()>max_sun.size()){
//                    max_sun=sun;
//                }
            }
        }while(true);
        return 0;
    }
};
*/

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    
    while(true){
        cout << "n: ";
        int n;
        cin >> n;
        cout << solution.hasAlternatingBits(n) << endl;
    }
    
    return 0;
}
