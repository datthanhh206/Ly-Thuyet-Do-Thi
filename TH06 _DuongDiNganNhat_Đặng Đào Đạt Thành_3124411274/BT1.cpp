#include <bits/stdc++.h>
using namespace std;

struct Circle {
    double x, y, r;
};

struct State {
    int node, jumps, steps;
    bool operator>(const State &other) {
        if (jumps != other.jumps) return jumps < other.jumps; 
        return steps < other.steps; 
    }
};
double edgeDist(const Circle &a, const Circle &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) - (a.r + b.r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, S, T;
    cin >> N >> S >> T;
    vector<Circle> c(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> c[i].x >> c[i].y >> c[i].r;
    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            double d = edgeDist(c[i], c[j]);
            if (d <= 50) {
                adj[i].push_back({j, 0});
                adj[j].push_back({i, 0});
            } else if (d <= 60) {
                adj[i].push_back({j, 1});
                adj[j].push_back({i, 1});
            }
        }
    }
    const int INF = 1e9;
    vector<pair<int, int>> dist(N + 1, {INF, INF});
    vector<int> parent(N + 1, -1);
    vector<int> moveType(N + 1, -1); // 0: bước, 1: nhảy
    priority_queue<State, vector<State>> pq; 
    pq.push({S, 0, 0});
    dist[S] = {0, 0};
    while (!pq.empty()) {
        auto [u, jumps, steps] = pq.top(); pq.pop();
        if (make_pair(jumps, steps) > dist[u]) continue;
        
        for (auto [v, type] : adj[u]) {
            pair<int, int> newCost = {jumps + type, steps + 1};
            if (newCost < dist[v]) {
                dist[v] = newCost;
                parent[v] = u;
                moveType[v] = type;
                pq.push({v, newCost.first, newCost.second});
            }
        }
    }

    if (dist[T].first == INF) {
        cout << 1;
        return 0;
    }
    vector<pair<int, int>> path;
    for (int v = T; v != -1; v = parent[v]) {
        int type = (v == S ? 0 : moveType[v]);
        path.push_back({v, type});
    }
    reverse(path.begin(), path.end());
    cout << 0 << "\n";
    cout << dist[T].first << " " << path.size() << "\n";
    for (auto [id, type] : path)
        cout << id << " " << type << "\n";
    return 0;
}
