#include <fstream>
#include <vector>
using namespace std;
#define FI "DanhSachKe.inp"
#define FO "DanhSachKe.out"
ifstream fi;
ofstream fo;
int n;
vector<vector<int>> adjList; // Danh sách kề
vector<int> deg;             // Bậc các đỉnh
void Nhap()
{
    fi.open(FI);
    fi >> n;
    adjList.resize(n + 1); // đánh số từ 1 tới n
    deg.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int x;
        while (true)
        {
            fi >> x;
            if (x == -1) break; // kết thúc danh sách kề của đỉnh i
            adjList[i].push_back(x);
        }
    }
    fi.close();
}
void XuLy()
{
    for (int i = 1; i <= n; i++)
    {
        deg[i] = adjList[i].size();
    }
}
void Xuat()
{
    fo.open(FO);
    fo << n << "\n";
    for (int i = 1; i <= n; i++)
    {
        fo << deg[i] << "\n";
    }
    fo.close();
}
int main()
{
    Nhap();
    XuLy();
    Xuat();
    return 0;
}
