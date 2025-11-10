#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];              // Danh sách kề
bool visited[1001];                 // Mảng đánh dấu đã thăm
vector<pair<int, int>> tree_edges;  // Lưu các cạnh thuộc cây khung BFS

// Hàm nhập đồ thị từ file
void inp() {
    ifstream fin("CAYKHUNG_BFS.INP"); // Mở file input
    fin >> n >> m; // Nhập số đỉnh và số cạnh

    for (int i = 0; i < m; i++) {
        int x, y;
        fin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Vì đồ thị vô hướng
    }

    fin.close(); // Đóng file input

    // Sắp xếp danh sách kề để BFS duyệt theo thứ tự tăng dần
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    memset(visited, false, sizeof(visited));
}

// Thuật toán BFS và ghi lại cây khung
void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Duyệt các đỉnh kề của u
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                tree_edges.push_back({u, v}); // Ghi lại cạnh thuộc cây khung
            }
        }
    }
}

int main() {
    inp();     // Đọc dữ liệu từ file
    bfs(1);    // Cây khung BFS bắt đầu từ đỉnh 1

    ofstream fout("CAYKHUNG_BFS.OUT"); // Mở file output

    fout << tree_edges.size() << endl; // Số cạnh của cây khung (n - 1 nếu liên thông)
    for (auto e : tree_edges)
        fout << e.first << " " << e.second << endl;

    fout.close(); // Đóng file output

    return 0;
}
