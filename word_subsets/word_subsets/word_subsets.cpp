/*

 916. Word Subsets
 
 Q: https://leetcode.com/problems/word-subsets/description/
 A: https://leetcode.com/problems/word-subsets/discuss/179522/Verbose-C++-(-easy-to-understand-)
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

using VS = vector< string >;
using Map = unordered_map< char,int >;
class Solution {
    Map toMap( const string& s ){
        Map m;
        for( const auto c: s )
            ++m[ c ];
        return m;
    }
    Map toMap( const vector<Map>& maps ){
        Map result;
        for( const auto& map: maps )
            for( const auto& p: map )
                result[ p.first ] = max( result[ p.first ], p.second );
        return result;
    }
    bool isUniversal( const string& s, const Map& needles ){
        const Map haystack = toMap( s );
        for( const auto& needle: needles ){
            auto it = haystack.find( needle.first );
            if( it == haystack.end() || it->second < needle.second )
                return false;
        }
        return true;
    }
public:
    VS wordSubsets( VS& A, VS& B, Map target={}, VS ans={} ){
        vector<Map> targets;
        for( const auto& b: B )
            targets.push_back( toMap( b ) );
        target = toMap( targets );
        for( const auto& a: A )
            if( isUniversal( a, target ))
                ans.push_back( a );
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    VS A{ "amazon","apple","facebook","google","leetcode" }, B{ "ec","oc","ceo" };
    auto result = s.wordSubsets( A, B );

    return 0;
}
