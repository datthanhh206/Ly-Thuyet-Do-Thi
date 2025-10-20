#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int n, vector<vector<int>>& adj) {
    vector<int> color(n + 1, -1); // -1 = chưa tô, 0 và 1 là 2 màu

    for (int start = 1; start <= n; start++) {
        if (color[start] == -1) { // Nếu thành phần liên thông chưa duyệt
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u]; // tô màu đối lập
                        q.push(v);
                    }
                    else if (color[v] == color[u]) {
                        return false; // xung đột màu → không phân đôi
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    cout << "Nhap cac canh (u v), ket thuc bang -1 -1:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u < 1 || v < 1 || u > n || v > n) {
            continue;
        }
        // Nếu đồ thị vô hướng:
        adj[u].push_back(v);
        adj[v].push_back(u);

        // Nếu đồ thị có hướng thì chỉ cần:
        // adj[u].push_back(v);
    }

    if (isBipartite(n, adj)) {
        cout << "Do thi phan doi\n";
    }
    else {
        cout << "Do thi khong phan doi\n";
    }

    return 0;
}
