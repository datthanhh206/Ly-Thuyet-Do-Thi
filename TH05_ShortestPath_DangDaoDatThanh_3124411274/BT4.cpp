#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

#define FI "priorityqueue.in"
#define FO "priorityqueue.out"

const long long INF = 1e18; 
const int MAXN = 1005;

vector<pair<int, int>> adj[MAXN];
long long dist[MAXN]; // Chuyển sang long long
int trace[MAXN];
bool visited[MAXN];

void dijkstra(int start, int n)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
        trace[i] = -1;
    }

    dist[start]=0;

    for (int i = 1; i <= n; i++)
    {
        int u = -1;
        long long minDist = INF; // Dùng long long

        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && dist[j] < minDist)
            {
                minDist = dist[j];
                u = j;
            }
        }
        
        if (u == -1) break;

        visited[u] = true;

        for (auto &[v, w] : adj[u])
        {
            // Phép so sánh và cộng đã an toàn
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                trace[v] = u;
            }
        }
    }
}

int n, m, x, y; // x là S, y là T
int u, v, w;

void readInput(ifstream &fi)
{
    fi >> n >> m >> x >> y; 

    for (int i = 0; i < m; i++)
    {
        fi >> u >> v >> w;
        adj[u].push_back({v, w});
    }
}

int main()
{
    ifstream fi(FI);
    ofstream fo(FO);

    if (!fi.is_open()) {
        cout << "Khong mo duoc file dau vao 'dijkstra.in'!\n";
        return 1;
    }

    readInput(fi);

    dijkstra(x, n);

    if (dist[y] == INF) {
        fo << "Khong co duong di\n";
        return 0;
    }

    vector<int> path;
    int HTai = y;
    while (HTai != -1)
    {
        path.push_back(HTai);
        HTai = trace[HTai];
    }

    reverse(path.begin(), path.end());

    // Ghi kết quả ra file
    fo << path.size() << " " << dist[y] << "\n";
    for (auto node : path)
    {
        fo << node << " ";
    }

    fo << "\n";

    fi.close();
    fo.close();
    return 0;
}