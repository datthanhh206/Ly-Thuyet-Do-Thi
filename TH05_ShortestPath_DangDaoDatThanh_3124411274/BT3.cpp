#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits>

using namespace std;

const long long INF = 1e18; 

int main() {
    ifstream fin("floyd.in");
    ofstream fout("floyd.out");

    if (!fin.is_open()) {
        cout << "Khong mo duoc file dau vao 'floyd.in'!" << endl;
        return 1;
    }

    int n, m;
    if (!(fin >> n >> m)) return 0;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        if (!(fin >> u >> v >> w)) continue;

        dist[u][v] = min(dist[u][v], (long long)w);
        dist[v][u] = min(dist[v][u], (long long)w);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                fout << 0 << " ";
            } else {
                fout << dist[i][j] << " ";
            }
        }
        fout << "\n";
    }
    
    fin.close();
    fout.close();
    return 0;
}