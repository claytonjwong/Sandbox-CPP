//
//  main.cpp
//  CH7_Recursion
//
//  Created by CLAYTON WONG on 6/6/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//



#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//
// telephony words
//
class TelephoneWords {
    vector<string> ans;
    unordered_map<char,string> m{
        {'2',"ABC"},{'3',"DEF"},{'4',"GHI"},
        {'5',"JKL"},{'6',"MNO"},{'7',"PRS"},
        {'8',"TUV"},{'9',"WXY"},
    };
    void go(const string& num, string& path, int pos=0){
        int N=(int)num.size();
        if (pos==N){
            ans.push_back(path);
            return;
        }
        char digit=num[pos];
        string letters=m[digit];
        for (auto letter: letters){
            path.push_back(letter);
            go(num,path,pos+1);
            path.pop_back();
        }
    }
public:
    vector<string> getWords(const string& num, string path=""){
        ans.clear();
        go(num,path);
        return ans;
    }
};


int main(int argc, const char * argv[]) {

    TelephoneWords tw;
    auto r=tw.getWords("234");
    for (auto x: r)
        cout << x << endl;

    return 0;
}
