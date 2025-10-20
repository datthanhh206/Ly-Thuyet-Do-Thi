#include <fstream>
using namespace std;
#define FI "BacVaoBacRa.inp"
#define FO "BacVaoBacRa.out"
ifstream fi; 
ofstream fo;
#define MAXN 1000
int a[MAXN][MAXN]; // Ma trận kề
int n;
int inDeg[MAXN], outDeg[MAXN]; // Bậc vào, bậc ra
void Nhap()
{
    fi.open(FI);
    fi >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fi >> a[i][j];
    fi.close();
}
void XuLy()
{
    for (int i = 0; i < n; i++)
    {
        inDeg[i] = 0;
        outDeg[i] = 0;
    }

    for (int i = 0; i < n; i++) // duyệt từng hàng, từng cột
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                outDeg[i]++; // i có cạnh ra j
                inDeg[j]++;  // j có cạnh vào từ i
            }
        }
    }
}
void Xuat()
{
    fo.open(FO);
    fo << n << "\n";
    for (int i = 0; i < n; i++)
    {
        fo << inDeg[i] << " " << outDeg[i] << "\n";
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