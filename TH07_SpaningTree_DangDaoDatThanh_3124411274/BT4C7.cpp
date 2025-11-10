#include <iostream>
#include <vector>
#include <climits> // Dùng cho INT_MAX

using namespace std;
using ll = long long;

// Struct để lưu cạnh kề (đỉnh kề, trọng số)
struct Neighbor {
    int v, w;
};

// Struct để lưu cạnh của MST (để in ra kết quả)
struct edge {
    int u, v, w;
};

const int maxn = 1001;
int n, m;

vector<Neighbor> adj[maxn]; // Danh sách kề

// Các mảng dùng cho Prim
int dist[maxn];      // dist[i]: chi phí rẻ nhất nối i vào MST
bool visited[maxn];  // visited[i]: i đã trong MST chưa
int parent[maxn];    // parent[i]: cha của i trong MST

void inp() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

void Prim() {
    // 1. Khởi tạo
    for (int i = 1; i <= n; ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    // Bắt đầu từ đỉnh 1
    dist[1] = 0;

    ll total_weight = 0;
    vector<edge> mst; 

    // 2. Lặp n lần, mỗi lần chọn 1 đỉnh
    for (int i = 0; i < n; ++i) {
        
        // a. Tìm đỉnh 'u' chưa thăm có dist[u] nhỏ nhất
        int u = -1;
        int min_dist = INT_MAX;
        for (int v = 1; v <= n; ++v) {
            if (!visited[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }

        if (u == -1) break; // Đồ thị không liên thông

        // b. Thêm 'u' vào MST
        visited[u] = true;
        total_weight += dist[u]; 

        if (parent[u] != -1) {
            mst.push_back({parent[u], u, dist[u]});
        }

        // c. Cập nhật 'dist' cho các đỉnh kề 'v' của 'u'
        for (auto& neighbor : adj[u]) {
            int v = neighbor.v;
            int w = neighbor.w;
            
            if (!visited[v] && w < dist[v]) {
                dist[v] = w;
                parent[v] = u;
            }
        }
    }
    
    // 3. In kết quả
    if (mst.size() != n - 1) {
         cout << "Đồ thị không liên thông";
    } else {
        cout << mst.size() << " " << total_weight << endl;
        for (auto& e : mst) {
            cout << e.u << " " << e.v << " " << e.w << endl;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("PRIM.INP","r",stdin);
    freopen("PRIM.OUT","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    inp();
    Prim();
    
    return 0;
}