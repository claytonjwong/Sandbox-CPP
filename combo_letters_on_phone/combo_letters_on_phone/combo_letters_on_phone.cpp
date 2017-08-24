/*
 
 17. Letter Combinations of a Phone Number
 
 https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 
 Given a digit string, return all possible letter combinations that the number could represent.
 
 A mapping of digit to letters (just like on the telephone buttons).

 
 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> combos;
        
        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        
        for ( char digit : digits ){
            
            if (map.find(digit) == map.end()) { continue; } // digits w/o letters such as 0 or 1
            
            if (combos.empty()){ // first digit, append digit's letters onto the vector of combos
                
                for ( char letter : map[digit] ){
                    
                    combos.push_back( string(1, letter) );
                                     
                }
             } else { // create a new vector by appending subsequent digit's letters
                      // onto the old vector of combos
                 
                 vector<string> new_combos;
                 for (int i=0; i < combos.size(); i++){
                     for ( char letter : map[digit] ){
                         new_combos.push_back(combos[i] + string(1, letter) );
                     }
                 }
                 combos = new_combos;
             }
         }
        
        return combos;
     }
 };


int main(int argc, const char * argv[]) {

    Solution solution;
    
    vector<string> result = solution.letterCombinations("123");
    
    for ( auto el : result ){
        cout << el << ",";
    }
    cout << endl;
    
    return 0;
}




