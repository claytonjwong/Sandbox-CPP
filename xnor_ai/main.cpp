#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>


using namespace std;


namespace xnor_ai
{

    const auto maximum = numeric_limits< uint8_t >::max();


    //
    // top-down recursive solution with memoization
    //
    template< typename Type >
    class Solution_TopDown_with_Memoization
    {
        struct Query
        {
            Type base{ 0 };
            size_t power{ 0 };
            bool operator==( const Query& rhs ) const
            {
                return base == rhs.base && power == rhs.power;
            }
        };
        struct Hash
        {
            size_t operator()( const Query& q ) const
            {
                return q.base * ( maximum + 1 ) + q.power;
            }
        };
        using Map = unordered_map< Query, Type, Hash >;
        Map memo_;

        Type go( Type base, size_t power )
        {
            if( power == 0 )
                return memo_[ { base, power } ] = 1;

            return memo_[ { base, power } ] = base * go( base, power - 1 );
        }

    public:

        Type plusOnePower( Type base, size_t power )
        {
            return go( base + 1, power );
        }
    }; // class Solution_TopDown_with_Memoization


    //
    // bottom-up dynamic programming solution
    //
    template< typename Type >
    class Solution_BottomUp_with_DynamicProgramming
    {
        using Collection = vector< Type >;
        using Collections = vector< Collection >;
        const size_t N;
        Collections DP_;

    public:

        Solution_BottomUp_with_DynamicProgramming() :
            N{ maximum + 1 },
            DP_( N, Collection( N, 1 ) ) // base case: dp[ base ][ power=0 ] = 1
        {
            for( auto base{ 0 }; base < N; ++base )
                for( auto power{ 1 }; power < N; ++power )
                    DP_[ base ][ power ] = base * DP_[ base ][ power - 1 ];
        }

        Type plusOnePower( Type base, size_t power )
        {
            return DP_[ base + 1 ][ power ];
        }
    }; // class Solution_BottomUp_with_DynamicProgramming


} // namespace xnor_ai


int main() try
{
    using Type = int;

    xnor_ai::Solution_TopDown_with_Memoization< Type > topDownSolution;
    Type topDownResult = topDownSolution.plusOnePower( 2, 3 );
    assert( topDownResult == 27 );

    xnor_ai::Solution_BottomUp_with_DynamicProgramming< Type > bottomUpSolution;
    Type bottomUpResult = bottomUpSolution.plusOnePower( 2, 3 );
    assert( bottomUpResult == 27 );

    return 0;
}
catch( const exception& e )
{
    cout << e.what() << endl << endl;

    return -1;
}
