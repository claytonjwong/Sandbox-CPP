/*
 
 https://www.codechef.com/MARCH18B/submit/CHEGLOVE
 
 */

/*
#include <iostream>
#include <vector>

using namespace std;

string getGloveFitStr(int N, vector<int>& fingers, vector<int>& holes){
    
    bool front=true,back=true;
    for (int i=0; i<N; ++i){
        if (fingers[i]>holes[i]){
            front=false;
        }
        if (fingers[i]>holes[N-1-i]){
            back=false;
        }
    }
    return front&&back ? "both" : front ? "front" : back ? "back" : "none";
}

int main(int argc, const char * argv[]) {
    
    
    int T,N;
    cin >> T;
    for (int i=0; i<T; ++i){
        cin >> N;
        vector<int> fingers(N),holes(N);
        for (int i=0; i<N; ++i)
            cin >> fingers[i];
        for (int i=0; i<N; ++i)
            cin >> holes[i];
        cout << getGloveFitStr(N, fingers, holes) << endl;
    }

    return 0;
}



*/
