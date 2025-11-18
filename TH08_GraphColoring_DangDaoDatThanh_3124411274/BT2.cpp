#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ======== Khai báo đồ thị ========
    map<string, vector<string>> adj;
    adj["CALIFORNIA"] = { "NEVADA", "ARIZONA" };
    adj["NEVADA"] = { "CALIFORNIA", "UTAH", "ARIZONA" };
    adj["UTAH"] = { "NEVADA", "COLORADO", "ARIZONA" };
    adj["COLORADO"] = { "UTAH", "NEBRASKA", "KANSAS", "OKLAHOMA", "ARIZONA" };
    adj["NEBRASKA"] = { "COLORADO", "KANSAS" };
    adj["KANSAS"] = { "NEBRASKA", "COLORADO", "OKLAHOMA" };
    adj["OKLAHOMA"] = { "COLORADO", "KANSAS", "ARKANSAS", "TEXAS" };
    adj["TEXAS"] = { "OKLAHOMA", "ARKANSAS", "LOUISIANA" };
    adj["ARKANSAS"] = { "OKLAHOMA", "TEXAS", "MISSISIPI", "LOUISIANA" };
    adj["LOUISIANA"] = { "TEXAS", "ARKANSAS", "MISSISIPI" };
    adj["MISSISIPI"] = { "ARKANSAS", "LOUISIANA", "GEORGIA", "FLORIDA" };
    adj["GEORGIA"] = { "MISSISIPI", "FLORIDA" };
    adj["FLORIDA"] = { "GEORGIA", "MISSISIPI" };
    adj["ARIZONA"] = { "CALIFORNIA", "NEVADA", "UTAH", "COLORADO" };

    // ======== Lấy danh sách đỉnh ========
    vector<string> nodes;
    for (auto const& [node, neighbors] : adj) {
        nodes.push_back(node);
    }

    // ======== Sắp xếp theo bậc giảm dần (Welsh–Powell) ========
    sort(nodes.begin(), nodes.end(), [&](const string& a, const string& b) {
        return adj.at(a).size() > adj.at(b).size();
    });

    map<string, int> color;
    int maxColor = 0;
    int n = nodes.size();

    // ======== Tô màu ========
    for (const string& node : nodes) {
        vector<bool> used(n + 2, false);
        
        for (const string& neighbor : adj.at(node)) {
            if (color.count(neighbor)) {
                used[color[neighbor]] = true;
            }
        }

        int c = 1;
        while (used[c]) {
            c++;
        }

        color[node] = c;
        maxColor = max(maxColor, c);
    }

    // ======== Xuất kết quả ========
    cout << "So mau su dung: " << maxColor << "\n";

    map<int, vector<string>> colorGroups;
    for (auto const& [node, c] : color) {
        colorGroups[c].push_back(node);
    }

    for (int c = 1; c <= maxColor; c++) {
        cout << "Mau " << c << ": ";
        for (const string& node : colorGroups[c]) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}