/*
 *
 * Contest 112
 *
 * https://leetcode.com/contest/weekly-contest-112
 *
 * Q1:
 * A1:
 *
 * Q2:
 * A2:
 *
 * Q3:
 * A3:
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;






/*
class Solution {
public:
    int minIncrementForUnique( vector<int>& A, int ans=0 ){
        set<int> unique;
        for( int i=0; i <= 80000; ++i ){
            unique.insert( i );
        }
        for( const auto a: A ){
            auto it = lower_bound( unique.begin(), unique.end(), a );
            if( it != unique.end() ){
                ans += *it - a;
                unique.erase( it );
            }
        }
        return ans;
    }
};
*/


/*
class Solution {
public:
    int minIncrementForUnique( vector<int> &A, bitset<80001> V={}, int w=0, int i=0 ){
        sort( A.begin(), A.end() );
        for( const auto a: A ){
            for( w = a;  V[ w ];  ++w, ++i);
            V[ w ] = true;
        }
        return i;
    }
};
*/

/*
class Solution {
public:
    int minIncrementForUnique( vector<int> &A, int sum=0 ){
        sort( A.begin(), A.end() );
        for( auto it = A.empty() ? A.begin() : next( A.begin() );  it != A.end();  ++it ){
            int m = max( *prev( it ) + 1,  *it );
            sum += m - *it;
            *it = m;
        }
        return sum;
    }
};
*/

/*
class Solution {
public:
    int minIncrementForUnique( vector<int> &A, int sum=0 ){
        sort( A.begin(), A.end() );
        int m = A.empty() ? 0 : A.front();
        for( auto it = A.empty() ? A.begin() : next( A.begin() );  it != A.end();  ++it ){
            m = max( m + 1,  *it );
            sum += m - *it;
        }
        return sum;
    }
};
*/


class Solution {
public:
    int minIncrementForUnique( vector<int> &A, int sum=0 ){
        sort( A.begin(), A.end() );
        int m = A.empty() ? 0 : A.front();
        for( auto it = A.empty() ? A.begin() : next( A.begin() );  it != A.end();  ++it )
            m = max( m + 1,  *it ), sum += m - *it;
        return sum;
    }
};




int main() {

    Solution s;
    vector<int> A{ 1,1,2,2,3,7 };
    cout << s.minIncrementForUnique( A ) << endl;



    return 0;
}


