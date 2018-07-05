/*
 
 Pg. 18: INSERTION-SORT(A)
 
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*
void insertion_sort(vector<int>& A) {
    for (int j=1,N=(int)A.size(); j<N; ++j){
        int key=A[j];
        int i=j-1;
        while (i>=0 && A[i]>key){
            A[i+1]=A[i];
            --i;
        }
        A[i+1]=key;
    }
}
*/


void insertion_sort(vector<int>& A) {
    
    for (int j=1,N=(int)A.size(); j<N; ++j){ // loop invariant: the subarray A[0:j) contains the original
                                             //                 elements in A[0:j) in sorted order
                                             // note: A[0:j) denotes A[0] to A[j] non-inclusive
                                             //       this is the same as A[0] to A[j-1] inclusive
                                             //       ( i.e. A[0:j-1] )
        
        int key=A[j]; // key is the value to be inserted
        
        int i=j-1;    // i is the index of A where key will be inserted after
        
        while (i>=0 && A[i]>key){
                                //
                                // Summary:
                                //
                                // case 1) i is a terminal value -1
                                //
                                // XOR
                                //
                                // case 2) A[i]<=key
                                //

                                //
                                // Details:
                                //
                                // 2 cases for terminating conditions occur when attempting
                                // to find the first index i to the left of index j whose value A[i]<=key:
                                // Case 1) if there is no value i in A[0:j) such that A[i]<=key,
                                //         then i==-1.
                                // Case 2) if there is a value i in A[0:j) such that A[i]<=key,
                                //         then i equals the right-most index i<j whose value A[i]<=key
                                //
            
            A[i+1]=A[i];    // shift the contents of A[i:j] to the right by one
            --i;            // ( this is performed one index i at a time )
                            // until an index i is found to insert the key after
            
        }
        
        A[i+1]=key; // insert after A[i]
                    // for case 1) i==-1, A[i+1]==A[0], and A[0] is the smallest value in A[0:j)
                    // for case 2) A[i]<=key, A[i+1]==the location in A to insert the key just after A[i]
        
    }
}


void print(const vector<int>& A){
    ostringstream os;
    for (auto x: A)
        os << x << ",";
    string str(os.str());
    str.pop_back();
    cout << str << endl;
}

int main(int argc, const char * argv[]) {
    
    vector<int> A{5,2,4,6,1,3};
    cout << "Before: "; print(A);
    insertion_sort(A);
    cout << "After: "; print(A);
    
    return 0;
}
