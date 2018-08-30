/*

890. Find and Replace Pattern

Q: https://leetcode.com/problems/find-and-replace-pattern/description/
A: https://leetcode.com/problems/find-and-replace-pattern/discuss/164762/Straightforward-C++

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using VS=vector<string>;
class Solution {
public:

    VS findAndReplacePattern( VS& words, string pattern, VS answer={} )
    {
        for ( const auto& word: words )
        {
            if (  word.size() == pattern.size()
              &&  isMatch( word, pattern )
              &&  isMatch( pattern, word )  )
            {
                answer.push_back( word );
            }
        }

        return answer;
    }

private:

    bool isMatch( const string& word, const string& pattern, unordered_map<char,char>&& umap={} )
    {
        for ( auto index = 0; index < word.size(); ++index )
        {
            auto it = umap.find( pattern[ index ] );
            if ( it == umap.end() )
            {
                umap[ pattern[ index ] ] = word[ index ];
            }
            else
            {
                if ( it->second != word[ index ] )
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {

    Solution s;
    VS words{ "abc","deq","mee","aqq","dkd","ccc" }; string pattern{ "abb" };
    auto res = s.findAndReplacePattern( words, pattern );

    return 0;
}