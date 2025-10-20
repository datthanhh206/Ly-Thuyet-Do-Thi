#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    const int V = 7; // số đỉnh 0..6
    int adj[V][V] = { 0 };
    int deg[V] = { 0 };

    // đọc n quân domino
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        // giả sử input hợp lệ: 0 <= x,y <= 6
        adj[x][y] += 1;
        adj[y][x] += 1;
        deg[x]++; deg[y]++;
    }

    // kiểm tra mọi đỉnh có bậc chẵn
    for (int i = 0; i < V; ++i) {
        if (deg[i] % 2 != 0) {
            cout << 0 << '\n';
            return 0;
        }
    }

    // kiểm tra liên thông với các đỉnh có bậc > 0
    int start = -1;
    for (int i = 0; i < V; ++i) if (deg[i] > 0) { start = i; break; }
    if (start == -1) {
        // không có cạnh nào — coi như có chu trình rỗng?
        // theo đề nếu n=0 có thể in 1 và không in dòng tiếp
        cout << 1 << '\n';
        return 0;
    }

    vector<int> stk;
    vector<bool> vis(V, false);
    // DFS để check liên thông (vô hướng)
    vector<int> s;
    s.push_back(start);
    vis[start] = true;
    while (!s.empty()) {
        int u = s.back(); s.pop_back();
        for (int v = 0; v < V; ++v) {
            if (adj[u][v] > 0 && !vis[v]) {
                vis[v] = true;
                s.push_back(v);
            }
        }
    }
    for (int i = 0; i < V; ++i) {
        if (deg[i] > 0 && !vis[i]) {
            cout << 0 << '\n';
            return 0;
        }
    }

    // Hierholzer (iterative) để tìm chu trình Euler
    vector<int> circuit; // sẽ chứa dãy đỉnh (edges+1)
    stk.push_back(start);
    while (!stk.empty()) {
        int v = stk.back();
        int u_found = -1;
        for (int u = 0; u < V; ++u) {
            if (adj[v][u] > 0) {
                u_found = u;
                break;
            }
        }
        if (u_found != -1) {
            // dùng cạnh v-u_found
            adj[v][u_found]--;
            adj[u_found][v]--;
            stk.push_back(u_found);
        }
        else {
            // không còn cạnh đi tiếp từ v
            circuit.push_back(v);
            stk.pop_back();
        }
    }

    // circuit bây giờ là dãy đỉnh theo thứ tự ngược (từ cuối về đầu),
    // đảo ngược để được chu trình đúng: v0, v1, ..., vk  (k = n)
    reverse(circuit.begin(), circuit.end());

    // kiểm tra số cạnh có đúng n không (circuit.size() phải = n+1)
    if ((int)circuit.size() != n + 1) {
        // không dùng hết tất cả cạnh → không hợp lệ
        cout << 0 << '\n';
        return 0;
    }

    // In ra theo đề: 1 rồi n dòng domino (cặp đỉnh consecutive)
    cout << 1 << '\n';
    for (size_t i = 0; i + 1 < circuit.size(); ++i) {
        cout << circuit[i] << " " << circuit[i + 1] << '\n';
    }

    return 0;
}
