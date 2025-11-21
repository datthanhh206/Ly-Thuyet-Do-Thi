#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

void solve_boba() {
    string text;
    if (!(cin >> text)) return;

    if (text.length() < 3) {
        cout << 0 << endl;
        return;
    }

    map<string, int> tanso;
    
    for (int i = 0; i <= (int)text.length() - 3; ++i) {
        string sub = text.substr(i, 3);
        tanso[sub]++;
    }

    int max_count = 0;
    for (const auto& pair : tanso) {
        if (pair.second > max_count) {
            max_count = pair.second;
        }
    }

    cout << max_count << endl;
}

int main() {
    // T là số lượng tests (1 <= T <= 10)
    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        solve_boba();
    }
    return 0;
}