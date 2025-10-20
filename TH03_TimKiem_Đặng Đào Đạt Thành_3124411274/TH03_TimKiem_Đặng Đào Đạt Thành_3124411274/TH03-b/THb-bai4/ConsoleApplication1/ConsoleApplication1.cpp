#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS_iterative(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n + 1, false);
    stack<int> st;

    st.push(start);
    visited[start] = true;

    cout << "Thu tu DFS: ";
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        cout << u << " ";

        // Duyệt ngược để thứ tự giống DFS đệ quy
        for (int i = (int)adj[u].size() - 1; i >= 0; --i) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
    cout << "\n";
}

int main() {
    int n, start;
    cout << "Nhap so dinh va dinh bat dau: ";
    cin >> n >> start;

    vector<vector<int>> adj(n + 1);

    cout << "Nhap danh sach ke (ket thuc moi dong bang -1):\n";
    for (int i = 1; i <= n; i++) {
        while (true) {
            int v;
            cin >> v;
            if (v == -1) break;
            adj[i].push_back(v);
        }
    }

    DFS_iterative(start, adj, n);

    system("pause");
    return 0;
}