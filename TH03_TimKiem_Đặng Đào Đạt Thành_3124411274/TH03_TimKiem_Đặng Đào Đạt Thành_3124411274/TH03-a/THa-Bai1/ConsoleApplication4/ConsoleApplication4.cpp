#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }

    vector<int> visited(n + 1, 0);
    vector<int> result;
    queue<int> q;

    visited[x] = 1;
    q.push(x);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
                result.push_back(v); // chỉ lưu những đỉnh tìm được, KHÔNG lưu x
            }
        }
    }

    cout << result.size() << "\n";
    for (int v : result) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}


/*
8 7
2 -1
1 5 -1
4 -1
3 7 -1
2 -1
-1
4 8 -1
7 -1
*/
