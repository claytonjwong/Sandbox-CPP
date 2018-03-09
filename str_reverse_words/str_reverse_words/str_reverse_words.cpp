/*
 
 
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




