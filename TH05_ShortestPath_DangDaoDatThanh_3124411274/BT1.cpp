#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <fstream>
#include <limits>

using namespace std;

const long long INF = 1e18; 

typedef pair<long long, int> DistanceNode; 

int main() {
    ifstream fin("dijkstra.in");
    ofstream fout("dijkstra.out");

    if (!fin.is_open()) {
        cout << "Khong mo duoc file dau vao!" << endl;
        return 1;
    }

    int n, m, s, t;
    if (!(fin >> n >> m >> s >> t)) {
        fin.close(); fout.close();
        return 1; 
    }

    vector< vector<pair<int, int>> > adj(n + 1); 
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        if (fin >> u >> v >> w) {
            adj[u].push_back(make_pair(v, w));
        }
    }

    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1); 

    priority_queue<DistanceNode> pq;

    dist[s] = 0;
    pq.push(make_pair(-0, s)); 

    while (!pq.empty()) {
        DistanceNode top = pq.top();
        pq.pop();

        long long du = -top.first;  
        int u = top.second;      

        if (du > dist[u]) {
            continue;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.first;  
            int w = edge.second; 

            if (dist[v] > dist[u] + w) { 
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }

    if (dist[t] == INF) {
        fout << "Khong co duong di" << endl;
    } else {
        vector<int> path;
        int curr = t;
        for (int i = 0; i <= n && curr != -1; ++i) { 
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end()); 

        fout << path.size() << " " << dist[t] << endl;
        
        for (size_t i = 0; i < path.size(); i++) {
            fout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        fout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}