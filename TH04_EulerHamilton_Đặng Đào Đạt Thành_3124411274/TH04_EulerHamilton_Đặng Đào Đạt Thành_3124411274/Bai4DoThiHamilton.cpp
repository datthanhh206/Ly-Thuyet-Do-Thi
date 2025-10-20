#include <iostream>
using namespace std;

int n;
int a[105][105];   // ma trận kề
int path[105];     // lưu chu trình
bool visited[105];
bool found = false;

void printPath() {
    for (int i = 0; i <= n; i++) {
        cout << path[i];
        if (i < n) cout << " ";
    }
    cout << endl;
}

void Try(int k) {
    if (found) return; // nếu đã tìm được rồi thì dừng
    for (int v = 2; v <= n; v++) { // thử từ đỉnh 2 trở đi
        if (!visited[v] && a[path[k - 1]][v]) {
            path[k] = v;
            visited[v] = true;
            if (k == n) {
                if (a[path[n]][path[0]]) { // có cạnh quay về đỉnh xuất phát
                    found = true;
                    cout << 1 << endl;
                    printPath();
                }
            }
            else {
                Try(k + 1);
            }
            visited[v] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    path[0] = 1;
    visited[1] = true;
    Try(1);

    if (!found) cout << 0 << endl;
    return 0;
}
