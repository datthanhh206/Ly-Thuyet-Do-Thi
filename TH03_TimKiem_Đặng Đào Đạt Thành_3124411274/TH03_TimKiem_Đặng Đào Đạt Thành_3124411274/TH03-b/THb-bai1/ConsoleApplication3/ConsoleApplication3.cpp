#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
vector<int> result;
int n, x;

void dfs(int u) {
    visited[u] = true;
    result.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
            adj[v].push_back(i); // vì đồ thị vô hướng
        }
    }

    memset(visited, false, sizeof(visited));
    dfs(x);

    cout << result.size() << "\n";
    for (int v : result) cout << v << " ";
    cout << "\n";

    return 0;
}
