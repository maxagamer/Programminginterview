#include <iostream>

#include <iostream>
#include <unordered_map>
#include <cassert>

using namespace std;
/***
 *
 * @param n     is n
 * @param u     is a map to save every problem that was once solved
 * @return      returns count
 *              if we encounter a solution we already computed we
 *              don't have to calculate them again
 */
int threeNPlusOne(int n, unordered_map<int, int> &u){
    int start = n;
    if(n <= 0){
        u[0] = 1;
        return 0;
    }
    if(n == 1){
        u[1] = 1;
        return 1;
    }
    int count = 0;
    while(n != 1){
        if(u[n]){
            count += u[n];
            u[start] = count;
            return count;
        }
        if(n % 2 == 1) n = 3 * n + 1;
        else n /= 2;
        count++;
    }
    u[start] = count;
    return count;
}

int main() {

    unordered_map<int, int> u;
    assert(6 == threeNPlusOne(10, u));
    assert(25 == threeNPlusOne(100, u));
    assert(26 == threeNPlusOne(200, u));
    assert(18 == threeNPlusOne(201, u));
    assert(39 == threeNPlusOne(210, u));
    assert(54 == threeNPlusOne(900, u));
    assert(111 == threeNPlusOne(1000, u));

    cout << "All tests passed";

    return 0;
}

