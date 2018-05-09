//
//  StudentIO.cpp
//  EWeek2
//
//  Created by CLAYTON WONG on 5/3/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#include <sstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include "StudentIO.hpp"
#include "Student.hpp"

using namespace std;

void StudentIO::ExecIO() {
    Input();
    Output();
}

void StudentIO::Input() {
    unordered_map<char,vector<Student>> map;
    string str;
    while (getline(myFin,str,',')){
        int id=DEFAULT_ID;
        str=Strip(str);
        auto pos=str.find(';');
        string name=str.substr(0,pos);
        char key=name[0];
        if (pos==string::npos)
            cout << "Student <" << str << "> did not have an ID" << endl;
        else
            id=stoi(str.substr(str.find(';')+1));
        map[key].emplace_back(Student(name,id));
    }
    for (auto& x: map)
        myStudents.emplace_back(move(x.second));
}

void StudentIO::Output() {
    for (auto& students: myStudents){
        for (auto& s: students){
            string name=s.getName();
            if (name.empty()) continue;
            char C=toupper(name[0]);
            cout << C << ":  " << Pad(name,20) << s.getID() << endl;
        }
    }
}

// helper function used to strip leading and trailing whitespace
string StudentIO::Strip(const string& s) const {
    int i=0,j=(int)s.size();
    if (isspace(s[i])) ++i;
    if (s.size() > 2 && isspace(s[j-1])) --j;
    return s.substr(i,j-i);
}

string StudentIO::Pad(const string& s, const int& len) const  {
    int i=(int)s.size();
    if (len < i) return s;
    int padding=len-i;
    return s+string(padding,' ');
}
