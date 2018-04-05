/*
 
 https://www.codechef.com/MARCH18B/submit/BIGSALE
 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    for (int i=0; i<T; ++i){
        int N;
        cin >> N;
        vector<int> prices(N),amounts(N);
        double total=0.0000;
        for (int j=0; j<N; ++j){
            double origPrice,amount,percent;
            cin >> origPrice >> amount >> percent;
            percent*=0.01;
            double upcount=origPrice*percent;
            double newPrice=(origPrice+upcount);
            double discount=newPrice*percent;
            newPrice=newPrice-discount;
            int loss=amount*(origPrice-newPrice);
            total+=loss;
        }
        cout << total << endl;
    }
    
    return 0;
}
