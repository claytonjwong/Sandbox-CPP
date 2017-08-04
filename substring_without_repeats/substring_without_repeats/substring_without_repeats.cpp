/*
 
 3. Longest Substring Without Repeating Characters
 
 https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 
 Given "abcabcbb", the answer is "abc", which the length is 3.
 
 Given "bbbbb", the answer is "b", with the length of 1.
 
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
 */

#include <algorithm>
#include <unordered_map>
#include <string>
#include <iostream>



using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,bool> dic;
        int maxlen = 0;
        
        for (int i=0; i < s.size(); i++){
            
            // collision, check for new max, set new i position, and clear dic
            if (dic.find(s[i]) != dic.end()){
                
                maxlen = max(maxlen, (int)dic.size());
                i = dic[s[i]]+1; // index of previous duplicate of this char + 1
                dic.clear();
            }
            dic[s[i]]=i;
        }
        
        return max(maxlen,(int)dic.size());
        
    }
};


int main(){
    
    Solution solution;
    
    cout << "abc == " << solution.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "b == " << solution.lengthOfLongestSubstring("bbbbb") << endl;
    cout << "wke == " << solution.lengthOfLongestSubstring("pwwkew") << endl;
    cout << "vdf == " << solution.lengthOfLongestSubstring("dvdf") << endl;
    
    
    
    
    return 0;
}





