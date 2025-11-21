#include <iostream>

using namespace std;

int main() {
    long long N;
    // Đọc nhiều dòng input N
    while (cin >> N) {
        if (N < 0) { 
            cout << 0 << endl;
            continue;
        }

        int count = 0;
        long long divisor = 5; 

        // Công thức Legendre cho p=5
        while (N / divisor >= 1) {
            count += N / divisor;
            
            // Tránh tràn số cho divisor
            if (divisor > N / 5) break; 
            divisor *= 5; 
        }

        cout << count << endl;
    }
    return 0;
}