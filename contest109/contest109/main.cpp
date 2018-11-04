/*
 
 https://leetcode.com/contest/weekly-contest-109
 
 Rank          Name             Score    Finish Time    Q1 (4)    Q2 (5)        Q3 (6)    Q4 (8)
 867 / 3352    claytonjwong     9        1:16:23        0:04:44   1:06:23  2*
 
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

/*
class RecentCounter {
    set<int> history;
public:
    int ping(int t) {
        history.insert( t );
        return distance( history.lower_bound( t - 3000 ), history.end() );
    }
};
*/

// TLE for input: 161
/*
class Solution {
 
    vector<vector<int>> moves{
        { 4, 6 },
        { 6, 8 },
        { 7, 9 },
        { 4, 8 },
        { 0, 3, 9 },
        { },
        { 0, 1, 7 },
        { 2, 6 },
        { 1, 3 },
        { 2, 4 }
    };
    
    long long go( int N, int cur ){
        if( N-1 == 0 )
            return 1LL;
        long long result{ 0LL };
        for( const auto next: moves[ cur ] )
            result += go( N-1, next ) % 1000000007;
        return result;
    }
 
public:
 
    int knightDialer( int N ){
        long long result{ 0LL };
        for( auto i=0; i <= 9; ++i )
            result += go( N, i ) % 1000000007;
        return result % 1000000007;
    }
};
*/


/*
 
I derived this bottom-up DP solution from a TLE top-down DFS solution ( provided below ).
The row of the DP vector represent the N number of hops.  The column of the DP vector represent
the numeric phone pad keys [0:9] ( zero to nine, inclusive ).  Then the DP formula is as follows:
 
Base case: when N is 1, the knight will take zero hops from its current digit
 
dp[1][0:9] = 1
 
Recursive case:
 
dp[ i ][ 0 ] = sum( dp[ i-1 ][ x ] )
 
 */

/*
using VL = vector< long >;
using VVL = vector< VL >;
class Solution {
    static const int MOD = 1000000007;
public:
    int knightDialer( int N ){
        VVL dp( N+1, VL( 10, 1 ));
        for( int i{ 2 };  i <= N;  ++i ){
            dp[ i ][ 0 ] = (  dp[ i-1 ][ 4 ] + dp[ i-1 ][ 6 ]  ) % MOD;
            dp[ i ][ 1 ] = (  dp[ i-1 ][ 6 ] + dp[ i-1 ][ 8 ]  ) % MOD;
            dp[ i ][ 2 ] = (  dp[ i-1 ][ 7 ] + dp[ i-1 ][ 9 ]  ) % MOD;
            dp[ i ][ 3 ] = (  dp[ i-1 ][ 4 ] + dp[ i-1 ][ 8 ]  ) % MOD;
            dp[ i ][ 4 ] = (  dp[ i-1 ][ 0 ] + dp[ i-1 ][ 3 ] + dp[ i-1 ][ 9 ]  ) % MOD;
            dp[ i ][ 5 ] = (  0  );
            dp[ i ][ 6 ] = (  dp[ i-1 ][ 0 ] + dp[ i-1 ][ 1 ] + dp[ i-1 ][ 7 ]  ) % MOD;
            dp[ i ][ 7 ] = (  dp[ i-1 ][ 2 ] + dp[ i-1 ][ 6 ]  ) % MOD;
            dp[ i ][ 8 ] = (  dp[ i-1 ][ 1 ] + dp[ i-1 ][ 3 ]  ) % MOD;
            dp[ i ][ 9 ] = (  dp[ i-1 ][ 2 ] + dp[ i-1 ][ 4 ]  ) % MOD;
        }
        return accumulate( dp[ N ].begin(), dp[ N ].end(), 0L ) % MOD;
    }
};
*/

/*
class Solution {
    static const int MOD = 1000000007;
public:
    int knightDialer( int N ){
        vector< long > cur( 10, 1 ), next( cur );
        for( int i{ 2 };  i <= N;  ++i ){
            next[ 0 ] = (  cur[ 4 ] + cur[ 6 ]  ) % MOD;
            next[ 1 ] = (  cur[ 6 ] + cur[ 8 ]  ) % MOD;
            next[ 2 ] = (  cur[ 7 ] + cur[ 9 ]  ) % MOD;
            next[ 3 ] = (  cur[ 4 ] + cur[ 8 ]  ) % MOD;
            next[ 4 ] = (  cur[ 0 ] + cur[ 3 ] + cur[ 9 ]  ) % MOD;
            next[ 5 ] = (  0  );
            next[ 6 ] = (  cur[ 0 ] + cur[ 1 ] + cur[ 7 ]  ) % MOD;
            next[ 7 ] = (  cur[ 2 ] + cur[ 6 ]  ) % MOD;
            next[ 8 ] = (  cur[ 1 ] + cur[ 3 ]  ) % MOD;
            next[ 9 ] = (  cur[ 2 ] + cur[ 4 ]  ) % MOD;
            cur.swap( next );
        }
        return accumulate( cur.begin(), cur.end(), 0L ) % MOD;
    }
};
*/

/*
class Solution {
    static const int MOD = 1000000007;
    vector<vector<int>> moves{
        { 4, 6 },  { 6, 8 },  { 7, 9 },  { 4, 8 },  { 0, 3, 9 },  { },  { 0, 1, 7 },  { 2, 6 },  { 1, 3 },  { 2, 4 }
    };
public:
    int knightDialer( int N ){
        vector<long> cur( 10, 1 );
        for(  vector<long> next( 10, 0 );  --N > 0;  next=vector<long>( 10, 0 )  ){
            for( int i=0;  i <= 9;  ++i )
                for( const int move: moves[ i ] )
                    next[ i ] += cur[ move ] % MOD;
            cur.swap( next );
        }
        return accumulate( cur.begin(), cur.end(), 0L ) % MOD;
    }
};
*/


class Solution {
    static const int MOD = 1000000007;
    vector<vector<int>> moves{ {4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4} };
public:
    int knightDialer( int N, int ans=10 ){
        for(  vector<long> cur( 10, 1 ), next( 10, 0 );  --N > 0;  cur.swap( next ), next=vector<long>( 10, 0 ), ans = accumulate( cur.begin(), cur.end(), 0L ) % MOD  )
            for( int i=0;  i <= 9;  ++i )
                for( const int move: moves[ i ] )
                    next[ i ] += cur[ move ] % MOD;
        return ans;
    }
};


int main(int argc, const char * argv[]) {

    /*
    RecentCounter rc;
    cout << rc.ping(1) << " " << rc.ping(100) << " " << rc.ping(3001) << " " << rc.ping(3002) << endl;
    */
    
    Solution s;
    cout << s.knightDialer( 161 ) << endl;
    
    return 0;
}







