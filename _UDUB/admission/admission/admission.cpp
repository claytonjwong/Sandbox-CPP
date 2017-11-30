/*
 
 Online admissions test
 
 */

#include <iostream>


/*
 
 Question 3.
 What's wrong with this C function?
 
 */

char* getpass()
{
    char password[10];
    scanf("%s\n", password);
    return password;
}

/*
 
 Answer 3: The address returned by getpass() is an address of a local variable "password"
 which only exists in the context of the activation record (stack) for the getpass() function.
 
 */


/*
 
 Write a program that prints the numbers from 1 to 100. But for multiples of three print "Fizz" instead of the number and for multiples of five print "Buzz". For numbers which are multiples of both three and five print "FizzBuzz".
 
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/*
class Solution {
public:
    void printNums(){
        vector<string> vs{};
        getNums(100,vs);
        for (auto &&s: vs)
            cout << s << endl;
    }
private:
     void getNums(int n, vector<string>& res) {
        return getNums(1,n,{{3,"Fizz"},{5,"Buzz"},{15,"FizzBuzz"}},res);
    }
    void getNums(int beg, int end, vector<pair<int,string>>&& mapping, vector<string>& res){
        map<int,string,std::greater<int>> hash{};
        for (auto &&x: mapping) hash[x.first]=x.second;
        for (int i=beg; i<=end; ++i){
            int j=i;
            string special{};
            for (auto &&x: hash){ // ordered using std::greater, so 15 is checked before 5 or 3
                if (j%x.first==0){
                    special=x.second;
                    break;
                }
            }
            special.empty() ? res.push_back(to_string(i)) : res.push_back(special);
        }
    }
};

struct Employee {
    string firstName,lastName,employeeNumber;
    double salary;
    Employee(string fn, string ln, string num, double sal)
        : firstName{fn}, lastName{ln}, employeeNumber{num}, salary{sal} {}
};
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        return helper(1,n,{{3,"Fizz"},{5,"Buzz"},{15,"FizzBuzz"}});
    }
private:
    vector<string> helper(int beg, int end, vector<pair<int,string>>&& mapping){
        vector<string> res{};
        map<int,string,std::greater<int>> hash{};
        for (auto &&x: mapping) hash[x.first]=x.second;
        for (int i=beg; i<=end; ++i){
            string special{};
            for (auto &&x: hash){
                if (i%x.first==0){
                    special=x.second;
                    break;
                }
            }
            if (special.empty()) res.push_back(to_string(i)); // normal
            else                 res.push_back(special);      // special
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<string> res=solution.fizzBuzz(100);
    return 0;
}
