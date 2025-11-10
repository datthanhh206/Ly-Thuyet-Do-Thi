#include <bits/stdc++.h>
using namespace std;

using ll=long long;

// Struct để lưu cạnh
struct edge{
    int u,v;
    int w;
};

// Khai báo biến toàn cục
const int maxn=1001;
int n,m;
int parent[maxn], sz[maxn];
vector<edge> canh;

// Khởi tạo DSU (Union-Find)
void make_set(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
}

// Hàm Find (tìm gốc) có nén đường
int find(int v){
    if (v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}

// Hàm Union (gộp 2 nhóm) theo size
bool Union(int a, int b){
    a=find(a);
    b=find(b);
    if(a==b) return false; // Chung gốc, trả về false
    if(sz[a]<sz[b]) swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b]; // Sửa lỗi logic: phải là +=
    return true;
}

// Hàm nhập
void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w; cin>>x>>y>>w;
        // Sửa lỗi cú pháp: dùng {} để khởi tạo
        edge e= {x ,y ,w}; 
        canh.push_back(e);
    }
}

// Hàm so sánh cho sort
bool cmp(edge a, edge b){
    return a.w<b.w;
}

// Hàm thuật toán Kruskal
void Kruskal(){
    vector<edge> mst;
    ll d=0; // Dùng long long cho tổng
    
    // 1. Sắp xếp cạnh
    sort(canh.begin(), canh.end(), cmp);
    
    // 2. Duyệt qua các cạnh
    for(int i=0;i<m;i++){
        if(mst.size()==n-1) break; // Đủ n-1 cạnh thì dừng
        edge e=canh[i];
        if(Union(e.u, e.v)){ // Nếu không tạo chu trình
            mst.push_back(e);
            d+=e.w;
        }
    }
    
    // 3. In kết quả
    if(mst.size()!=n-1){
        cout<<"Đồ thị không liên thông";
    }
    else{
        // In ra theo đúng định dạng đề bài "Bài 3"
        cout<<mst.size()<<" "<<d<<endl;
        for(auto it:mst){
            cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
        }
    }
}

// Hàm main
int main(){
    // Đoạn này để đọc file .INP và .OUT (dùng khi nộp bài)
    #ifndef ONLINE_JUDGE
    freopen("KRUSKAL.INP","r",stdin);
    freopen("KRUSKAL.OUT","w",stdout);
    #endif
    
    // Tăng tốc nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    inp();
    make_set();
    
    // Sửa lỗi gõ phím: Tên hàm là Kruskal (viết hoa K)
    Kruskal(); 

    return 0;
}