#include <iostream>

using namespace std;

int countDJSets;

void init(int parent[], int rank[], int n){
    
    memset(rank, 0, sizeof(rank));

    for(int i = 0; i < n; ++i) parent[i]  = 65 + i;
    
    countDJSets = n;
}

int find(int parent[], int rank[], int x){
    if(x < 0) x = 0;
    if( x != parent[x] )
        parent[x] = find(parent, rank, parent[x]);
    return parent[x];
}


bool checkEqual(int parent[], int rank[], int x, int y){
    return find(parent, rank, x) == find(parent, rank, y);
}


void connect(int parent[], int rank[], int x, int y){
    if( !checkEqual(parent, rank, x, y) ){
        if( rank[x] > rank[y] )
            parent[y] = x;
        else{
            parent[x] = y;

            if(rank[x] == rank[y])
                rank[y] = rank[y] + 1;
        }
        countDJSets--;
    }
}

void unite(int parent[], int rank[], int x, int y){
    connect(parent, rank, find(parent, rank, x), find(parent, rank, y));
}

int main(){

    {
        int n = 4;
        int parent[n];
        int rank[n];
        string st[] = {"1" , " ", "E", "AB", "CE", "DB", "EC"};
        string s;
        init(parent, rank, n);
        for(int i = 2; i < sizeof(st)/sizeof(string); i++){
            s = st[i];
            unite(parent, rank, s[0] - 65, s[1] - 65);
        }
        cout << countDJSets;
    }

    {
        int n = 4;
        int parent[n];
        int rank[n];
        string st[] = {"1" , " ", "A", "B", "D", "E"};
        string s;
        init(parent, rank, n);
        for(int i = 2; i < sizeof(st)/sizeof(string); i++){
            s = st[i];
            unite(parent, rank, s[0] - 65, s[1] - 65);
        }
        cout << countDJSets;
    }
    {
        int n = 4;
        int parent[n];
        int rank[n];
        string st[] = {"1" , " ", "AB", "AC", "AD", "BA", "BC", "BD", "CD", "DC"};
        string s;
        init(parent, rank, n);
        for(int i = 2; i < sizeof(st)/sizeof(string); i++){
            s = st[i];
            unite(parent, rank, s[0] - 65, s[1] - 65);
        }
        cout << countDJSets;
    }

    return 0;
}



