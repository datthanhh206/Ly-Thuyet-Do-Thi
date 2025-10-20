#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, x, y, z;
vector<vector<int>> adj;
vector<bool> visited;

void bfs(int start, int skipNode, int skipU = -1, int skipV = -1) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (v == skipNode) continue;
            if ((u == skipU && v == skipV) || (u == skipV && v == skipU)) continue;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int countComponents(int skipNode = -1, int skipU = -1, int skipV = -1) {
    visited.assign(n + 1, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == skipNode) continue;
        if (!visited[i]) {
            cnt++;
            bfs(i, skipNode, skipU, skipV);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y >> z;
    adj.assign(n + 1, {});

    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }

    // Đếm số thành phần ban đầu
    int initialCC = countComponents();

    // Kiểm tra cạnh cầu
    int withoutEdgeCC = countComponents(-1, x, y);
    if (withoutEdgeCC > initialCC)
        cout << "canh cau\n";
    else
        cout << "khong la canh cau\n";

    // Kiểm tra đỉnh khớp
    int withoutNodeCC = countComponents(z);
    if (withoutNodeCC > initialCC)
        cout << "dinh khop\n";
    else
        cout << "khong la dinh khop\n";

    return 0;
}
