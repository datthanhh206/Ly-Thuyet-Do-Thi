#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    set<int> s;
    bool is_valid_range = true;
    int element;

    for (int i = 0; i < N; ++i) {
        if (!(cin >> element)) {
            is_valid_range = false; // Lỗi đọc input
            break;
        }

        // Kiểm tra phạm vi (1 tới N)
        if (element < 1 || element > N) {
            is_valid_range = false;
        }

        s.insert(element);
    }
    
    // Kiểm tra: 
    // 1. Tất cả phần tử đều trong [1, N]
    // 2. Kích thước set phải bằng N (tức là không có phần tử nào trùng lặp/thiếu)
    if (is_valid_range && s.size() == (size_t)N) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}