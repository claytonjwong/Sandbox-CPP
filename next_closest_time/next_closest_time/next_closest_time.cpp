/*
 
 681. Next Closest Time
 
 https://leetcode.com/contest/leetcode-weekly-contest-51/problems/next-closest-time/
 
 Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.
 
 You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
 
 Example 1:
 
 Input: "19:34"
 Output: "19:39"
 Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
 Example 2:
 
 Input: "23:59"
 Output: "22:22"
 Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
 
 */

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        set<char> digits{};
        for (auto& ch : time){
            if (isdigit(ch)){digits.insert(ch);}
        }
        int hour=stoi(time.substr(0,2));
        int minute=stoi(time.substr(3,2));
        auto next=make_pair(hour,minute);
        while(true){

            nextMinute(next);
            string nextTime="";
            if (next.first<10){ nextTime.push_back('0'); } nextTime+=to_string(next.first);
            nextTime.push_back(':');
            if (next.second<10){ nextTime.push_back('0'); } nextTime+=to_string(next.second);

            bool valid=true;
            for (auto& ch : nextTime){
                if (isdigit(ch) && digits.find(ch)==digits.end()){
                    valid=false;
                    break;
                }
            }
            if (valid) { return nextTime; }
        }
    }
private:
    void nextMinute(pair<int,int>& t){
        if (++t.second==60){
            t.second=0;
            ++t.first;
        }
        if (t.first==24){
            t.first=0;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    while(true){
        string time;
        cout << "time: ";
        cin >> time;
        cout << solution.nextClosestTime(time) << endl;
    }
    
    
    return 0;
}



