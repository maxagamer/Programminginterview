// enable assertions in release build
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <cassert>
#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

/************** begin assignment **************/
// Implement a function which takes as input an sorted array and a key, and
// updates the array so that all occurrences of the input key have been removed
// and the remaining elements have been shifted left to fill the emptied
// indices. Return the number of remaining elements. Values beyond the last
// valid element are the same as in the original array.
// (Requirements: O(1) space, O(n) time)

void printVec(vector<int> &v){
    cout << "{";
    for (int i : v) cout << ", " << i;
    cout << "}";
}

inline size_t delete_keys(vector<int> &v, const int key) {
    // edge cases
    if(v.empty()) return 0;
    if(v.size() == 1 && v.at(0) == key) return 0;
    //size is to measure how many valid elements still remain
    int size = v.size();
    // to push back the last item and contain length
    int lastItem = v.back();
    // pointer to the first element of the vector v
    vector<int>::iterator it = v.begin();
    vector<int>::iterator end = v.end();

    // we go through the vector until we reach the end ( of the vector we put in not the
    // end of the vector that it is after we erased stuff
    while(it != end){
        // if the value at the address of the pointer matches key
        if(*it == key){
            // erase the value
            v.erase(it);
            // pushback the last element to contain size and condition of the exercise
            v.push_back(lastItem);
            // decrease size, because we lost a valid element
            size--;
            // we intentionally don't increase the pointer value
            // so we stay at the postion, because our pointer points now to the next element
        }
        // if it is now the value we search for we continue
        else it++;
    }
    return size;
}

/*************** end assignment ***************/

int main() {

    {
        vector<int> v;
        vector<int> vresult;
        int key = 1;
        auto valid_entries = delete_keys(v, key);
        assert(v == vresult);
        assert(valid_entries == 0);
    }
    {
        vector<int> v{1};
        vector<int> vresult{1};
        int key = 2;
        auto valid_entries = delete_keys(v, key);
        assert(v == vresult);
        assert(valid_entries == 1);
    }
    {
        vector<int> v{1};
        vector<int> vresult{1};
        int key = 1;
        auto valid_entries = delete_keys(v, key);
        assert(v == vresult);
        assert(valid_entries == 0);
    }
    {
        vector<int> v           {1, 2, 3};
        vector<int> vresult     {2, 3, 3};
        int key = 1;
        auto valid_entries = delete_keys(v, key);
        assert(v == vresult);
        assert(valid_entries == 2);
    }
    /* wrong case
    {
        vector<int> v           {1, 2, 2, 3};
        vector<int> vresult     {1, 3, 2, 3};
        int key = 2;
        auto valid_entries = delete_keys(v, key);
        assert(v == vresult);
        assert(valid_entries == 2);
    }
    */


    // right case
    {
        vector<int> v           {1, 2, 2, 3};
        vector<int> vresult     {1, 3, 3, 3};
        int key = 2;
        auto valid_entries = delete_keys(v, key);
        assert(v == vresult);
        assert(valid_entries == 2);
    }
    {
        vector<int> v           {1, 2, 2, 3, 3};
        vector<int> vresult     {1, 3, 3, 3, 3};
        int key = 2;
        auto valid_entries = delete_keys(v, key);
        assert(v == vresult);
        assert(valid_entries == 3);
    }
    {
        vector<int> v           {2, 3, 5, 5, 7, 11, 11, 11, 13};
        vector<int> vresult     {2, 3, 5, 5, 11, 11, 11, 13, 13};
        int key = 7;
        auto valid_entries = delete_keys(v, key);
        assert(v == vresult);
        assert(valid_entries == 8);
    }
    cout << "all tests passed" << endl;

}

