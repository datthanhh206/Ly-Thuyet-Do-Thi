#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];
int n, x, y;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == y) return; // dừng nếu đã tới y

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
            adj[v].push_back(i); // thêm cạnh ngược lại vì đồ thị vô hướng
        }
    }

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    bfs(x);

    if (!visited[y]) {
        cout << 0 << "\n"; // không có đường đi
        return 0;
    }

    // dựng lại đường đi từ y về x
    vector<int> path;
    for (int cur = y; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }

    cout << path.size() << "\n";
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i > 0) cout << " ";
    }
    cout << "\n";

    return 0;
}
