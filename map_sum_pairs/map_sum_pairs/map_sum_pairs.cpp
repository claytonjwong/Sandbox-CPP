/*
 
 677. Map Sum Pairs
 
 https://leetcode.com/contest/leetcode-weekly-contest-50/problems/map-sum-pairs/
 
 Implement a MapSum class with insert, and sum methods.
 
 For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.
 
 For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.
 
 Example 1:
 Input: insert("apple", 3), Output: Null
 Input: sum("ap"), Output: 3
 Input: insert("app", 2), Output: Null
 Input: sum("ap"), Output: 5
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() : _map{} {}
    
    void insert(string key, int val) {
        _map[key]=val;
    }
    
    int sum(string prefix) {
        int cnt=0, sz=(int)prefix.size();
        map<string,int>::iterator itr;
        for (itr=_map.lower_bound(prefix); itr!=_map.end(); itr++){
            if (itr->first.substr(0,sz)==prefix){ cnt+=itr->second; } else { break; }
        }
        return cnt;
    }
private:
    map<string,int> _map;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main(int argc, const char * argv[]) {

    MapSum solution;
    solution.insert("apple", 3);
    solution.insert("app", 2);
    solution.insert("othera", 69);
    solution.insert("otherb", 69);
    solution.insert("otherc", 69);
    cout << solution.sum("ap") << endl;
    
    
    
    return 0;
}




