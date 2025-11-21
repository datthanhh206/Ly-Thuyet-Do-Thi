#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void read_array_to_set(set<int>& s, int n) {
    int element;
    for (int i = 0; i < n; ++i) {
        if (cin >> element) {
            s.insert(element);
        }
    }
}

int main() {
    int nx, ny, nz;
    
    // Đọc nx và dãy x
    if (!(cin >> nx)) return 0;
    set<int> sx;
    read_array_to_set(sx, nx);

    // Đọc ny và dãy y
    if (!(cin >> ny)) return 0;
    set<int> sy;
    read_array_to_set(sy, ny);

    // Đọc nz và dãy z
    if (!(cin >> nz)) return 0;
    set<int> sz;
    read_array_to_set(sz, nz);
    
    vector<int> common_elements;

    // Lặp qua tập hợp x (hoặc tập nhỏ nhất) và kiểm tra sự tồn tại trong 2 set còn lại
    for (int val : sx) {
        if (sy.count(val) > 0 && sz.count(val) > 0) {
            common_elements.push_back(val);
        }
    }
    
    // Dòng đầu: số lượng phần tử chung
    cout << common_elements.size() << endl;
    
    // Dòng sau: liệt kê các giá trị chung
    for (size_t i = 0; i < common_elements.size(); ++i) {
        cout << common_elements[i] << (i == common_elements.size() - 1 ? "" : " ");
    }
    cout << endl;
    
    return 0;
}