#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
ifstream fi;
ofstream fo;
int n;                   // số đỉnh
int a[MAXN][MAXN];       // ma trận kề
int deg[MAXN];           // bậc các đỉnh
void Nhap() {
    fi.open("MaTranKe.inp");
    fi >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fi >> a[i][j];
        }
    }
    fi.close();
}
void TinhBac() {
    for (int i = 0; i < n; i++) {
        deg[i] = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) deg[i] += 2 * a[i][j]; 
            else deg[i] += a[i][j];
        }
    }
}
void Xuat() {
    fo.open("MaTranKe.out");
    fo << n << "\n";
    for (int i = 0; i < n; i++) {
        fo << deg[i] << "\n";
    }
    fo.close();
}
int main() {
    Nhap();
    TinhBac();
    Xuat();
    return 0;
}