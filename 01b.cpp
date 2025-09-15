#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("MaTranKe.inp"); // file chứa dữ liệu đồ thị
    ofstream fout("MaTranKe.out");
    if (!fin) {
        fout << "Khong mo duoc file!" << endl;
        return 0;
    }

    int n;
    fin >> n;
    fout << "So dinh cua do thi: " << n << endl;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(fin >> a[i][j])) {
                fout << "Thong tin do thi khong hop le (thieu du lieu)." << endl;
                return 0;
            }
            if (a[i][j] != 0 && a[i][j] != 1) {
                fout << "Thong tin do thi khong hop le (chi duoc chua 0 hoac 1)." << endl;
                return 0;
            }
        }
    }

    // in ma trận
    fout << "Ma tran ke cua do thi:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fout << a[i][j] << " ";
        }
        fout << endl;
    }

    // kiểm tra đối xứng
    bool symmetric = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                symmetric = false;
                break;
            }
        }
        if (!symmetric) break;
    }

    if (symmetric)
        fout << "Do thi la VO HUONG" << endl;
    else
        fout << "Do thi la CO HUONG" << endl;

    return 0;
}
