#include <iostream>
#include <vector>
#include <algorithm> // Dùng cho sort
#include <climits>   // Dùng cho INT_MIN

using namespace std;
using ll = long long;

struct edge {
    int u, v, w;
    int original_index;
};
bool cmp(const edge& a, const edge& b) {
    return a.w < b.w;
}
int parent[1001]; // Giới hạn N <= 1000
int sz[1001];

void make_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (sz[a] < sz[b])
        swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}
ll run_kruskal(int n, vector<edge>& edges, int k_special_idx) {
    int real_cost_of_special_edge = 0;
    for (auto& e : edges) {
        if (e.original_index == k_special_idx) {
            real_cost_of_special_edge = e.w; 
            e.w = INT_MIN; 
            break;
        }
    }

    make_set(n);
    sort(edges.begin(), edges.end(), cmp);

    ll total_weight = 0;
    int edges_added = 0;

    for (auto& e : edges) {
        if (Union(e.u, e.v)) {
            edges_added++;
            
            if (e.original_index == k_special_idx) {
                total_weight += real_cost_of_special_edge;
            } else {
                total_weight += e.w;
            }
        }
    }

    if (edges_added != n - 1) {
        return -1; 
    }
    
    return total_weight;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("COMNET.INP","r",stdin);
    freopen("COMNET.OUT","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N, M, Q;
        cin >> N >> M >> Q;

        vector<edge> original_edges;
        for (int i = 0; i < M; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            original_edges.push_back({u, v, w, i + 1});
        }

        for (int j = 0; j < Q; j++) {
            int k_special_idx;
            int g; 
            cin >> k_special_idx >> g;
            vector<edge> temp_edges = original_edges;
            for (int p = 0; p < g; p++) {
                int t_p, c_p; 
                cin >> t_p >> c_p;
                for (auto& e : temp_edges) {
                    if (e.original_index == t_p) {
                        e.w = c_p;
                        break;
                    }
                }
            }
            
            ll new_mst_cost = run_kruskal(N, temp_edges, k_special_idx);
            cout << new_mst_cost << endl;
        }
    }
    return 0;
}