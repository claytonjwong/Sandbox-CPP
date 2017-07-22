/*
 
 
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        if (nums.empty()){
            return 0;
        }
            
        // swap all instances of val to the end of the array
        int i = 0;
        int j = (int)nums.size() - 1;
        while ( true ){

            // end index
            while ( i < j && nums[j] == val ){
                j--;
            }
            
            if ( i == j ){
                break;
            }
            
            // move val to the the end
            if (nums[i] == val){
                
                // swap i and j
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            
            i++;

        }
        
        // if i is val, then return i as the array length
        // so that n[i] is NOT included in the array
        if ( nums[i] == val ){
            return i;
        } else {
            return i+1;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    vector<int> test = { 2, 1, 1, 1 };
    cout << "1 == " << solution.removeElement(test, 1) << endl << endl;
    
    return 0;
}
