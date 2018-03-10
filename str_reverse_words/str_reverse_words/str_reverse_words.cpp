/*
 
 151. Reverse Words in a String
 
 https://leetcode.com/problems/reverse-words-in-a-string/description/
 
 Given an input string, reverse the string word by word.
 
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 
 */

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
    void reverseWords(string &str) {
        stringstream stream(str);
        stack<string> s;
        for (string word; getline(stream,word,' ');) if (!word.empty()) s.push(word);
        str.clear();
        while (!s.empty()){
            str+=s.top()+" ";
            s.pop();
        }
        str.pop_back(); // remove trailing whitespace
    }
};

int main(int argc, const char * argv[]) {
  
    string str("    ");
    Solution s;
    s.reverseWords(str);
    cout << str << endl;
    
    
    return 0;
}




