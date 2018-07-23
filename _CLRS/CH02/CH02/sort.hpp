/*
 
 INSERTION-SORT
 
 SELECTION-SORT
 
 BUBBLE-SORT
 
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

//
// INSERTION-SORT
//
// Loop Invariant:
//
// The subarray A[0:j) contains the original elements in A[0:j) in sorted order
//
// Note:
//
// A[0:j) denotes A[0] to A[j] non-inclusive.
// This is the same as A[0] to A[j-1] inclusive: i.e. A[0:j-1]
//
void insertion_sort1(vector<int>& A) {
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

void insertion_sort2(vector<int>& A) {
    
    for (int j=1,N=(int)A.size(); j<N; ++j){
        
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

//
// SELECTION-SORT
//
// Loop Invariant:
//
// The left-most i items in A are ordered minimum values in A[0:N),
// starting with i=0 ( no items ) and ending at i=N-2 ( the second to last item ).
//
// Note:
//
// There is no need to iterate i all the way to N-1 ( the last item ) since A[N-1] is
// the maximum value in A and is also the minimum element in the range A[N-1:N-1],
// therefore, the last item A[N-1] would be swapped with itself if i were allowed
// to iterate until N-1.
//
void selection_sort1(vector<int>& A){
    for (int i=0,N=(int)A.size(); i<N-1; ++i){
        int minj=i;
        for (int j=i+1; j<N; ++j)
            if (A[minj] > A[j])
                minj=j;
        swap(A[i],A[minj]);
    }
}

void selection_sort2(vector<int>& A){
    for (int i=0,N=(int)A.size(); i<N-1; ++i){
        int j=(int)distance(A.begin(),min_element(A.begin()+i, A.end()));
        swap(A[i],A[j]);
    }
}

void selection_sort3(vector<int>& A){
    if (A.empty()) return;
    for (auto i=A.begin(),N=A.end(); i!=prev(N); ++i){
        auto j=min_element(i, N);
        iter_swap(i,j);
    }
}

void selection_sort4(vector<int>& A){
    if (A.empty()) return;
    for (auto i=A.begin(),N=A.end(); i!=prev(N); ++i)
        iter_swap(i,min_element(i, N));
}

void selection_sort5(vector<int>& A){
    for (auto i=A.begin(),N=A.end(); i!=N && i!=prev(N); iter_swap(i,min_element(i++, N)));
}

//
// BUBBLE-SORT
//
// loop-invariant:
//
// the right-most i elements are the largest i elements in A[0:N), 0<=i<N
// sorted in ascending order
//
void bubble_sort1(vector<int>& A){
    bool swapped;
    do {
        swapped=false;
        for (int i=1,N=(int)A.size(); i<N; ++i)
            if (A[i-1] > A[i]){
                swap(A[i-1],A[i]);
                swapped=true;
            }
    } while (swapped);
}

void bubble_sort2(vector<int>& A){
    bool swapped;
    do {
        swapped=false;
        for (auto itr=A.begin(); itr!=A.end() && itr!=prev(A.end()); ++itr)
            if (*itr > *next(itr)){
                iter_swap(itr,next(itr));
                swapped=true;
            }
    } while (swapped);
}


void print(const vector<int>& A){
    ostringstream os;
    for (auto x: A)
        os << x << ",";
    string str(os.str());
    str.pop_back();
    cout << str << endl;
}

