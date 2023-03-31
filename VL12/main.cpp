#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>
#include <stack>
#include <unordered_map>


using namespace std;

void Lerr(string st){
    cout << "-------------------------------" << st << "-------------------------------\n";
}

void printVecForReadOut(vector<vector<int>> a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i].size() << "\n";
        cout << a[i][0] + 1 << " ";
        for(int j = 1; j < a[i].size(); j++){
            cout << a[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}

/***
 *
 * @param a     is the vector with the given parameters
 * @return      returns a bool if the given vector is valid
 *
 *              This function tests and modifies the vector.
 *              Tested by using the sum of the numbers.
 *              If they are uneqal to (n*(n+1))/2 the
 *              numbers are not 1 to n. It also lower every
 *              value of every entry because this way it is
 *              easier to work with them as arrays start at 0
 */
bool checkNMod(vector<int> &a){
    int sum = 0;
    int supposedSum = (a.size()*(a.size() + 1))/2;
    for(int i = 0; i < a.size(); i++){
        sum += a[i];
        // we lower every entry,
        // so we can match it to our indices
        a[i]--;
        // if we
    }
    if(sum != supposedSum){
        cout << "Impossible\n";
        return false;
    }
    return true;
}

/***
 *
 * @param a     is the vector with the given parameters
 * @param p     array p given by the problem
 * @param q     array q given by the problem
 * @param n     the size of a
 *
 *              This function tests the cases for i = a[p[q[i]]]
 *
 */
void testSolution(const vector<int> &a,const int p[],const int q[],const int n){
    for(int i = 0; i < n; i++){
        if(i != a.at(p[q[i]])){
            cout << "\nImpossible\n";
            break;
        }
    }
}


/**
 *
 * @param a     is the vector with the given parameters
 * @param p     array p given by the problem
 * @param q     array q given by the problem
 * @param n     the size of a
 *
 *              This function calculates the solution by
 *              filtering every impossible case out and
 *              backtracking the possible solution
 */
void calculate(vector<int> &a, int p[], int q[], int n){

    // to find every index in O(1)
    unordered_map<int, int> find_indicies;
    for(int i = 0; i < a.size(); i++){
        find_indicies[a.at(i)] = i;
    }

    // this it to store every number in b
    // since bitset needs to know how big
    // it is while compiling I had to use
    // the biggest n possible (it is about 13KB,
    // if it really just stores single bit's)
    bitset<10000> indexOfP;
    bitset<10000> indexOfQ;

    // these stacks are used to backtrack what was done
    // and in case to roll back
    stack<int> accesssedElementsP;
    stack<int> accesssedElementsQ;

    // this variable is used to store at which point we are
    int count = 1;

    // first iteration
    if(a.at(0) == 0){
        q[0]                        = 1;
        p[1]                        = 0;
        indexOfQ[0]                 = 1;
        indexOfP[1]                 = 1;
        accesssedElementsQ.push(0);
        accesssedElementsP.push(1);
    }
    else {
        int tmpValue = a.at(0);
        if(tmpValue == 1){
            q[tmpValue]             = tmpValue + 1;
            p[tmpValue + 1]         = 0;
            indexOfQ[tmpValue]      = 1;
            indexOfP[tmpValue + 1]  = 1;
            accesssedElementsQ.push(tmpValue);
            accesssedElementsP.push(tmpValue + 1);
        }
        else {
            q[tmpValue]             = 1;
            p[1]                    = 0;
            indexOfQ[tmpValue]      = 1;
            indexOfP[1]             = 1;
            accesssedElementsQ.push(tmpValue);
            accesssedElementsP.push(1);
        }
    }

    // ----------------------------------Print---------------------------------- \\

    count++;

    {
        while(count <= n) {
            // we continue on the last used element which could be:
            // if it was 0 we continue at 1
            // if it was 1 we contonue at 2
            // if it was something else we continue at 0
            int tmpValue = accesssedElementsP.top();
            int tmpIndex = find_indicies[accesssedElementsP.top()];
            int i;

            if(!indexOfQ[tmpValue]) {
                for (i = 0; i < n; i++) {
                    if (i != tmpIndex && i != tmpValue) {
                        if (!indexOfP[i]) break;
                    }
                }
            }else{
                for(i = 0; i < n; i++){
                    if(!indexOfP[i]) break;
                }
                tmpValue = i;
                tmpIndex = find_indicies[i];
            }

            q[tmpValue] = i;
            p[i] = tmpIndex;
            indexOfQ[tmpValue] = 1;
            indexOfP[i] = 1;
            accesssedElementsQ.push(tmpValue);
            accesssedElementsP.push(i);
            count++;

        }


        // ----------------------------------Print---------------------------------- \\

        cout << "\n";
        for(int ia : a){
            cout << ia + 1  << " ";
        }
        cout << "\n";
        for(int i = 0; i < n; i++){
            cout << p[i] + 1 << " ";
        }
        cout << "\n";
        for(int i = 0; i < n; i++){
            cout << q[i] + 1 << " ";
        }

        // ----------------------------------End---------------------------------- \\


    }

}


/**
 *
 * @param a     vector filled with testcase vectors
 *
 *              This function is to manage/sort the the given vectors into there solution
 *              if(<2)  there is no solution
 *              if(<=3) hardcoded every solution
 *              if(>3)  the function calculation is called to calculate the solution
 */
void mainManager(vector<vector<int>> &a){
    for(int x = 0; x < a.size(); x++){
        int currSize = a[x].size();
        // errors message included in checkNMod
        if(!checkNMod(a[x])) return;
        // not solvable if it is less than 3
        else if(currSize < 3) cout << "Impossible\n";
        // special case n == 3
        else if(currSize == 3) {
            // testing on paper I solved all n = 3 cases,
            // so I just do it this way then
            if(a[x][0] == 1){
                if(a[x][1] == 2){
                    cout << "3 1 2\n";
                    cout << "2 3 1\n";
                }
                else cout << "Impossible\n";
            }
            else if(a[x][0] == 2){
                if(a[x][1] == 1) cout << "Impossible\n";
                else{
                    cout << "2 3 1\n";
                    cout << "2 3 1\n";
                }
            }
            else{
                if(a[x][1] == 1){
                    cout << "3 1 2\n";
                    cout << "3 1 2\n";
                }
                else cout << "Impossible\n";
            }
        }
        // for everything n > 3
        else {
            bool inOrder = true;
            for(int i = 0; i < a[0].size() - 1; i++){
                if(a[x].at(i) > a[x].at(i + 1)) inOrder = false;
            }
            // if the array we're currently looking at is in order there is an easy algorithm to solve this
            if(inOrder){
                // every in Cards should have those permutations if you just do p[i + 1] = i and q[i] = i + 1
                int p[currSize];
                int q[currSize];
                // to ensure the arrays are filled with zeroes
                memset(p, 0, sizeof(p));
                memset(q, 0, sizeof(q));
                for(int i = 0; i < currSize - 1; i++){
                    p[i + 1] = i;
                    q[i] = i + 1;
                }
                q[currSize - 1] = 0;
                p[0] = currSize - 1;

                // ----------------------------------Print---------------------------------- \\

                cout << "\n";
                for(int i = 0; i < currSize; i++){
                    cout << p[i] << " ";
                }
                cout << "\n";
                for(int i = 0; i < currSize; i++){
                    cout << q[i] << " ";
                }
            }else{
                int p[currSize];
                int q[currSize];
                // to ensure the arrays are filled with zeroes
                memset(p, 0, sizeof(p));
                memset(q, 0, sizeof(q));
                calculate(a[x], p, q, currSize);
                testSolution(a[x], p, q, currSize);
            }

            cout << "\n\n";
        }
    }

}

int main() {

    // Test Case Codeforces
    {
        vector<vector<int>> input;
        input.push_back({2, 1});
        input.push_back({1, 2, 3});
        input.push_back({2, 1, 4, 3});
        input.push_back({5, 1, 4, 2, 3});
        mainManager(input);
    }
    {
        vector<vector<int>> input;
        input.push_back({10, 2, 5, 7, 4, 11, 3, 1, 9, 6, 8});
        input.push_back({2, 4, 10, 7, 5, 1, 8, 9, 3, 6, 11});
        input.push_back({9, 8, 12, 4, 2, 10, 3, 1, 5, 6, 13, 11, 7});
        mainManager(input);
    }


    return 0;
}
