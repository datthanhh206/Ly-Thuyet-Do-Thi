#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Kiểm tra số nguyên tố
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Công thức Legendre: E_p(N!) = Sum(floor(N / p^k))
int count_prime_in_factorial(int N, int p) {
    int count = 0;
    long long power_of_p = p;
    while (power_of_p <= N) {
        count += N / power_of_p;
        // Tránh tràn số khi N / p^k quá lớn
        if (power_of_p > N / p) break; 
        power_of_p *= p;
    }
    return count;
}

int main() {
    int N;
    // Đọc nhiều dòng input N
    while (cin >> N) {
        vector<int> results;
        int last_positive_index = -1;

        // Tìm và đếm số mũ cho các số nguyên tố p <= N
        for (int p = 2; p <= N; ++p) {
            if (is_prime(p)) {
                int count = count_prime_in_factorial(N, p);
                results.push_back(count);
                
                if (count > 0) {
                    last_positive_index = results.size() - 1;
                }
            }
        }
        
        // In ra kết quả chỉ đến phần tử cuối cùng có số mũ > 0
        for (int i = 0; i <= last_positive_index; ++i) {
            cout << results[i] << (i == last_positive_index ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}