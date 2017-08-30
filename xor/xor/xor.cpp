/*
 
 XOR
 
 */

#include <iostream>
#include <string>

using namespace std;



void PrintBinary(int n){
    
    string nstr="";
    for (int i=7; i>=0; i--){
        if (n & (1<<i)){
            nstr += "1";
        } else {
            nstr += "0";
        }
    }
    cout << nstr << endl;
}

void PrintIndex(){

    string istr="";
    for (int i=7; i>=0; i--){
        istr += to_string(i%10);
    }
    cout << istr << endl;
}

int main(int argc, const char * argv[]) {

    /*
     
     x = x ^ y
     y = x ^ y
     x = x ^ y
     
     x1 = x ^ y
     y1 = x1 ^ y
     x2 = x1 ^ y1
     
     
     y1 = x1 ^ y 
     y1 = (x ^ y ) ^ y
     y1 = x ^ ( y ^ y )
     y1 = x ^ (0)
     y1 = x
     
     x2 = x1 ^ y1
     x2 = (x ^ y) ^ x
     x2 = y ^ (x^x)
     x2 = y ^ (0)
     x2 = y
     
     */
    
    
    int n=10;
    
    cout << "     "; PrintIndex();
    
    int a=1;
    int b=3;
    cout << "     "; PrintBinary(a);
    cout << "     "; PrintBinary(b);
    cout << endl;
    
    //
    // include everything from a that is not in b
    //
    cout << "a^=b ";
    a ^= b;
    PrintBinary(a);
    cout << endl;
    
    
    cout << "b^=a ";
    b ^= a;
    PrintBinary(b);
    cout << endl;
    
    cout << "a^=b ";
    a ^= b;
    PrintBinary(a);
    cout << endl;
    
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    
    return 0;
}



