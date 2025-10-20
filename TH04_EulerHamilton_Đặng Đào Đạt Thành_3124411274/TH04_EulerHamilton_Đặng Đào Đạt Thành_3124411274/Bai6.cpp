#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m; // số đỉnh, số cạnh
vector<vector<int>> adj; // danh sách kề
vector<int> res;

void euler_iterative(int start) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        if (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();

            // xóa cạnh ngược lại
            for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
                if (*it == u) {
                    adj[v].erase(it);
                    break;
                }
            }

            st.push(v);
        }
        else {
            res.push_back(u);
            st.pop();
        }
    }
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // đồ thị vô hướng
    }

    euler_iterative(1); // bắt đầu từ đỉnh 1

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
