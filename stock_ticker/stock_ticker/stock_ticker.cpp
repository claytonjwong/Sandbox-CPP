/*
 
 Question from Bloomberg, be able to output top n quantities of stocks
 
 and insert/update existing records
 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



class Trans{
public:
    Trans(string, int);
    
    bool operator()(const Trans t1, const Trans t2) const {return t1.quantity < t2.quantity; }
    
    string ticker;
    int quantity;
};

Trans::Trans(string ticker, int quantity ){
    this->ticker = ticker;
    this->quantity = quantity;
}

class Solution{
public:
    Solution() {}
    
    void add(Trans trans){
        this->trans.push_back(trans);
        make_heap(this->trans.begin(), this->trans.end());
    }
private:
    vector<Trans> trans;
};

void update(string ticker, int quantity){
    
}

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
