#include <iostream>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>

using namespace std;

int f(int N){
    int a=0; for (int c=0,b=1; N--; c=b,b=a) a=b+c; return a;
}

int gcd(int a, int b){
    if (b==0)
        return a;
    return gcd(b,a%b);
}

int main(){
    
    while(true){
        int a,b;
        cout << "a,b: "; cin >> a >> b;
        cout << gcd(a,b) << endl;
    }
    
    return 0;
}
