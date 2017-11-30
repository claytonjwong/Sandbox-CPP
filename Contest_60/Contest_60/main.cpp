/*

 Contest 60
 
 */


#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

/*
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int newColor) {
        vector<vector<int>> res(img);
        int oldColor=res[sr][sc];
        helper(res,sr,sc,oldColor,newColor);
        return res;
    }
private:
    set<pair<int,int>> visited{};
    void helper(vector<vector<int>>& res, int r, int c, int o, int n){
        if (r<0 || c<0 || r==res.size() || c==res[0].size() || res[r][c]==n) return;
        if (visited.find({r,c})!=visited.end()) return;
        visited.insert({r,c});
        if (res[r][c]==o){
            res[r][c]=n;
            helper(res,r-1,c,o,n); // above
            helper(res,r,c+1,o,n); // right
            helper(res,r+1,c,o,n); // below
            helper(res,r,c-1,o,n); // left
        }
    }
};
*/


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i=0;
        while(i+1<asteroids.size()){
            if(asteroids[i]>0&&asteroids[i+1]<0){
                if(abs(asteroids[i])>abs(asteroids[i+1])){
                    asteroids.erase(asteroids.begin()+(i+1));
                }else if(abs(asteroids[i])<abs(asteroids[i+1])){
                    asteroids.erase(asteroids.begin()+(i));
                    --i;
                }else{
                    asteroids.erase(asteroids.begin()+(i),asteroids.begin()+i+2);
                    --i;
                }
            } else {
                ++i;
            }
        }
        return asteroids;
    }
};



int main(int argc, const char * argv[]) {
    
   
    Solution s;
    vector<int> v{10,5,-5};
    auto res=s.asteroidCollision(v);
    
    return 0;
}





