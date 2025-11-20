#include <iostream>
using namespace std;

const int MAX = 1005;
int n;
int adj[MAX][MAX];  
int inDeg[MAX], outDeg[MAX];
int path[1000000];  
int idx = 0;
void euler(int u) {
    for (int v = 1; v <= n; v++) {
        while (adj[u][v] > 0) {
            adj[u][v]--;
            euler(v);
        }
    }
    path[idx++] = u;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if (adj[i][j]) {
                outDeg[i] += adj[i][j];
                inDeg[j] += adj[i][j];
            }
        }
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] != outDeg[i]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1 << "\n";
    euler(1);
    for (int i = idx - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    return 0;
}
