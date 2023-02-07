#include <vector>
#include <iostream>

void main() {

}

vector<int> readVals() {
    vector<int> v;
    while (cin >> value)
    {
        v.push_back(value);
    }
    return v;
    
};
void printVals(vector<int> v) {
    for (int i = 0; i < v.size(); i++){
        cout << v[i];
    }

};

// returns a vector of values from v that are greater than 0
// these values are in the same relative order as they are in v.
vector<int> valsGT0() {
    vOrigin = readVals;
    vector<int> vFiltered;
    for (int i = 0; i < vOrigin.size(); i++){
        if (vOrigin[i] > 0) {
            vFiltered.push_back(vOrigin[i]);
        }
    }
    cout << "Filtered vector: "
    printVals(vFiltered);
    cout << "\nFiltered vector: "
    printVals(vOrigin);
    
};

/**
 * returns location of last instance of target in v or -1 if not found
 */ 
int findLast(vector<int> v, int target) {
    int instance = -1;
    for (int i = 0; i < v.size(); i++){
        if (v[i] == target) {
            instance = i;
        }
    }
    
    return instance;
};

