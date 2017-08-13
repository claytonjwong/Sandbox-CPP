/*
 
 3. Longest Substring Without Repeating Characters
 
 https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 
 Given "abcabcbb", the answer is "abc", which the length is 3.
 
 Given "bbbbb", the answer is "b", with the length of 1.
 
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
 */

#include <iostream>
#include <unordered_map>

using namespace std;


class Solution{
public:
    
    int lengthOfLongestSubstring(string s){
        
        int maxlen = 0;
        
        unordered_map<char, bool> dic;
        
        int i=0; // left-side of sliding window
        int j=0; // right-side of sliding window
        
        while (i < s.size() && j < s.size()){
            
            if ( dic.find( s[j] ) == dic.end() ){ // add unique onto right-side of window
                
                //
                // unique char @ j, add char @ j to dic, and move j forward
                // and update maxlen if there is a new max
                //
                dic[ s[j++] ] = true;
                maxlen = max( maxlen, j-i );
                
                
            } else { // drop duplicate from left-side of window
                
                //
                // duplicate char @ j, delete char @ i from dic, and iterate i forward
                //
                dic.erase( s[i++] );
            }
            
        }
        
        return maxlen;
    }
    
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    //             012345
    string test = "pwwkew";
    
    cout << "3 == " << solution.lengthOfLongestSubstring(test) << endl;
    
    
    
    
    return 0;
}




