#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, x, y;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;

bool bfs(int start, int target) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == target) return true; // tìm thấy y

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }

    if (!bfs(x, y)) {
        cout << "0\n"; // không có đường đi
        return 0;
    }

    // Truy vết đường đi từ y ngược về x
    vector<int> path;
    for (int cur = y; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
        if (cur == x) break;
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}

/*

8 3 8
2 -1
1 5 -1
4 -1
3 7 -1
2 -1
-1
4 8 -1
7 -1

*/