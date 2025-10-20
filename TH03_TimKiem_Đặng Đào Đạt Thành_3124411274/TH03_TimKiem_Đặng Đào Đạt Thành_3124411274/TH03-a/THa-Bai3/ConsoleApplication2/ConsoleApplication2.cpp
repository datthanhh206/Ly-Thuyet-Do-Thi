#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;

vector<int> bfs(int start) {
    vector<int> comp;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        comp.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return comp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }

    vector<vector<int>> components;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components.push_back(bfs(i));
        }
    }

    cout << components.size() << "\n";
    for (auto& comp : components) {
        for (int v : comp) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
