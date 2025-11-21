#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <limits>

using namespace std;

const long long INF = 1e18; 

struct Edge {
    int to;
    int w;
};

vector<long long> dijkstra(int n, int st, const vector<vector<Edge>>& g, vector<int>& parent) {
    vector<long long> dist(n + 1, INF);
    parent.assign(n + 1, -1);
    
    priority_queue<pair<long long, int>> pq; 

    dist[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {
        auto [neg, u] = pq.top(); pq.pop();
        long long du = -neg;
        
        if (du != dist[u]) continue;

        for (auto &e : g[u]) {
            int v = e.to;
            int w = e.w;
            
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({-dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ifstream fin("ngannhat.in");
    ofstream fout("ngannhat.out");

    int n, m, s, t, x;
    if (!(fin >> n >> m >> s >> t >> x)) return 0;

    vector<vector<Edge>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        if (fin >> u >> v >> w) {
            g[u].push_back({v, w});
        }
    }

    vector<int> p1, p2;
    auto dist_sx = dijkstra(n, s, g, p1);
    auto dist_xt = dijkstra(n, x, g, p2);

    long long dist_s_x = dist_sx[x];
    long long dist_x_t = dist_xt[t];

    if (dist_s_x == INF || dist_x_t == INF) {
        fout << "Khong co duong di\n";
        return 0;
    }

    long long total_dist = dist_s_x + dist_x_t;

    vector<int> path1, path2;
    
    for (int v = x; v != -1; v = p1[v]) path1.push_back(v);
    reverse(path1.begin(), path1.end());
    
    for (int v = t; v != -1; v = p2[v]) path2.push_back(v);
    reverse(path2.begin(), path2.end());

    path1.insert(path1.end(), path2.begin() + 1, path2.end());

    fout << path1.size() << " " << total_dist << "\n"; 
    
    for (int v : path1) fout << v << " ";
    fout << "\n";

    return 0;
}