#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define N 101


using namespace std;

int main() {

        int n;
        int count = 1;


        //cin >> n;
        do{
            cin >> n;
            if(n <= 1) break;

            int edges[101][101] = {};

            // int edges[n-1][n-1];
            // memset(edges, 0, sizeof(edges));

            int s, t, c, x, y, z;
            cin >> s >> t >> c;

            for (int i = 0; i < c; i++)
            {
                cin >> x >> y >> z;
                edges[x][y] += z;
                edges[y][x] += z;
            }
            int maxFlow = 0;

            while (true)
            {
                int path[101];
                memset(path, 0, sizeof path);

                queue<int> Q;

                Q.push(s);
                path[s] = s;
                while (!Q.empty() && !path[t])
                {
                    int now = Q.front();
                    Q.pop();
                    for (int i = 0; i < n; i++)
                        if (!path[i] && edges[now][i] > 0)
                        {
                            path[i] = now;
                            Q.push(i);
                        }
                }

                if (!path[t])
                    break;


                int new_f = 2147483647;

                for (int from = path[t], to = t; from != to; from = path[to = from])
                    new_f = new_f < edges[from][to] ? new_f : edges[from][to];

                for (int from = path[t], to = t; from != to; from = path[to = from])
                {
                    edges[from][to] -= new_f;
                    edges[to][from] += new_f;
                }
                maxFlow += new_f;


                cout << "\nNetwork " << count++ << "\n";
                cout << "The bandwidth is " << maxFlow << ".\n";

                for (int i = 0; i < n; i++)
                    memset(edges[i], 0, sizeof edges[i]);
            }
        }while (cin >> n && n);

        return 0;

}


