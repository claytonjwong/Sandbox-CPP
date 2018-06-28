/*
 
 71. Simplify Path
 
 Q: https://leetcode.com/problems/simplify-path/description/
 A: https://leetcode.com/problems/simplify-path/discuss/142902/Straightforward-C++-using-istringstream
 
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path, vector<string> folders={}, string s="", string ans="") {
        istringstream is(path);
        while (getline(is,s,'/')){
            if (s.empty() || s==".")
                continue;
            if (s==".."){
                if (!folders.empty())
                    folders.pop_back();
                continue;
            }
            folders.push_back(s);
        }
        for (const auto& folder: folders)
            ans.append("/"+folder);
        return ans.empty() ? "/" : ans;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    cout << "/home==" << s.simplifyPath("/home/") << endl;
    cout << "/home/foo==" << s.simplifyPath("/home//foo/") << endl;
    cout << "/c==" << s.simplifyPath("/a/./b/../../c/") << endl;
    cout << "/==" << s.simplifyPath("/../") << endl;
    cout << "/...==" << s.simplifyPath("/...") << endl;
    cout << "/home/foo/.ssh2/authorized_keys==" << s.simplifyPath("/home/foo/.ssh/../.ssh2/authorized_keys/") << endl;
    
    return 0;
}


