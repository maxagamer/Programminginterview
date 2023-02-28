#include <iostream>

#include <iostream>
#include <unordered_map>

using namespace std;

void threeNPlusOne(int n, unordered_map<int, int> &u){
    int start = n;
    if(n <= 0) return;
    if(n == 1) return;
    int count = 0;
    while(n != 1){
        if(u[n]){
            count += u[n];
            u[start] = count;
            return;
        }
        if(n % 2 == 1) n = 3 * n + 1;
        else n /= 2;
        count++;
    }
    u[start] = count;
    return;
}

int main() {

    // n, count
    unordered_map<int, int> u;
    threeNPlusOne(1, u);
    threeNPlusOne(10, u);

    threeNPlusOne(100, u);
    threeNPlusOne(200, u);

    threeNPlusOne(201, u);
    threeNPlusOne(210, u);

    threeNPlusOne(900, u);
    threeNPlusOne(1000, u);

    return 0;
}

/*
1 10
100 200
201 210
900 1000
 *
 */
