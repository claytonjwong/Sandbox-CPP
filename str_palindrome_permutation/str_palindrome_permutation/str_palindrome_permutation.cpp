/*
 
 Given a string wrote a funtion to check if it is a permutation of a palindrome.
 
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    bool is_pp(string s){
        
        // sanity checks
        if ( s.empty() ) {
            return false;
        }
        
        // track the count of each char of s only contains letters and spaces
        unordered_map<char,int> umap;
        for ( auto ch : s ){

            if (!isspace(ch)){
                ch = tolower(ch);
                umap[ch]++;
            }
        }
        
        // a palindrome permutation has at most 1 single char
        // all other chars need to be in even pairs ( 2, 4, 6 etc )
        unordered_map<char,int>::iterator itr;
        bool one_found = false;
        for (itr = umap.begin(); itr != umap.end(); itr++) {
            
            if ( itr->second == 1 ) {
                if ( one_found ) {
                    return false; // at most only one single char can have count 1
                } else {
                    one_found = true;
                }
            }
            else
            if ( itr->second % 2 != 0 ) {
                return false; // all other chars count need to be an even number
            }
            
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;

    string test;
    cout << "is_pp(" << test << "): " << solution.is_pp(test) << endl;

    test = "race car";
    cout << "is_pp(" << test << "): " << solution.is_pp(test) << endl;

    test = "a man a plan a canal panama";
    cout << "is_pp(" << test << "): " << solution.is_pp(test) << endl;

    
    test = "something else";
    cout << "is_pp(" << test << "): " << solution.is_pp(test) << endl;
    
    return 0;
}
