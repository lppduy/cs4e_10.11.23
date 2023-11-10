#include <iostream>
using namespace std;

// Hàm tính tổng ước số của một số nguyên dương n
int sum_of_divisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum + n; // Bổ sung n vào tổng vì n cũng là ước của chính nó
}

int main() {
    int T;
    cin >> T; // Nhập số lượng test cases
    while (T--) {
        int n;
        cin >> n; // Nhập số nguyên dương n
        int result = sum_of_divisors(n); // Tính tổng ước của n
        cout << result << endl; // In kết quả
    }
    return 0;
}
