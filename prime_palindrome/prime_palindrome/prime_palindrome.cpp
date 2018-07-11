/*
 
 867. Prime Palindrome
 
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int primePalindrome(int N) {
        if (N<12) return N<=2 ? 2 : N<4 ? 3 : N<6 ? 5 : N<8 ? 7 : 11;
        for (int i=10; i<1000000; ++i){
            string odd=to_string(i),even(odd+odd.back());
            for (int j=int(odd.size())-2; j>=0; --j){
                char c=odd[j];
                odd.push_back(c);
                even.push_back(c);
            }
            int p=stoi(odd),q=stoi(even);
            if (p>=N && isPrime(p))
                return p;
            if (q>=N && isPrime(q))
                return q;
        }
        return -1;
    }
private:
    bool isPrime(int x) {
        for (int i=2,M=(int)ceil(sqrt(x)); i<=M; ++i)
            if (x%i==0)
                return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
//    cout << "2==" << s.primePalindrome(1) << endl;
//    cout << "2==" << s.primePalindrome(2) << endl;
//    cout << "3==" << s.primePalindrome(3) << endl;
//    cout << "5==" << s.primePalindrome(4) << endl;
//    cout << "7==" << s.primePalindrome(6) << endl;
//    cout << "11==" << s.primePalindrome(8) << endl;
//    cout << "11==" << s.primePalindrome(9) << endl;
//    cout << "11==" << s.primePalindrome(10) << endl;
//    cout << "11==" << s.primePalindrome(11) << endl;
//    cout << "101==" << s.primePalindrome(12) << endl;
    cout << "131==" << s.primePalindrome(102) << endl;
    cout << "100030001==" << s.primePalindrome(9989900) << endl;
    
    return 0;
}
