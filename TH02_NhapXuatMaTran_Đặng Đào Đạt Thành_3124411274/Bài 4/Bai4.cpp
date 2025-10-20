#include <fstream>
#include <vector>
using namespace std;

#define FI "DanhSachCanh.inp"
#define FO "DanhSachCanh.out"

struct Edge
{
    int u, v;
    Edge(int vertex1, int vertex2)
    {
        u = vertex1;
        v = vertex2;
    }
};

vector<Edge> edgeList; // danh sách cạnh
int n, m;
vector<int> deg;       // mảng bậc các đỉnh

ifstream fi;
ofstream fo;

void Nhap()
{
    fi.open(FI);
    fi >> n >> m;
    deg.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        fi >> u >> v;
        edgeList.push_back(Edge(u, v));
    }
    fi.close();
}

void XuLy()
{
    // duyệt danh sách cạnh để tính bậc
    for (auto e : edgeList)
    {
        deg[e.u]++;
        deg[e.v]++;
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
