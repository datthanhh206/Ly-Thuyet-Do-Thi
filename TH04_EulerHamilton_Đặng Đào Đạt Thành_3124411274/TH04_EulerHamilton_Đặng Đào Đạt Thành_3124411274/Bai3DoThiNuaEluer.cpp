#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    vector<int> deg(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            deg[i] += adj[i][j];
        }
    }

    // Đếm số đỉnh bậc lẻ
    vector<int> odd;
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 == 1) odd.push_back(i);
    }

    if (!(odd.size() == 0 || odd.size() == 2)) {
        cout << 0;
        return 0;
    }

    // Tìm điểm bắt đầu
    int start = 1;
    if (odd.size() == 2) start = odd[0];
    else {
        for (int i = 1; i <= n; i++) if (deg[i] > 0) { start = i; break; }
    }

    // Hierholzer để tìm đường đi Euler
    vector<int> path;
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        bool found = false;
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] > 0) {
                found = true;
                adj[u][v]--;
                adj[v][u]--;
                st.push(v);
                break;
            }
        }
        if (!found) {
            path.push_back(u);
            st.pop();
        }
    }

    cout << 1 << "\n";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i] << (i + 1 == (int)path.size() ? '\n' : ' ');
    }

    return 0;
}
