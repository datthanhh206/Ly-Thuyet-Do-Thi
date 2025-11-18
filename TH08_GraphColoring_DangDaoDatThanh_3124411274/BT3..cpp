#include <iostream>
#include <vector>

using namespace std;

bool dfs(const vector<vector<int>>& adj, vector<int>& team, int u, int c) {
    team[u] = c;

    for (int v : adj[u]) {
        if (team[v] == 0) {
            // Gán đội ngược lại (1 -> 2, 2 -> 1)
            if (!dfs(adj, team, v, 3 - c)) {
                return false;
            }
        }
        else if (team[v] == c) {
            // Hàng xóm mà cùng đội -> xung đột
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> team(n + 1, 0); 
    bool possible = true;

    for (int i = 1; i <= n; i++) {
        if (team[i] == 0) {
            // Bắt đầu gán đội 1 cho thành phần liên thông mới
            if (!dfs(adj, team, i, 1)) {
                possible = false;
                break; 
            }
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << team[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}