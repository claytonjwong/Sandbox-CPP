/*
 
 https://leetcode.com/contest/weekly-contest-82
 
 Rank           Name             Score    Finish Time     Q1 (4)     Q2 (5)       Q3 (7)    Q4 (8)
 113 / 2563     claytonjwong     16       0:42:23         0:09:05    0:24:37  1   0:37:23
 
 Q1: https://leetcode.com/contest/weekly-contest-82/problems/goat-latin/
 A1: https://leetcode.com/problems/goat-latin/discuss/126940/C++-stringstream
 
 Q2: https://leetcode.com/contest/weekly-contest-82/problems/friends-of-appropriate-ages/
 A2: https://leetcode.com/problems/friends-of-appropriate-ages/discuss/127014/C++-solution-with-explanation
 
 Q3: https://leetcode.com/contest/weekly-contest-82/problems/most-profit-assigning-work/
 A3: https://leetcode.com/problems/most-profit-assigning-work/discuss/126999/C++-map
 
 
 */


#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <numeric>

using namespace std;

/*
class Solution {
public:
    string toGoatLatin(string S) {
        istringstream is(S); ostringstream os;
        string V="aeiouAEIOU",s,a="a";
        while (is >> s){
            if (V.find(s[0])==string::npos)
                os << s.substr(1) << s[0];
            else
                os << s;
            os << "ma" << a << " ";
            a.push_back('a');
        }
        string ans=os.str();
        ans.pop_back();
        return ans;
    }
};
 */

/*
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> A(121);
        for (auto x: ages) ++A[x];
        int cnt=0; for (int i=15; i<121; ++i){
            if (i>0.5*i+7) cnt-=A[i];
            for (int j=i; j>0.5*i+7; --j)
                cnt+=A[i]*A[j];
        }
        return cnt;
    }
};
*/

/*
class Solution {
public:
    int maxProfitAssignment(vector<int>& D, vector<int>& P, vector<int>& W) {
        map<int,int> M; M[0]=0;
        for (int i=0; i<D.size(); ++i)
            M[D[i]]=max(M[D[i]],P[i]);
        int maxp=0; for (auto& x: M)
            x.second=maxp=max(maxp,x.second);
        int ans=0; for (auto w: W)
            ans+=prev(M.upper_bound(w))->second;
        return ans;
    }
};
*/

class Solution{
public:
    int maxProfitAssignment(vector<int>& lv, vector<int>& profit, vector<int>& worker, int res = 0) {
        map<int, int> m; m[0]=0;
        for (auto i = 0; i < lv.size(); ++i) m[lv[i]] = max(m[lv[i]], profit[i]);
        for (auto it = next(m.begin()); it != m.end(); ++it) it->second = max(it->second, prev(it)->second);
        for (auto w : worker) res += prev(m.upper_bound(w))->second;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    /*
    string S="The quick brown fox jumped over the lazy dog";
    Solution s;
    cout << s.toGoatLatin(S) << endl;
    
    // Imaa peaksmaaa oatGmaaaa atinLmaaaaa
    // Imaa peaksmaaa oatGmaaaa atinLmaaaaa
    
    // "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa
    // "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
    */
    
    /*
    vector<int> ages={16,16};
    Solution s;
    cout << s.numFriendRequests(ages) << endl;
    */
    
    vector<int> D = { 2, 4, 6, 8,10},
                P = {10,20,30,40,50}, W = {4,5,6,7};
    Solution s;
    cout << s.maxProfitAssignment(D, P, W) << endl;;
    
    
    return 0;
}



