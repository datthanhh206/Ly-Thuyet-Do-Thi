#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];             // Danh sách kề
bool visited[1001];                // Đánh dấu đỉnh đã thăm
vector<pair<int, int>> tree_edges; // Lưu các cạnh thuộc cây khung DFS

// Hàm nhập dữ liệu từ file
void inp() {
    ifstream fin("CAYKHUNG_DFS.INP"); // Mở file input
    fin >> n >> m; // Nhập số đỉnh và số cạnh

    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Vì đồ thị vô hướng nên thêm cả chiều ngược lại
    }

    fin.close(); // Đóng file sau khi đọc xong

    // Sắp xếp danh sách kề để DFS duyệt theo thứ tự tăng dần
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    memset(visited, false, sizeof(visited));
}

// Hàm duyệt DFS có lưu cạnh của cây khung
void dfs(int u) {
    visited[u] = true; // Đánh dấu đỉnh u đã thăm
    for (int v : adj[u]) {
        if (!visited[v]) {
            tree_edges.push_back({u, v}); // Ghi lại cạnh thuộc cây khung
            dfs(v); // Đệ quy duyệt tiếp
        }
    }
}

int main() {
    inp();
    dfs(1); // Cây khung DFS bắt đầu từ đỉnh 1

    ofstream fout("CAYKHUNG_DFS.OUT"); // Mở file output để ghi kết quả

    fout << tree_edges.size() << endl; // Số cạnh trong cây khung (n-1)
    for (auto edge : tree_edges)
        fout << edge.first << " " << edge.second << endl;

    fout.close(); // Đóng file kết quả

    return 0;
}
