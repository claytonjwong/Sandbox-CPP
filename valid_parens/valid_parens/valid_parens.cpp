/*
 
 20. Valid Parentheses
 
 https://leetcode.com/problems/valid-parentheses/#/description
 
 
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        vector<char> stack;
        
        for (int i=0; i<s.size(); i++) {
            
            char curr = s[i];
            
            //
            // when an open container is found,
            // push the corresponding close container
            // onto the stack
            //
            if (curr=='(') {
                stack.push_back(')');
                
            } else if (curr=='{') {
                stack.push_back('}');
                
            } else if (curr=='[') {
                stack.push_back(']');
            
            } else if (stack.size() > 0) {
                
                //
                // this character should be a close container
                // which should match the previously pushed character
                //
                char prev = stack.back();
                
                if (curr != prev ) {
                    return false;
                } else {
                    stack.pop_back();
                }
                
            } else /* stack.size() == 0 */ {
                return false;
                
            }
        }
        
        //
        // stack size should be 0 if all pushed values were popped and matched
        //
        if ( stack.size()==0 ){
            return true;
        } else {
            return false;
        }
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    cout << "() == " << solution.isValid("()") << endl;
    
    cout << "] == " << solution.isValid("]") << endl;
    
    cout << "[ == " << solution.isValid("[") << endl;
    
    
    return 0;
}
