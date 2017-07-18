#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b){
    
    // gcd(a,0) = a
    // gcd(a,b) = gcd( b, a % b )
    while (b > 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

int maximumGcdAndSum(vector <int> a, vector <int> b) {
    int max_gcd = 0;
    int max_sum = 0;
    
    for (int i=0; i < a.size(); i++){
        for (int j=0; j < b.size(); j++){
            
            int curr_gcd = gcd(a[i],b[j]);
            
            if (curr_gcd > max_gcd){
                max_gcd = curr_gcd;
                max_sum = a[i] + b[i];
            }
            
            if ( curr_gcd == max_gcd && (a[i] + b[j]) > max_sum ){
                max_sum = a[i] + b[j];
            }
        }
    }
    
    return max_sum;
    
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
        cin >> A[A_i];
    }
    vector<int> B(n);
    for(int B_i = 0; B_i < n; B_i++){
        cin >> B[B_i];
    }
    int res = maximumGcdAndSum(A, B);
    cout << res << endl;
    return 0;
}
