#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, cost;
    bool operator>(const Node &o) const { return cost > o.cost; }
};

int main() {
    int N, M, XI, YI, XJ, YJ;
    cin >> N >> M >> XI >> YI >> XJ >> YJ;
    vector<vector<int>> A(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];

    if (A[XI][YI] == 0 || A[XJ][YJ] == 0) {
        cout << 1;
        return 0;
    }

    vector<vector<int>> dist(N + 1, vector<int>(M + 1, 1e9));
    vector<vector<pair<int,int>>> parent(N + 1, vector<pair<int,int>>(M + 1, {-1,-1}));
    int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({XI, YI, 0});
    dist[XI][YI] = 0;

    while (!pq.empty()) {
        auto [x, y, c] = pq.top(); pq.pop();
        if (c > dist[x][y]) continue;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 1 || nx > N || ny < 1 || ny > M || A[nx][ny] == 0) continue;

            int add = (nx == XJ && ny == YJ) ? 0 : A[nx][ny]; // không tính ô cuối
            int nc = c + add;

            if (nc < dist[nx][ny]) {
                dist[nx][ny] = nc;
                parent[nx][ny] = {x, y};
                pq.push({nx, ny, nc});
            }
        }
    }

    if (dist[XJ][YJ] == 1e9) {
        cout << 1;
        return 0;
    }

    cout << 1 << "\n" << dist[XJ][YJ] << "\n";

    vector<pair<int,int>> path;
    for (pair<int,int> p = {XJ,YJ}; p.first != -1; p = parent[p.first][p.second])
        path.push_back(p);
    reverse(path.begin(), path.end());

    for (auto [x,y] : path) cout << x << " " << y << "\n";
}
