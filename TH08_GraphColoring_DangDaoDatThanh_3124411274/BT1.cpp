#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve_graph_coloring() {
    int n, m;
    cin >> n >> m; 

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> color(n + 1, 0);
    int maxColorUsed = 0; 

    for (int node = 1; node <= n; node++) {
        
        vector<bool> used(n + 1, false);

        for (int neighbor : adj[node]) {
            if (color[neighbor] != 0) {
                used[color[neighbor]] = true; 
            }
        }

        int chosenColor = 1;
        while (used[chosenColor]) {
            chosenColor++;
        }

        color[node] = chosenColor;
        maxColorUsed = max(maxColorUsed, chosenColor);
    }

    // Chuẩn bị và In kết quả
    vector<vector<int>> colorGroups(maxColorUsed + 1);
    for (int node = 1; node <= n; node++) {
        colorGroups[color[node]].push_back(node);
    }

    cout << maxColorUsed << "\n";

    for (int c = 1; c <= maxColorUsed; c++) {
        for (int node : colorGroups[c]) {
            cout << node << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve_graph_coloring();

    return 0;
}